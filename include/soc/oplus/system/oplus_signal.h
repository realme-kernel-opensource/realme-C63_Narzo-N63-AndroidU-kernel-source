/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (C) 2018-2020 Oplus. All rights reserved.
 */
#ifndef __OPLUS_SIGNAL_H
#define __OPLUS_SIGNAL_H

#include <linux/signal.h>
#include <linux/sched.h>

/* signal pending, fatal_signal_pending from signal.h*/
#define PF_KILLING	0x00000001
/*
 * wait.h cannot include linux/shed/signal.h , so workaround as hung_long_and_fatal_signal_pending
 * return fatal_signal_pending(p) && (p->flags & PF_KILLING)
 */
static inline int hung_long_and_fatal_signal_pending(struct task_struct *p)
{
//odm alm_id:5321993 struk to reboot function ; build-in  for gki 2023/3/17 wangshuaishuai start
	return (unlikely(test_tsk_thread_flag(p,TIF_SIGPENDING)))
		&& (unlikely(sigismember(&p->pending.signal, SIGKILL)))
		&& (p->flags & PF_KILLING);
//	return 0;
//odm alm_id:5321993 struk to reboot function ; build-in  for gki 2023/3/17 wangshuaishuai end
}

#endif