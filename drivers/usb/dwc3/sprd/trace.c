// SPDX-License-Identifier: GPL-2.0
/*
 * trace.c - DesignWare USB3 DRD Controller Trace Support
 *
 * Copyright (C) 2014 Texas Instruments Incorporated - https://www.ti.com
 *
 * Author: Felipe Balbi <balbi@ti.com>
 */

#define CREATE_TRACE_POINTS
#include "trace.h"

EXPORT_TRACEPOINT_SYMBOL_GPL(dwc3_sprd_event);
EXPORT_TRACEPOINT_SYMBOL_GPL(dwc3_sprd_ctrl_req);
EXPORT_TRACEPOINT_SYMBOL_GPL(dwc3_sprd_complete_trb);
