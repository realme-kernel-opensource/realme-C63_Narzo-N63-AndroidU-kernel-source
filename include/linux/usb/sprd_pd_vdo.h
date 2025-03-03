// SPDX-License-Identifier: GPL-2.0-only
/*
 * sprd_pd_vdo.h - Unisoc platform header
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

#ifndef __LINUX_USB_SPRD_PD_VDO_H
#define __LINUX_USB_SPRD_PD_VDO_H

#include "sprd_pd.h"

/*
 * VDO : Vendor Defined Message Object
 * VDM object is minimum of VDM header + 6 additional data objects.
 */

#define SPRD_VDO_MAX_OBJECTS		6
#define SPRD_VDO_MAX_SIZE		(SPRD_VDO_MAX_OBJECTS + 1)

/*
 * VDM header
 * ----------
 * <31:16>  :: SVID
 * <15>     :: VDM type ( 1b == structured, 0b == unstructured )
 * <14:13>  :: Structured VDM version (can only be 00 == 1.0 currently)
 * <12:11>  :: reserved
 * <10:8>   :: object position (1-7 valid ... used for enter/exit mode only)
 * <7:6>    :: command type (SVDM only?)
 * <5>      :: reserved (SVDM), command type (UVDM)
 * <4:0>    :: command
 */
#define SPRD_VDO(vid, type, custom)				\
	(((vid) << 16) |				\
	 ((type) << 15) |				\
	 ((custom) & 0x7FFF))

#define SPRD_VDO_SVDM_TYPE		(1 << 15)
#define SPRD_VDO_SVDM_VERS(x)		((x) << 13)
#define SPRD_VDO_OPOS(x)		((x) << 8)
#define SPRD_VDO_CMDT(x)		((x) << 6)
#define SPRD_VDO_OPOS_MASK		SPRD_VDO_OPOS(0x7)
#define SPRD_VDO_CMDT_MASK		SPRD_VDO_CMDT(0x3)

#define SPRD_CMDT_INIT			0
#define SPRD_CMDT_RSP_ACK		1
#define SPRD_CMDT_RSP_NAK		2
#define SPRD_CMDT_RSP_BUSY		3

/* reserved for SVDM ... for Google UVDM */
#define SPRD_VDO_SRC_INITIATOR		(0 << 5)
#define SPRD_VDO_SRC_RESPONDER		(1 << 5)

#define SPRD_CMD_DISCOVER_IDENT		1
#define SPRD_CMD_DISCOVER_SVID		2
#define SPRD_CMD_DISCOVER_MODES		3
#define SPRD_CMD_ENTER_MODE		4
#define SPRD_CMD_EXIT_MODE		5
#define SPRD_CMD_ATTENTION		6

#define SPRD_VDO_CMD_VENDOR(x)    (((0x10 + (x)) & 0x1f))

/* ChromeOS specific commands */
#define SPRD_VDO_CMD_VERSION		SPRD_VDO_CMD_VENDOR(0)
#define SPRD_VDO_CMD_SEND_INFO		SPRD_VDO_CMD_VENDOR(1)
#define SPRD_VDO_CMD_READ_INFO		SPRD_VDO_CMD_VENDOR(2)
#define SPRD_VDO_CMD_REBOOT		SPRD_VDO_CMD_VENDOR(5)
#define SPRD_VDO_CMD_FLASH_ERASE	SPRD_VDO_CMD_VENDOR(6)
#define SPRD_VDO_CMD_FLASH_WRITE	SPRD_VDO_CMD_VENDOR(7)
#define SPRD_VDO_CMD_ERASE_SIG		SPRD_VDO_CMD_VENDOR(8)
#define SPRD_VDO_CMD_PING_ENABLE	SPRD_VDO_CMD_VENDOR(10)
#define SPRD_VDO_CMD_CURRENT		SPRD_VDO_CMD_VENDOR(11)
#define SPRD_VDO_CMD_FLIP		SPRD_VDO_CMD_VENDOR(12)
#define SPRD_VDO_CMD_GET_LOG		SPRD_VDO_CMD_VENDOR(13)
#define SPRD_VDO_CMD_CCD_EN		SPRD_VDO_CMD_VENDOR(14)

#define SPRD_PD_VDO_VID(vdo)		((vdo) >> 16)
#define SPRD_PD_VDO_SVDM(vdo)		(((vdo) >> 15) & 1)
#define SPRD_PD_VDO_OPOS(vdo)		(((vdo) >> 8) & 0x7)
#define SPRD_PD_VDO_CMD(vdo)		((vdo) & 0x1f)
#define SPRD_PD_VDO_CMDT(vdo)		(((vdo) >> 6) & 0x3)

/*
 * SVDM Identity request -> response
 *
 * Request is simply properly formatted SVDM header
 *
 * Response is 4 data objects:
 * [0] :: SVDM header
 * [1] :: Identitiy header
 * [2] :: Cert Stat VDO
 * [3] :: (Product | Cable) VDO
 * [4] :: AMA VDO
 *
 */
#define SPRD_VDO_INDEX_HDR		0
#define SPRD_VDO_INDEX_IDH		1
#define SPRD_VDO_INDEX_CSTAT		2
#define SPRD_VDO_INDEX_CABLE		3
#define SPRD_VDO_INDEX_PRODUCT		3
#define SPRD_VDO_INDEX_AMA		4

/*
 * SVDM Identity Header
 * --------------------
 * <31>     :: data capable as a USB host
 * <30>     :: data capable as a USB device
 * <29:27>  :: product type
 * <26>     :: modal operation supported (1b == yes)
 * <25:16>  :: Reserved, Shall be set to zero
 * <15:0>   :: USB-IF assigned VID for this cable vendor
 */
#define SPRD_IDH_PTYPE_UNDEF		0
#define SPRD_IDH_PTYPE_HUB		1
#define SPRD_IDH_PTYPE_PERIPH		2
#define SPRD_IDH_PTYPE_PCABLE		3
#define SPRD_IDH_PTYPE_ACABLE		4
#define SPRD_IDH_PTYPE_AMA		5

#define SPRD_VDO_IDH(usbh, usbd, ptype, is_modal, vid)		\
	((usbh) << 31 | (usbd) << 30 | ((ptype) & 0x7) << 27	\
	 | (is_modal) << 26 | ((vid) & 0xffff))

#define SPRD_PD_IDH_PTYPE(vdo)		(((vdo) >> 27) & 0x7)
#define SPRD_PD_IDH_VID(vdo)		((vdo) & 0xffff)
#define SPRD_PD_IDH_MODAL_SUPP(vdo)	((vdo) & (1 << 26))

/*
 * Cert Stat VDO
 * -------------
 * <31:0>  : USB-IF assigned XID for this cable
 */
#define SPRD_PD_CSTAT_XID(vdo)		(vdo)

/*
 * Product VDO
 * -----------
 * <31:16> : USB Product ID
 * <15:0>  : USB bcdDevice
 */
#define SPRD_VDO_PRODUCT(pid, bcd)	(((pid) & 0xffff) << 16 | ((bcd) & 0xffff))
#define SPRD_PD_PRODUCT_PID(vdo)	(((vdo) >> 16) & 0xffff)

/*
 * Cable VDO
 * ---------
 * <31:28> :: Cable HW version
 * <27:24> :: Cable FW version
 * <23:20> :: Reserved, Shall be set to zero
 * <19:18> :: type-C to Type-A/B/C (00b == A, 01 == B, 10 == C)
 * <17>    :: Type-C to Plug/Receptacle (0b == plug, 1b == receptacle)
 * <16:13> :: cable latency (0001 == <10ns(~1m length))
 * <12:11> :: cable termination type (11b == both ends active VCONN req)
 * <10>    :: SSTX1 Directionality support (0b == fixed, 1b == cfgable)
 * <9>     :: SSTX2 Directionality support
 * <8>     :: SSRX1 Directionality support
 * <7>     :: SSRX2 Directionality support
 * <6:5>   :: Vbus current handling capability
 * <4>     :: Vbus through cable (0b == no, 1b == yes)
 * <3>     :: SOP" controller present? (0b == no, 1b == yes)
 * <2:0>   :: USB SS Signaling support
 */
#define SPRD_CABLE_ATYPE		0
#define SPRD_CABLE_BTYPE		1
#define SPRD_CABLE_CTYPE		2
#define SPRD_CABLE_PLUG			0
#define SPRD_CABLE_RECEPTACLE		1
#define SPRD_CABLE_CURR_1A5		0
#define SPRD_CABLE_CURR_3A		1
#define SPRD_CABLE_CURR_5A		2
#define SPRD_CABLE_USBSS_U2_ONLY	0
#define SPRD_CABLE_USBSS_U31_GEN1	1
#define SPRD_CABLE_USBSS_U31_GEN2	2
#define SPRD_VDO_CABLE(hw, fw, cbl, gdr, lat, term, tx1d, tx2d, rx1d, rx2d, cur,\
		       vps, sopp, usbss) \
	(((hw) & 0x7) << 28 | ((fw) & 0x7) << 24 | ((cbl) & 0x3) << 18	\
	 | (gdr) << 17 | ((lat) & 0x7) << 13 | ((term) & 0x3) << 11	\
	 | (tx1d) << 10 | (tx2d) << 9 | (rx1d) << 8 | (rx2d) << 7	\
	 | ((cur) & 0x3) << 5 | (vps) << 4 | (sopp) << 3		\
	 | ((usbss) & 0x7))

/*
 * AMA VDO
 * ---------
 * <31:28> :: Cable HW version
 * <27:24> :: Cable FW version
 * <23:12> :: Reserved, Shall be set to zero
 * <11>    :: SSTX1 Directionality support (0b == fixed, 1b == cfgable)
 * <10>    :: SSTX2 Directionality support
 * <9>     :: SSRX1 Directionality support
 * <8>     :: SSRX2 Directionality support
 * <7:5>   :: Vconn power
 * <4>     :: Vconn power required
 * <3>     :: Vbus power required
 * <2:0>   :: USB SS Signaling support
 */
#define SPRD_VDO_AMA(hw, fw, tx1d, tx2d, rx1d, rx2d, vcpwr, vcr, vbr, usbss) \
	(((hw) & 0x7) << 28 | ((fw) & 0x7) << 24			\
	 | (tx1d) << 11 | (tx2d) << 10 | (rx1d) << 9 | (rx2d) << 8	\
	 | ((vcpwr) & 0x7) << 5 | (vcr) << 4 | (vbr) << 3		\
	 | ((usbss) & 0x7))

#define SPRD_PD_VDO_AMA_VCONN_REQ(vdo)	(((vdo) >> 4) & 1)
#define SPRD_PD_VDO_AMA_VBUS_REQ(vdo)	(((vdo) >> 3) & 1)

#define SPRD_AMA_VCONN_PWR_1W		0
#define SPRD_AMA_VCONN_PWR_1W5		1
#define SPRD_AMA_VCONN_PWR_2W		2
#define SPRD_AMA_VCONN_PWR_3W		3
#define SPRD_AMA_VCONN_PWR_4W		4
#define SPRD_AMA_VCONN_PWR_5W		5
#define SPRD_AMA_VCONN_PWR_6W		6
#define SPRD_AMA_USBSS_U2_ONLY		0
#define SPRD_AMA_USBSS_U31_GEN1		1
#define SPRD_AMA_USBSS_U31_GEN2		2
#define SPRD_AMA_USBSS_BBONLY		3

/*
 * SVDM Discover SVIDs request -> response
 *
 * Request is properly formatted VDM Header with discover SVIDs command.
 * Response is a set of SVIDs of all all supported SVIDs with all zero's to
 * mark the end of SVIDs.  If more than 12 SVIDs are supported command SHOULD be
 * repeated.
 */
#define SPRD_VDO_SVID(svid0, svid1)	(((svid0) & 0xffff) << 16 | ((svid1) & 0xffff))
#define SPRD_PD_VDO_SVID_SVID0(vdo)	((vdo) >> 16)
#define SPRD_PD_VDO_SVID_SVID1(vdo)	((vdo) & 0xffff)

/* USB-IF SIDs */
#define SPRD_USB_SID_PD			0xff00 /* power delivery */
#define SPRD_USB_SID_DISPLAYPORT	0xff01
#define SPRD_USB_SID_MHL		0xff02	/* Mobile High-Definition Link */

/* VDM command timeouts (in ms) */

#define SPRD_PD_T_VDM_UNSTRUCTURED	500
#define SPRD_PD_T_VDM_BUSY		100
#define SPRD_PD_T_VDM_WAIT_MODE_E	100
#define SPRD_PD_T_VDM_SNDR_RSP	30
#define SPRD_PD_T_VDM_E_MODE		25
#define SPRD_PD_T_VDM_RCVR_RSP	15

#endif /* __LINUX_USB_PD_VDO_H */
