// SPDX-License-Identifier: GPL-2.0-only
/*
 * sprd-pamu3.h - Unisoc platform header
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

#ifndef _PAM_USB3_H_
#define _PAM_USB3_H_

#include <linux/bitops.h>

/* pam u3 registers */
#define PAM_U3_CTL0						0x0000
#define PAM_U3_SRC_MACH					0x0004
#define PAM_U3_SRC_MACL					0x0008
#define PAM_U3_DST_MACH					0x000c
#define PAM_U3_DST_MACL					0x0010
#define PAM_U3_RNDIS_DATA_OFFSET		0x0014
#define PAM_U3_RNDIS_DATA_LENGTH		0x0018
#define PAM_U3_RNDIS_ODATA_OFFSET		0x001c
#define PAM_U3_RNDIS_ODATA_LENGTH		0x0020
#define PAM_U3_RNDIS_NUMODATAINFO		0x0024
#define PAM_U3_RNDIS_PERPACKOFFSET		0x0028
#define PAM_U3_RNDIS_PERPACKLENGTH		0x002c
#define PAM_U3_RNDIS_VCHANDLE			0x0030
#define PAM_U3_TXEVENTTBUFFER_ADDRL		0x0040
#define PAM_U3_TXEVENTTBUFFER_ADDRH		0x0044
#define PAM_U3_RXEVENTTBUFFER_ADDRL		0x0048
#define PAM_U3_RXEVENTTBUFFER_ADDRH		0x004c
#define PAM_U3_DLFIFOFILL_ADDRL			0x0050
#define PAM_U3_DLFIFOFILL_ADDRH			0x0054
#define PAM_U3_DLFIFOFREE_ADDRL			0x0058
#define PAM_U3_DLFIFOFREE_ADDRH			0x005c
#define PAM_U3_ULFIFOFILL_ADDRL			0x0060
#define PAM_U3_ULFIFOFILL_ADDRH			0x0064
#define PAM_U3_ULFIFOFREE_ADDRL			0x0068
#define PAM_U3_ULFIFOFREE_ADDRH			0x006c
#define PAM_U3_TXTRBBUF0_ADDRL			0x0070
#define PAM_U3_TXTRBBUF0_ADDRH			0x0074
#define PAM_U3_TXTRBBUF1_ADDRL			0x0078
#define PAM_U3_TXTRBBUF1_ADDRH			0x007c
#define PAM_U3_RXTRBBUF0_ADDRL			0x0080
#define PAM_U3_RXTRBBUF0_ADDRH			0x0084
#define PAM_U3_RXTRBBUF1_ADDRL			0x0088
#define PAM_U3_RXTRBBUF1_ADDRH			0x008c
#define PAM_U3_RXTRBBUF2_ADDRL			0x0090
#define PAM_U3_RXTRBBUF2_ADDRH			0x0094
#define PAM_U3_RXTRBBUF3_ADDRL			0x0098
#define PAM_U3_RXTRBBUF3_ADDRH			0x009c
#define PAM_U3_TXPROIRAM_ADDRL			0x00a0
#define PAM_U3_TXPROIRAM_ADDRH			0x00a4
#define PAM_U3_RXPROIRAM_ADDRL			0x00a8
#define PAM_U3_RXPROIRAM_ADDRH			0x00ac
#define PAM_U3_TXPCMDENTRY_ADDR0		0x00b0
#define PAM_U3_TXPCMDENTRY_ADDR1		0x00b4
#define PAM_U3_RXPCMDENTRY_ADDR0		0x00b8
#define PAM_U3_RXPCMDENTRY_ADDR1		0x00bc
#define PAM_U3_TXEVTBUFFER_ADDRL		0x00c0
#define PAM_U3_TXEVTBUFFER_ADDRH		0x00c4
#define PAM_U3_RXEVTBUFFER_ADDRL		0x00c8
#define PAM_U3_RXEVTBUFFER_ADDRH		0x00cc
#define PAM_U3_TXEVTCOUNT_ADDRL			0x00d0
#define PAM_U3_TXEVTCOUNT_ADDRH			0x00d4
#define PAM_U3_RXEVTCOUNT_ADDRL			0x00d8
#define PAM_U3_RXEVTCOUNT_ADDRH			0x00dc
#define PAM_U3_CTL1						0x00e0
#define PAM_U3_INR_EN					0x00e4
#define PAM_U3_INR_CLR					0x00e8
#define PAM_U3_RXBUF0_ADDRL				0x00f0
#define PAM_U3_RXBUF0_ADDRH				0x00f4
#define PAM_U3_RXBUF1_ADDRL				0x00f8
#define PAM_U3_RXBUF1_ADDRH				0x00fc
#define PAM_U3_RXBUF2_ADDRL				0x0100
#define PAM_U3_RXBUF2_ADDRH				0x0104
#define PAM_U3_RXBUF3_ADDRL				0x0108
#define PAM_U3_RXBUF3_ADDRH				0x010c
#define PAM_U3_DLGETIPAFIFO_ADDRL		0x0110
#define PAM_U3_DLGETIPAFIFO_ADDRH		0x0114
#define PAM_U3_DLPUTIPAFIFO_ADDRL		0x0118
#define PAM_U3_DLPUTIPAFIFO_ADDRH		0x011c
#define PAM_U3_ULGETIPAFIFO_ADDRL		0x0120
#define PAM_U3_ULGETIPAFIFO_ADDRH		0x0124
#define PAM_U3_ULPUTIPAFIFO_ADDRL		0x0128
#define PAM_U3_ULPUTIPAFIFO_ADDRH		0x012c
#define PAM_U3_HEADER_ENDBASE_ADDRL		0x0130
#define PAM_U3_HEADER_ENDBASE_ADDRH		0x0134
#define PAM_U3_HEADER2_ENDBASE_ADDRL		0x01e8
#define PAM_U3_HEADER2_ENDBASE_ADDRH		0x01e4
#define PAM_U3_TRB_HEADER				0x0138
#define PAM_U3_TRB_HEADER_SID			0x013c
#define PAM_U3_UL_NODE_HEADER			0x0140
#define PAM_U3_UL_NODE_ERRCODE			0x0144
#define PAM_U3_DL_GETPUT_COMMONFIFO		0x0148
#define PAM_U3_UL_GETPUT_COMMONFIFO		0x014c
#define PAM_U3_MBIM_NCM_NTH				0x0150
#define PAM_U3_MBIM_NCM_NDP				0x0154
#define PAM_U3_AXI_WR_CHANPRIO			0x0158
#define PAM_U3_AXI_RD_CHANPRIO			0x015c
#define PAM_U3_GETPUT_OFFSET			0x0160
#define PAM_U3_RX_CTRL_DEBUG			0x0164
#define PAM_U3_RX_PRO_DEC_DEBUG			0x0168
#define PAM_U3_TRB_GEN_DEBUG			0x016c
#define PAM_U3_TX_PRO_GEN_DEBUG			0x0170
#define PAM_U3_AXI_OS					0x0174
#define PAM_U3_SOF_DST_NODE_OFFSET		0x0178
#define PAM_U3_ID_CONFIG				0x017c
#define PAM_U3_DDRMAP_OFFSETH			0x0180
#define PAM_U3_DDRMAP_OFFSETL			0x0184
#define PAM_U3_BUFFER01_COUNT			0x0188
#define PAM_U3_BUFFER23_COUNT			0x018c

#define PAM_U3_TX_REG(n)				((0x0400 + (n * 4)))
#define PAM_U3_TXDBG_INSTRUC_ADDRL		0x0440
#define PAM_U3_TXDBG_INSTRUC_ADDRH		0x0444
#define PAM_U3_TXDBG_STATE				0x0448
#define PAM_U3_TXDBG_BUFLEN				0x044c
#define PAM_U3_TXDBG_LINK_ADDRL			0x0450
#define PAM_U3_TXDBG_LINK_ADDRH			0x0454
#define PAM_U3_DUMMY_REG1				0x0460
#define PAM_U3_TXDBG_IRAM				0x0500

#define PAM_U3_RX_REG(n)				((0x0900 + (n * 4)))
#define PAM_U3_RXDBG_INSTRUC_ADDRL		0x0940
#define PAM_U3_RXDBG_INSTRUC_ADDRH		0x0944
#define PAM_U3_RXDBG_STATE				0x0948
#define PAM_U3_RXDBG_BUFLEN				0x094c
#define PAM_U3_RXDBG_LINK_ADDRL			0x0950
#define PAM_U3_RXDBG_LINK_ADDRH			0x0954
#define PAM_U3_DUMMY_REG2				0x0958
#define PAM_U3_RXDBG_IRAM				0x0a00

/*bitmap for PAM_U3_CTL0 */
#define PAMU3_CTL0_BIT_USB_EN			BIT(0)
#define PAMU3_CTL0_BIT_PAM_EN			BIT(1)
#define PAMU3_CTL0_BIT_RELEASE			BIT(2)
#define PAMU3_CTL0_BITS_STOPMODE		GENMASK(4, 3)
#define PAMU3_CTL0_BIT_DONE			BIT(8)

#define PAMU3_CTL0_MASK_PROTOCOL		GENMASK(6, 5)
#define PAMU3_CTL0_SHIFT_PROTOCOL		5
#define PAMU3_PROTOCOL_RNDIS			0x00
#define PAMU3_PROTOCOL_MBIM				0x01
#define PAMU3_PROTOCOL_NCM				0x02
#define PAMU3_PROTOCOL_NULL				0x03

#define PAMU3_CTL0_BIT_PROJECT			BIT(7)
#define PAMU3_CTL0_SHIFT_PROJECT		7
#define PAMU3_PROJECT_ORCA				0x00
#define PAMU3_PROJECT_ROC1				0x01

#define PAMU3_CTL0_BIT_TX_START			BIT(9)
#define PAMU3_CTL0_BIT_RX_START			BIT(10)

#define PAMU3_CTL0_MASK_RTL_VER			GENMASK(31, 20)

/* bitmap for PAM_U3_SRC_MACH */
#define PAMU3_MASK_SRCMAC_ADDRH			GENMASK(15, 0)
#define PAMU3_MASK_MAXIPCNT				GENMASK(23, 16)
#define MAX_PACKET_NUM				10
#define MAX_PACKET_NUM_SHIFT_BIT		16

/* bitmap for PAM_U3_DST_MACH */
#define PAMU3_MASK_DSTMAC_ADDRH			GENMASK(15, 0)
#define PAMU3_MASK_TRIGHDRCNT			GENMASK(31, 16)

/* bitmap for the highest byte of 40 bit-wide address */
#define PAMU3_BITS_LOWADDR32			32
#define PAMU3_MASK_LOWADDR32			GENMASK(31, 0)
#define PAMU3_MASK_ADDR32_LSB			GENMASK(7, 0)

/* bitmap for event size */
#define PAMU3_BITS_STARTEVTSZ			8
#define PAMU3_MASK_EVTSZ				GENMASK(15, 0)


/* bitmap for PAM_U3_CTL1 */
#define PAMU3_CTL1_TXSWREQ				BIT(0)
#define PAMU3_CTL1_TXSWRDY				BIT(1)
#define PAMU3_CTL1_RXSWREQ				BIT(2)
#define PAMU3_CTL1_RXSWRDY				BIT(3)
#define PAMU3_CTL1_TXCHKEN				BIT(4)
#define PAMU3_CTL1_RXCHKEN				BIT(5)
#define PAMU3_CTL1_TXDMAPRI				BIT(6)
#define PAMU3_CTL1_RXDMAPRI				BIT(7)
#define PAMU3_CTL1_TXHWBUSY				BIT(8)
#define PAMU3_CTL1_RXHWBUSY				BIT(9)

/* bitmap for PAM_U3_INR_EN and STS */
#define PAMU3_INTSTS_TXWDGTMOUT			BIT(0)
#define PAMU3_INTSTS_RXWDGTMOUT			BIT(1)
#define PAMU3_INTSTS_TXEPINT			BIT(2)
#define PAMU3_INTSTS_RXEPINT			BIT(3)
#define PAMU3_INTSTS_TXCMDERR			BIT(4)
#define PAMU3_INTSTS_RXCMDERR			BIT(5)
#define PAMU3_SHIFT_INTSTS				16

/* bitmap for PAM_U3_INR_CLR */
#define PAMU3_INTCLR_TXWDGTMOUT			BIT(0)
#define PAMU3_INTCLR_RXWDGTMOUT			BIT(1)
#define PAMU3_INTCLR_TXEPINT			BIT(2)
#define PAMU3_INTCLR_RXEPINT			BIT(3)
#define PAMU3_INTCLR_TXCMDERR			BIT(4)
#define PAMU3_INTCLR_RXCMDERR			BIT(5)

/* PAM_U3_TRB_HEADER */
#define PAMU3_TRB_LAST					0x100

/*bitmap for PAM_U3_UL_NODE_HEADER */
#define PAMU3_MASK_NETID				GENMASK(7, 0)
#define PAMU3_SHIFT_ULNODE_SRC			8
#define PAMU3_MASK_ULNODE_SRC			GENMASK(12, 8)
#define PAMU3_SHIFT_ULNODE_DST			13
#define PAMU3_MASK_ULNODE_DST			GENMASK(17, 13)

/* DWC3 regs */
#define REG_DWC3_GEVNTADRLO(n)			(0xc400 + (n * 0x10))
#define REG_DWC3_GEVNTADRHI(n)			(0xc404 + (n * 0x10))
#define REG_DWC3_GEVNTSIZ(n)			(0xc408 + (n * 0x10))
#define REG_DWC3_GEVNTCOUNT(n)			(0xc40c + (n * 0x10))
#define REG_DWC3_DEP_BASE(n)			(0xc800 + ((n) * 0x10))

/* TRB for PAM_U3 */
#define PAMU3_RX_TRB_NUM				4
#define PAMU3_TX_TRB_NUM				32
#define PAMU3_RX_TRBBUF_NUM				4
#define PAMU3_TX_TRBBUF_NUM				2
#define PAMU3_TRB_CTRL_DEFVAL			0x803
#define PAMU3_RX_TRBBUF_SIZE			0x4000
#define PAMU3_RNDIS_HEADER_SIZE			(1024*20)

#define PAMU3_BIT_RXTRBBUFSIZE_SHIFT	8
#define PAMU3_MASK_RXTRBBUFSIZE_LSB		GENMASK(7, 0)

/* MBIM */
#define PAM_U3_MBIM_DEFNTH				0x484d434e
#define PAM_U3_MBIM_DEFNDP				0x00535049

/* CMD ENTRY */
#define PAMU3_CMDENTER_ADDR0			0xa080600
#define PAMU3_CMDENTER_ADDR1			0xe0c0b1a

/* Packets per transfer default */
#define PAM_U3_MAX_DLPKTS_DEF			10
#define PAM_U3_MAX_ULPKTS_DEF			1

struct pamu3_dwc3_trb {
	u32		bpl;
	u32		bph;
	u32		size;
	u32		ctrl;
} __packed;

#endif /* _PAM_USB3_H_ */
