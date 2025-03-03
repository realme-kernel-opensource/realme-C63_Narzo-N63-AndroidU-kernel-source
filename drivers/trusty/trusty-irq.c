// SPDX-License-Identifier: GPL-2.0-only
/*
 * trusty-irq.c - Unisoc platform driver
 *
 * Copyright 2022 Unisoc(Shanghai) Technologies Co.Ltd
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#include <linux/cpu.h>
#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/irqdomain.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/of_irq.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/string.h>
#include <linux/trusty/smcall.h>
#include "sm_err.h"
#include "trusty.h"

#ifdef pr_fmt
#undef pr_fmt
#endif
#define pr_fmt(fmt) "sprd-trusty-irq: " fmt

struct trusty_irq {
	struct trusty_irq_state *is;
	struct hlist_node node;
	unsigned int irq;
	bool percpu;
	bool enable;
	struct trusty_irq __percpu *percpu_ptr;
};

struct trusty_irq_irqset {
	struct hlist_head pending;
	struct hlist_head inactive;
};

struct trusty_irq_state {
	struct device *dev;
	struct device *trusty_dev;
	struct trusty_irq_irqset normal_irqs;
	spinlock_t normal_irqs_lock;
	struct trusty_irq_irqset __percpu *percpu_irqs;
	struct notifier_block trusty_call_notifier;
	struct hlist_node cpuhp_node;
	unsigned int gic_version;
};

static int trusty_irq_cpuhp_slot = -1;

#define SPRD_GIC_DEFAULT	2
#define SPRD_GIC_V3	3

#define IPI_TRUSTY_SMC	13

static void trusty_irq_enable_pending_irqs(struct trusty_irq_state *is,
					   struct trusty_irq_irqset *irqset,
					   bool percpu)
{
	struct hlist_node *n;
	struct trusty_irq *trusty_irq;

	hlist_for_each_entry_safe(trusty_irq, n, &irqset->pending, node) {
		dev_dbg(is->dev,
			"%s: enable pending irq %d, percpu %d, cpu %d\n",
			__func__, trusty_irq->irq, percpu, smp_processor_id());
		if (percpu)
			enable_percpu_irq(trusty_irq->irq, 0);
		else
			enable_irq(trusty_irq->irq);
		hlist_del(&trusty_irq->node);
		hlist_add_head(&trusty_irq->node, &irqset->inactive);
	}
}

static void trusty_irq_enable_irqset(struct trusty_irq_state *is,
				      struct trusty_irq_irqset *irqset)
{
	struct trusty_irq *trusty_irq;

	hlist_for_each_entry(trusty_irq, &irqset->inactive, node) {
		if (trusty_irq->enable) {
			dev_warn(is->dev,
				 "%s: percpu irq %d already enabled, cpu %d\n",
				 __func__, trusty_irq->irq, smp_processor_id());
			continue;
		}
		dev_dbg(is->dev, "%s: enable percpu irq %d, cpu %d\n",
			__func__, trusty_irq->irq, smp_processor_id());
		enable_percpu_irq(trusty_irq->irq, 0);
		trusty_irq->enable = true;
	}
}

static void trusty_irq_disable_irqset(struct trusty_irq_state *is,
				      struct trusty_irq_irqset *irqset)
{
	struct hlist_node *n;
	struct trusty_irq *trusty_irq;

	hlist_for_each_entry(trusty_irq, &irqset->inactive, node) {
		if (!trusty_irq->enable) {
			dev_warn(is->dev,
				 "irq %d already disabled, percpu %d, cpu %d\n",
				 trusty_irq->irq, trusty_irq->percpu,
				 smp_processor_id());
			continue;
		}
		dev_dbg(is->dev, "%s: disable irq %d, percpu %d, cpu %d\n",
			__func__, trusty_irq->irq, trusty_irq->percpu,
			smp_processor_id());
		trusty_irq->enable = false;
		if (trusty_irq->percpu)
			disable_percpu_irq(trusty_irq->irq);
		else
			disable_irq_nosync(trusty_irq->irq);
	}
	hlist_for_each_entry_safe(trusty_irq, n, &irqset->pending, node) {
		if (!trusty_irq->enable) {
			dev_warn(is->dev,
				 "pending irq %d already disabled, percpu %d, cpu %d\n",
				 trusty_irq->irq, trusty_irq->percpu,
				 smp_processor_id());
		}
		dev_dbg(is->dev,
			"%s: disable pending irq %d, percpu %d, cpu %d\n",
			__func__, trusty_irq->irq, trusty_irq->percpu,
			smp_processor_id());
		trusty_irq->enable = false;
		hlist_del(&trusty_irq->node);
		hlist_add_head(&trusty_irq->node, &irqset->inactive);
	}
}

static int trusty_irq_call_notify(struct notifier_block *nb,
				  unsigned long action, void *data)
{
	struct trusty_irq_state *is;

	BUG_ON(!irqs_disabled());

	if (action != TRUSTY_CALL_PREPARE)
		return NOTIFY_DONE;

	is = container_of(nb, struct trusty_irq_state, trusty_call_notifier);

	spin_lock(&is->normal_irqs_lock);
	trusty_irq_enable_pending_irqs(is, &is->normal_irqs, false);
	spin_unlock(&is->normal_irqs_lock);
	trusty_irq_enable_pending_irqs(is, this_cpu_ptr(is->percpu_irqs), true);

	return NOTIFY_OK;
}

static irqreturn_t trusty_irq_handler(int irq, void *data)
{
	struct trusty_irq *trusty_irq = data;
	struct trusty_irq_state *is = trusty_irq->is;
	struct irq_data *irq_data = irq_get_irq_data(irq);
	struct trusty_irq_irqset *irqset;

	dev_dbg(is->dev, "%s: irq %d, percpu %d, cpu %d, enable %d\n",
		__func__, irq, trusty_irq->irq, smp_processor_id(),
		trusty_irq->enable);

	switch (is->gic_version) {
	case SPRD_GIC_V3:
		switch (irq_data->hwirq) {
		case IPI_TRUSTY_SMC:
			dev_dbg(is->dev, "receiving irq IPI_TRUSTY_SMC, will send a smc nop ......\n");
			trusty_enqueue_nop(is->trusty_dev, NULL);
			break;

		default:
			dev_err(is->dev, "unexcepted irq: %ld\n",
				irq_data->hwirq);
			return IRQ_NONE;
		}
		break;

	case SPRD_GIC_DEFAULT:
		if (trusty_irq->percpu) {
			disable_percpu_irq(irq);
			irqset = this_cpu_ptr(is->percpu_irqs);
		} else {
			disable_irq_nosync(irq);
			irqset = &is->normal_irqs;
		}

	spin_lock(&is->normal_irqs_lock);
	if (trusty_irq->enable) {
		hlist_del(&trusty_irq->node);
		hlist_add_head(&trusty_irq->node, &irqset->pending);
	}
	spin_unlock(&is->normal_irqs_lock);
	trusty_enqueue_nop(is->trusty_dev, NULL);
	break;

	default:
		dev_err(is->dev, "unexcepted gic version: %d\n",
			is->gic_version);
		return IRQ_NONE;
	}

	dev_dbg(is->dev, "%s: irq %d done\n", __func__, irq);

	return IRQ_HANDLED;
}

static int trusty_irq_cpu_up(unsigned int cpu, struct hlist_node *node)
{
	unsigned long irq_flags;
	struct trusty_irq_state *is;

	is = container_of(node, struct trusty_irq_state, cpuhp_node);

	dev_dbg(is->dev, "%s: cpu %d\n", __func__, cpu);

	local_irq_save(irq_flags);
	trusty_irq_enable_irqset(is, this_cpu_ptr(is->percpu_irqs));
	local_irq_restore(irq_flags);

	return 0;
}

static int trusty_irq_cpu_down(unsigned int cpu, struct hlist_node *node)
{
	unsigned long irq_flags;
	struct trusty_irq_state *is;

	is = container_of(node, struct trusty_irq_state, cpuhp_node);

	dev_dbg(is->dev, "%s: cpu %d\n", __func__, cpu);

	local_irq_save(irq_flags);
	trusty_irq_disable_irqset(is, this_cpu_ptr(is->percpu_irqs));
	local_irq_restore(irq_flags);

	return 0;
}

static int trusty_irq_create_irq_mapping(struct trusty_irq_state *is, int irq)
{
	int ret;
	int index;
	u32 irq_pos;
	u32 templ_idx;
	u32 range_base;
	u32 range_end;
	struct of_phandle_args oirq;

	/* check if "interrupt-ranges" property is present */
	if (!of_find_property(is->dev->of_node, "interrupt-ranges", NULL)) {
		/* fallback to old behavior to be backward compatible with
		 * systems that do not need IRQ domains.
		 */
		return irq;
	}

	/* find irq range */
	for (index = 0;; index += 3) {
		ret = of_property_read_u32_index(is->dev->of_node,
						 "interrupt-ranges",
						 index, &range_base);
		if (ret)
			return ret;

		ret = of_property_read_u32_index(is->dev->of_node,
						 "interrupt-ranges",
						 index + 1, &range_end);
		if (ret)
			return ret;

		if (irq >= range_base && irq <= range_end)
			break;
	}

	/*  read the rest of range entry: template index and irq_pos */
	ret = of_property_read_u32_index(is->dev->of_node,
					 "interrupt-ranges",
					 index + 2, &templ_idx);
	if (ret)
		return ret;

	/* read irq template */
	ret = of_parse_phandle_with_args(is->dev->of_node,
					 "interrupt-templates",
					 "#interrupt-cells",
					 templ_idx, &oirq);
	if (ret)
		return ret;

	WARN_ON(!oirq.np);
	WARN_ON(!oirq.args_count);

	/*
	 * An IRQ template is a non empty array of u32 values describing group
	 * of interrupts having common properties. The u32 entry with index
	 * zero contains the position of irq_id in interrupt specifier array
	 * followed by data representing interrupt specifier array with irq id
	 * field omitted, so to convert irq template to interrupt specifier
	 * array we have to move down one slot the first irq_pos entries and
	 * replace the resulting gap with real irq id.
	 *
	 * After replace ipi to sgi for k54, the #interrupt-cells of sgi and
	 * ppi and psi must be equal 3. However, there is only one args in sgi.
	 * So modify args_count and args[0] for sgi mapping
	 */

	if (templ_idx == 0) {
		oirq.args[0] = 0;
		oirq.args_count = 1;
	}

	irq_pos = oirq.args[0];

	if (irq_pos >= oirq.args_count) {
		dev_err(is->dev, "irq pos is out of range: %d\n", irq_pos);
		return -EINVAL;
	}

	for (index = 1; index <= irq_pos; index++)
		oirq.args[index - 1] = oirq.args[index];

	oirq.args[irq_pos] = irq - range_base;

	ret = irq_create_of_mapping(&oirq);

	return (!ret) ? -EINVAL : ret;
}

static int trusty_irq_init_normal_irq(struct trusty_irq_state *is, int tirq)
{
	int ret;
	int irq;
	unsigned long irq_flags;
	struct trusty_irq *trusty_irq;

	dev_dbg(is->dev, "%s: irq %d\n", __func__, tirq);

	irq = trusty_irq_create_irq_mapping(is, tirq);
	if (irq < 0) {
		dev_err(is->dev,
			"trusty_irq_create_irq_mapping failed (%d)\n", irq);
		return irq;
	}

	trusty_irq = kzalloc(sizeof(*trusty_irq), GFP_KERNEL);
	if (!trusty_irq)
		return -ENOMEM;

	trusty_irq->is = is;
	trusty_irq->irq = irq;
	trusty_irq->enable = true;

	spin_lock_irqsave(&is->normal_irqs_lock, irq_flags);
	hlist_add_head(&trusty_irq->node, &is->normal_irqs.inactive);
	spin_unlock_irqrestore(&is->normal_irqs_lock, irq_flags);

	ret = request_irq(irq, trusty_irq_handler, IRQF_NO_THREAD,
			  "trusty", trusty_irq);
	if (ret) {
		dev_err(is->dev, "request_irq failed %d\n", ret);
		goto err_request_irq;
	}
	return 0;

err_request_irq:
	spin_lock_irqsave(&is->normal_irqs_lock, irq_flags);
	hlist_del(&trusty_irq->node);
	spin_unlock_irqrestore(&is->normal_irqs_lock, irq_flags);
	kfree(trusty_irq);
	return ret;
}

static int trusty_irq_init_per_cpu_irq(struct trusty_irq_state *is, int tirq)
{
	int ret;
	int irq;
	unsigned int cpu;
	struct trusty_irq __percpu *trusty_irq_handler_data;

	dev_dbg(is->dev, "%s: irq %d\n", __func__, tirq);

	irq = trusty_irq_create_irq_mapping(is, tirq);
	if (irq <= 0) {
		dev_err(is->dev,
			"trusty_irq_create_irq_mapping failed (%d)\n", irq);
		return irq;
	}

	trusty_irq_handler_data = alloc_percpu(struct trusty_irq);
	if (!trusty_irq_handler_data)
		return -ENOMEM;

	for_each_possible_cpu(cpu) {
		struct trusty_irq *trusty_irq;
		struct trusty_irq_irqset *irqset;

		trusty_irq = per_cpu_ptr(trusty_irq_handler_data, cpu);
		irqset = per_cpu_ptr(is->percpu_irqs, cpu);

		trusty_irq->is = is;
		hlist_add_head(&trusty_irq->node, &irqset->inactive);
		trusty_irq->irq = irq;
		trusty_irq->percpu = true;
		trusty_irq->percpu_ptr = trusty_irq_handler_data;
	}

	ret = request_percpu_irq(irq, trusty_irq_handler, "trusty",
				 trusty_irq_handler_data);
	if (ret) {
		dev_err(is->dev, "request_percpu_irq failed %d\n", ret);
		goto err_request_percpu_irq;
	}

	return 0;

err_request_percpu_irq:
	for_each_possible_cpu(cpu) {
		struct trusty_irq *trusty_irq;

		trusty_irq = per_cpu_ptr(trusty_irq_handler_data, cpu);
		hlist_del(&trusty_irq->node);
	}

	free_percpu(trusty_irq_handler_data);
	return ret;
}

static int trusty_smc_get_next_irq(struct trusty_irq_state *is,
				   unsigned long min_irq, bool per_cpu)
{
	return trusty_fast_call32(is->trusty_dev, SMC_FC_GET_NEXT_IRQ,
				  min_irq, per_cpu, 0);
}

static int trusty_irq_init_one(struct trusty_irq_state *is,
			       int irq, bool per_cpu)
{
	int ret;

	irq = trusty_smc_get_next_irq(is, irq, per_cpu);
	if (irq < 0)
		return irq;

	if (per_cpu)
		ret = trusty_irq_init_per_cpu_irq(is, irq);
	else
		ret = trusty_irq_init_normal_irq(is, irq);

	if (ret) {
		dev_warn(is->dev,
			 "failed to initialize irq %d, irq will be ignored\n",
			 irq);
	}

	return irq + 1;
}

static void trusty_irq_free_irqs(struct trusty_irq_state *is)
{
	struct trusty_irq *irq;
	struct hlist_node *n;
	unsigned int cpu;

	hlist_for_each_entry_safe(irq, n, &is->normal_irqs.inactive, node) {
		dev_dbg(is->dev, "%s: irq %d\n", __func__, irq->irq);
		free_irq(irq->irq, irq);
		hlist_del(&irq->node);
		kfree(irq);
	}
	hlist_for_each_entry_safe(irq, n,
				  &this_cpu_ptr(is->percpu_irqs)->inactive,
				  node) {
		struct trusty_irq __percpu *trusty_irq_handler_data;

		dev_dbg(is->dev, "%s: percpu irq %d\n", __func__, irq->irq);
		trusty_irq_handler_data = irq->percpu_ptr;
		free_percpu_irq(irq->irq, trusty_irq_handler_data);
		for_each_possible_cpu(cpu) {
			struct trusty_irq *irq_tmp;

			irq_tmp = per_cpu_ptr(trusty_irq_handler_data, cpu);
			hlist_del(&irq_tmp->node);
		}
		free_percpu(trusty_irq_handler_data);
	}
}

static int trusty_irq_probe(struct platform_device *pdev)
{
	int ret;
	int irq;
	unsigned long irq_flags;
	struct trusty_irq_state *is;

	dev_dbg(&pdev->dev, "%s\n", __func__);

	is = kzalloc(sizeof(*is), GFP_KERNEL);
	if (!is) {
		ret = -ENOMEM;
		goto err_alloc_is;
	}

	is->dev = &pdev->dev;
	is->trusty_dev = is->dev->parent;
	spin_lock_init(&is->normal_irqs_lock);
	if (of_find_compatible_node(NULL, NULL, "arm,gic-v3"))
		is->gic_version = SPRD_GIC_V3;
	else {
		is->gic_version = SPRD_GIC_DEFAULT;
		dev_dbg(&pdev->dev, "gic_version is default gic_v2\n");
	}


	dev_dbg(&pdev->dev, "%s gic version = %d\n", __func__, is->gic_version);

	is->percpu_irqs = alloc_percpu(struct trusty_irq_irqset);
	if (!is->percpu_irqs) {
		ret = -ENOMEM;
		goto err_alloc_pending_percpu_irqs;
	}

	platform_set_drvdata(pdev, is);

	is->trusty_call_notifier.notifier_call = trusty_irq_call_notify;
	ret = trusty_call_notifier_register(is->trusty_dev,
					    &is->trusty_call_notifier);
	if (ret) {
		dev_err(&pdev->dev,
			"failed to register trusty call notifier\n");
		goto err_trusty_call_notifier_register;
	}

	if (is->gic_version == SPRD_GIC_V3) {
		ret = trusty_irq_init_per_cpu_irq(is, IPI_TRUSTY_SMC);
		if (ret) {
			dev_warn(is->dev,
				 "failed to initialize irq %d, irq will be ignored\n",
				 IPI_TRUSTY_SMC);
		}
	}

	for (irq = 0; irq >= 0;)
		irq = trusty_irq_init_one(is, irq, true);
	for (irq = 0; irq >= 0;)
		irq = trusty_irq_init_one(is, irq, false);

	ret = cpuhp_state_add_instance(trusty_irq_cpuhp_slot, &is->cpuhp_node);
	if (ret < 0) {
		dev_err(&pdev->dev, "cpuhp_state_add_instance failed %d\n",
			ret);
		goto err_add_cpuhp_instance;
	}

	return 0;

err_add_cpuhp_instance:
	spin_lock_irqsave(&is->normal_irqs_lock, irq_flags);
	trusty_irq_disable_irqset(is, &is->normal_irqs);
	spin_unlock_irqrestore(&is->normal_irqs_lock, irq_flags);
	trusty_irq_free_irqs(is);
	trusty_call_notifier_unregister(is->trusty_dev,
					&is->trusty_call_notifier);
err_trusty_call_notifier_register:
	free_percpu(is->percpu_irqs);
err_alloc_pending_percpu_irqs:
	kfree(is);
err_alloc_is:
	return ret;
}

static int trusty_irq_remove(struct platform_device *pdev)
{
	int ret;
	unsigned long irq_flags;
	struct trusty_irq_state *is = platform_get_drvdata(pdev);

	dev_dbg(&pdev->dev, "%s\n", __func__);

	ret = cpuhp_state_remove_instance(trusty_irq_cpuhp_slot,
					  &is->cpuhp_node);
	if (WARN_ON(ret))
		return ret;

	spin_lock_irqsave(&is->normal_irqs_lock, irq_flags);
	trusty_irq_disable_irqset(is, &is->normal_irqs);
	spin_unlock_irqrestore(&is->normal_irqs_lock, irq_flags);

	trusty_irq_free_irqs(is);

	trusty_call_notifier_unregister(is->trusty_dev,
					&is->trusty_call_notifier);
	free_percpu(is->percpu_irqs);
	kfree(is);

	return 0;
}

static const struct of_device_id trusty_test_of_match[] = {
	{ .compatible = "sprd,trusty-irq-v1", },
	{},
};

static struct platform_driver trusty_irq_driver = {
	.probe = trusty_irq_probe,
	.remove = trusty_irq_remove,
	.driver	= {
		.name = "sprd-trusty-irq",
		.of_match_table = trusty_test_of_match,
	},
};

static int __init trusty_irq_driver_init(void)
{
	int ret;

	/* allocate dynamic cpuhp state slot */
	ret = cpuhp_setup_state_multi(CPUHP_AP_ONLINE_DYN,
				      "trusty-irq:cpu:online",
				      trusty_irq_cpu_up,
				      trusty_irq_cpu_down);
	if (ret < 0)
		return ret;
	trusty_irq_cpuhp_slot = ret;

	/* Register platform driver */
	ret = platform_driver_register(&trusty_irq_driver);
	if (ret < 0)
		goto err_driver_register;

	return ret;

err_driver_register:
	/* undo cpuhp slot allocation */
	cpuhp_remove_multi_state(trusty_irq_cpuhp_slot);
	trusty_irq_cpuhp_slot = -1;

	return ret;
}

static void __exit trusty_irq_driver_exit(void)
{
	platform_driver_unregister(&trusty_irq_driver);
	cpuhp_remove_multi_state(trusty_irq_cpuhp_slot);
	trusty_irq_cpuhp_slot = -1;
}

module_init(trusty_irq_driver_init);
module_exit(trusty_irq_driver_exit);

MODULE_DESCRIPTION("Sprd trusty irq driver");
MODULE_LICENSE("GPL v2");
