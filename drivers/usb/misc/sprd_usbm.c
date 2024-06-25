/**
 * sprd_usbm.c - spreadtrum multiple USB management for controllers switch
 *
 * Copyright (c) 2021 Spreadtrum Co., Ltd.
 *		http://www.spreadtrum.com
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2  of
 * the License as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/err.h>
#include <linux/types.h>
#include <linux/slab.h>
#include <linux/io.h>
#include <linux/usb.h>
#include <linux/usb/hcd.h>
#include <linux/notifier.h>
#include <linux/usb/sprd_usbm.h>
#include <trace/hooks/usb.h>

struct sprd_usbm_event {
	int max_supported;
	struct mutex	serialize;
	struct raw_notifier_head nh[SPRD_USBM_EVENT_MAX];
};

static struct sprd_usbm_event *usb_event_sprd;
static atomic_t		musb_active;
/* phy status, 0 for off, 1 for on */
static atomic_t		hsphy_onoff;
static atomic_t		ssphy_onoff;

/* define our own notifier_call_chain */
int call_sprd_usbm_event_notifiers(unsigned int id, unsigned long val, void *v)
{
	struct sprd_usbm_event *usb_event = usb_event_sprd;
	int ret = 0;

	if (!usb_event || id >= SPRD_USBM_EVENT_MAX)
		return -EINVAL;

	pr_info("[%s]id(%d),val(%ld)\n", __func__, id, val);
	if ((id == SPRD_USBM_EVENT_HOST_MUSB) && val)
		atomic_set(&musb_active, 1);

	ret = raw_notifier_call_chain(&usb_event->nh[id], val, v);

	if ((id == SPRD_USBM_EVENT_HOST_MUSB) && !val)
		atomic_set(&musb_active, 0);

	return ret;
}
EXPORT_SYMBOL(call_sprd_usbm_event_notifiers);

/* get the musb status */
int sprd_usbm_event_is_active(void)
{
	return atomic_read(&musb_active);
}
EXPORT_SYMBOL(sprd_usbm_event_is_active);

/* set the musb deactive */
void sprd_usbm_event_set_deactive(void)
{
	atomic_set(&musb_active, 0);
}
EXPORT_SYMBOL(sprd_usbm_event_set_deactive);

/* get hsphy status */
int sprd_usbm_hsphy_get_onoff(void)
{
	return atomic_read(&hsphy_onoff);
}
EXPORT_SYMBOL(sprd_usbm_hsphy_get_onoff);

/* set hsphy status */
void sprd_usbm_hsphy_set_onoff(int onoff)
{
	atomic_set(&hsphy_onoff, onoff);
}
EXPORT_SYMBOL(sprd_usbm_hsphy_set_onoff);

/* get ssphy status */
int sprd_usbm_ssphy_get_onoff(void)
{
	return atomic_read(&ssphy_onoff);
}
EXPORT_SYMBOL(sprd_usbm_ssphy_get_onoff);

/* set ssphy status */
void sprd_usbm_ssphy_set_onoff(int onoff)
{
	atomic_set(&ssphy_onoff, onoff);
}
EXPORT_SYMBOL(sprd_usbm_ssphy_set_onoff);

/* set mutex lock */
void sprd_usbm_mutex_lock(void)
{
	struct sprd_usbm_event *usb_event = usb_event_sprd;

	if (!usb_event) {
		pr_info("usb_event is null when do mutex lock\n");
		return;
	}

	mutex_lock(&usb_event->serialize);
}
EXPORT_SYMBOL(sprd_usbm_mutex_lock);

/* set mutex unlock */
void sprd_usbm_mutex_unlock(void)
{
	struct sprd_usbm_event *usb_event = usb_event_sprd;

	if (!usb_event) {
		pr_info("usb_event is null when do mutex unlock\n");
		return;
	}

	mutex_unlock(&usb_event->serialize);
}
EXPORT_SYMBOL(sprd_usbm_mutex_unlock);

/* define our own notifier_chain_register func */
int register_sprd_usbm_notifier(struct notifier_block *nb, unsigned int id)
{
	struct sprd_usbm_event *usb_event = usb_event_sprd;

	if (!usb_event || !nb || id >= SPRD_USBM_EVENT_MAX)
		return -EINVAL;

	return raw_notifier_chain_register(&usb_event->nh[id], nb);
}
EXPORT_SYMBOL(register_sprd_usbm_notifier);

static void usb_new_device_added(void *data, struct usb_device *udev, int *ret)
{
	struct usb_interface_descriptor *intf_desc;
	struct usb_config_descriptor	*config_desc;
	const char		*driver_name;
	int i;
	bool audio_flag = false;

	*ret = 0;

	intf_desc = &udev->config->intf_cache[0]->altsetting[0].desc;
	config_desc = &udev->config->desc;

	if (udev->bus->controller->driver)
		driver_name = udev->bus->controller->driver->name;
	else
		driver_name = udev->bus->sysdev->driver->name;

	/* There may be couple of intf_cache due to config, loopup all
	 * of the intf for usb audio
	 */
	for (i = 0; i < config_desc->bNumInterfaces; i++) {
		intf_desc = &udev->config->intf_cache[i]->altsetting[0].desc;
		if (intf_desc->bInterfaceClass == USB_CLASS_AUDIO) {
			audio_flag = true;
			break;
		}
	}

	dev_dbg(&udev->dev,
		"config_desc: bNumInterfaces=%d, intf_desc: bInterfaceNumber=%d bInterfaceClass=%d \
		bInterfaceSubClass=%d bInterfaceProtocol=%d\n",
		config_desc->bNumInterfaces,
		intf_desc->bInterfaceNumber,
		intf_desc->bInterfaceClass,
		intf_desc->bInterfaceSubClass,
		intf_desc->bInterfaceProtocol);

	/* If the usb device is an audio device, and current usb controller is
	 * not "musb-hdrc", need to switch to musb
	 */
	if (audio_flag && !strncmp(driver_name, "xhci-hcd", 8)) {
		dev_info(&udev->dev, "Do usb3 -> usb2 switch for usb audio \n");
		call_sprd_usbm_event_notifiers(SPRD_USBM_EVENT_HOST_DWC3, false, NULL);
		*ret = 1;
	}
}

static int __init sprd_usbm_event_driver_init(void)
{
	int index;
	struct sprd_usbm_event *usb_event;

	atomic_set(&musb_active, 0);
	atomic_set(&hsphy_onoff, 0);
	atomic_set(&ssphy_onoff, 0);

	usb_event = kzalloc(sizeof(*usb_event), GFP_KERNEL);
	if (!usb_event)
		return -ENOMEM;

	usb_event->max_supported = SPRD_USBM_EVENT_MAX;

	mutex_init(&usb_event->serialize);

	for (index = 0; index < usb_event->max_supported; index++)
		RAW_INIT_NOTIFIER_HEAD(&usb_event->nh[index]);
	usb_event_sprd = usb_event;

	register_trace_android_vh_usb_new_device_added(usb_new_device_added, NULL);
	return 0;
}

static void __exit sprd_usbm_event_driver_exit(void)
{
	struct sprd_usbm_event *usb_event = usb_event_sprd;

	kfree(usb_event);
	usb_event_sprd = NULL;
}

subsys_initcall(sprd_usbm_event_driver_init);
module_exit(sprd_usbm_event_driver_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("DesignWare SPRD USBM");
