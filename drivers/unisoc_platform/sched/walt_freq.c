// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (c) 2022, Unisoc (shanghai) Technologies Co., Ltd
 */

#include "uni_sched.h"

DEFINE_PER_CPU(struct walt_update_util_data __rcu *, walt_cpufreq_update_util_data);

/**
 * cpufreq_add_update_util_hook - Populate the CPU's update_util_data pointer.
 * @cpu: The CPU to set the pointer for.
 * @data: New pointer value.
 * @func: Callback function to set for the CPU.
 *
 * Set and publish the update_util_data pointer for the given CPU.
 *
 * The update_util_data pointer of @cpu is set to @data and the callback
 * function pointer in the target struct update_util_data is set to @func.
 * That function will be called by cpufreq_update_util() from RCU-sched
 * read-side critical sections, so it must not sleep.  @data will always be
 * passed to it as the first argument which allows the function to get to the
 * target update_util_data structure and its container.
 *
 * The update_util_data pointer of @cpu must be NULL when this function is
 * called or it will WARN() and return with no effect.
 */
void walt_cpufreq_add_update_util_hook(int cpu, struct walt_update_util_data *data,
			void (*func)(struct walt_update_util_data *data, u64 time,
				     unsigned int flags))
{
	if (WARN_ON(!data || !func))
		return;

	if (WARN_ON(per_cpu(walt_cpufreq_update_util_data, cpu)))
		return;

	data->func = func;
	rcu_assign_pointer(per_cpu(walt_cpufreq_update_util_data, cpu), data);
}
EXPORT_SYMBOL_GPL(walt_cpufreq_add_update_util_hook);

/**
 * cpufreq_remove_update_util_hook - Clear the CPU's update_util_data pointer.
 * @cpu: The CPU to clear the pointer for.
 *
 * Clear the update_util_data pointer for the given CPU.
 *
 * Callers must use RCU callbacks to free any memory that might be
 * accessed via the old update_util_data pointer or invoke synchronize_rcu()
 * right after this function to avoid use-after-free.
 */
void walt_cpufreq_remove_update_util_hook(int cpu)
{
	rcu_assign_pointer(per_cpu(walt_cpufreq_update_util_data, cpu), NULL);
}
EXPORT_SYMBOL_GPL(walt_cpufreq_remove_update_util_hook);

/**
 * cpufreq_this_cpu_can_update - Check if cpufreq policy can be updated.
 * @policy: cpufreq policy to check.
 *
 * Return 'true' if:
 * - the local and remote CPUs share @policy,
 * - dvfs_possible_from_any_cpu is set in @policy and the local CPU is not going
 *   offline (in which case it is not expected to run cpufreq updates any more).
 */
bool walt_cpufreq_this_cpu_can_update(struct cpufreq_policy *policy)
{
	return cpumask_test_cpu(smp_processor_id(), policy->cpus) ||
		(policy->dvfs_possible_from_any_cpu &&
		 rcu_dereference_sched(*this_cpu_ptr(&walt_cpufreq_update_util_data)));
}
EXPORT_SYMBOL_GPL(walt_cpufreq_this_cpu_can_update);
