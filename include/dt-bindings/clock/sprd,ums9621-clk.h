/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Unisoc UMS9621 platform clocks
 *
 * Copyright (C) 2022, Unisoc Inc.
 */

#ifndef _DT_BINDINGS_CLK_UMS9621_H_
#define _DT_BINDINGS_CLK_UMS9621_H_

#define CLK_52M			0
#define CLK_26M_AUD		1
#define CLK_13M			2
#define CLK_6M5			3
#define CLK_4M3			4
#define CLK_4M			5
#define CLK_2M			6
#define CLK_1M			7
#define CLK_250K		8
#define CLK_16K			9
#define CLK_RCO_100M_25M	10
#define CLK_RCO_100m_20M	11
#define CLK_RCO_100m_4M		12
#define CLK_RCO_100m_2M		13
#define CLK_RCO_60m_20M		14
#define CLK_RCO_60m_4M		15
#define CLK_RCO_60m_2M		16
#define CLK_PHYR8PLL_GATE	17
#define CLK_PSR8PLL_GATE	18
#define CLK_V4NRPLL_GATE	19
#define CLK_TGPLL_GATE		20
#define CLK_MPLLL_GATE		21
#define CLK_MPLLM_GATE		22
#define CLK_MPLLM1_GATE		23
#define CLK_MPLLS_GATE		24
#define CLK_DPLL0_GATE		25
#define CLK_DPLL1_GATE		26
#define CLK_DPLL2_GATE		27
#define CLK_GPLL_GATE		28
#define CLK_AUDPLL_GATE		29
#define CLK_PIXELPLL_GATE	30
#define CLK_PMU_GATE_NUM	(CLK_PIXELPLL_GATE + 1)

#define CLK_RPLL		0
#define CLK_RPLL_390M		1
#define CLK_RPLL_26M		2
#define CLK_ANLG_PHY_G1_NUM	(CLK_RPLL_26M + 1)

#define CLK_DPLL0		0
#define CLK_DPLL1		1
#define CLK_DPLL2		2
#define CLK_ANLG_PHY_G1L_NUM	(CLK_DPLL2 + 1)

#define CLK_TGPLL		0
#define CLK_TGPLL_12M		1
#define CLK_TGPLL_24M		2
#define CLK_TGPLL_38M4		3
#define CLK_TGPLL_48M		4
#define CLK_TGPLL_51M2		5
#define CLK_TGPLL_64M		6
#define CLK_TGPLL_76M8		7
#define CLK_TGPLL_96M		8
#define CLK_TGPLL_128M		9
#define CLK_TGPLL_153M6		10
#define CLK_TGPLL_192M		11
#define CLK_TGPLL_256M		12
#define CLK_TGPLL_307M2		13
#define CLK_TGPLL_384M		14
#define CLK_TGPLL_512M		15
#define CLK_TGPLL_614M4		16
#define CLK_TGPLL_768M		17
#define CLK_PSR8PLL		18
#define CLK_V4NRPLL		19
#define CLK_V4NRPLL_38M4	20
#define CLK_V4NRPLL_409M6	21
#define CLK_V4NRPLL_614M4	22
#define CLK_V4NRPLL_819M2	23
#define CLK_V4NRPLL_1228M8	24
#define CLK_ANLG_PHY_G5L_NUM	(CLK_V4NRPLL_1228M8 + 1)

#define CLK_GPLL		0
#define	CLK_GPLL_680M		1
#define CLK_GPLL_850M           2
#define CLK_AUDPLL		3
#define CLK_AUDPLL_38M4		4
#define CLK_AUDPLL_24M57	5
#define CLK_AUDPLL_19M2		6
#define CLK_AUDPLL_12M28	7
#define CLK_PHYR8PLL		8
#define CLK_PIXELPLL		9
#define CLK_PIXELPLL_200M	10
#define CLK_PIXELPLL_400M	11
#define CLK_PIXELPLL_420M	12
#define CLK_ANLG_PHY_G5R_NUM	(CLK_PIXELPLL_420M + 1)

#define CLK_MPLLM1		0
#define CLK_ANLG_PHY_G8_NUM	(CLK_MPLLM1 + 1)

#define CLK_MPLLM		0
#define CLK_ANLG_PHY_G9_NUM	(CLK_MPLLM + 1)

#define CLK_MPLLL		0
#define CLK_MPLLS		1
#define CLK_ANLG_PHY_G10_NUM	(CLK_MPLLS + 1)

#define CLK_IIS0_EB		0
#define CLK_IIS1_EB		1
#define CLK_IIS2_EB		2
#define CLK_SPI0_EB		3
#define CLK_SPI1_EB		4
#define CLK_SPI2_EB		5
#define CLK_UART3_EB		6
#define CLK_UART0_EB		7
#define CLK_UART1_EB		8
#define CLK_UART2_EB		9
#define CLK_SPI0_LFIN_EB	10
#define CLK_SPI1_LFIN_EB	11
#define CLK_SPI2_LFIN_EB	12
#define CLK_SPI3_LFIN_EB	13
#define CLK_CE_SEC_EB		14
#define CLK_CE_PUB_EB		15
#define CLK_AP_APB_GATE_NUM	(CLK_CE_PUB_EB + 1)

#define CLK_SDIO0_EB		0
#define CLK_SDIO1_EB		1
#define CLK_SDIO2_EB		2
#define CLK_EMMC_EB		3
#define CLK_DMA_PUB_EB		4
#define CLK_UFS_EB		5
#define CLK_CKG_EB		6
#define CLK_BUSMON_CLK_EB	7
#define CLK_AP2EMC_EB		8
#define CLK_I2C0_EB		9
#define CLK_I2C1_EB		10
#define CLK_I2C2_EB		11
#define CLK_I2C3_EB		12
#define CLK_I2C4_EB		13
#define CLK_I2C5_EB		14
#define CLK_I2C6_EB		15
#define CLK_I2C7_EB		16
#define CLK_I2C8_EB		17
#define CLK_I2C9_EB		18
#define CLK_UFS_TX_EB		19
#define CLK_UFS_RX_0_EB		20
#define CLK_UFS_RX_1_EB		21
#define CLK_UFS_CFG_EB		22
#define CLK_AP_AHB_GATE_NUM	(CLK_UFS_CFG_EB + 1)

#define CLK_AP_APB		0
#define CLK_AP_AXI		1
#define CLK_AP2EMC		2
#define CLK_AP_UART0		3
#define CLK_AP_UART1		4
#define CLK_AP_UART2		5
#define CLK_AP_UART3		6
#define CLK_AP_I2C0		7
#define CLK_AP_I2C1		8
#define CLK_AP_I2C2		9
#define CLK_AP_I2C3		10
#define CLK_AP_I2C4		11
#define CLK_AP_I2C5		12
#define CLK_AP_I2C6		13
#define CLK_AP_I2C7		14
#define CLK_AP_I2C8		15
#define CLK_AP_I2C9		16
#define CLK_AP_IIS0		17
#define CLK_AP_IIS1		18
#define CLK_AP_IIS2		19
#define CLK_AP_CE		20
#define CLK_EMMC_2X		21
#define CLK_EMMC_1X		22
#define CLK_UFS_TX		23
#define CLK_UFS_RX		24
#define CLK_UFS_RX_1		25
#define CLK_UFS_CFG		26
#define CLK_IPA_AXI		27
#define CLK_IPA_APB		28
#define CLK_AP_CLK_NUM		(CLK_IPA_APB + 1)

#define CLK_RC100M_CAL_EB	0
#define CLK_RFTI_EB		1
#define CLK_DJTAG_EB		2
#define CLK_AUX0_EB		3
#define CLK_AUX1_EB		4
#define CLK_AUX2_EB		5
#define CLK_PROBE_EB		6
#define CLK_MM_EB		7
#define CLK_GPU_EB		8
#define CLK_MSPI_EB		9
#define CLK_AI_EB		10
#define CLK_APCPU_DAP_EB	11
#define CLK_AON_CSSYS_EB	12
#define CLK_CSSYS_APB_EB	13
#define CLK_CSSYS_PUB_EB	14
#define CLK_DPU_VSP_EB		15
#define CLK_DSI_CFG_EB		16
#define CLK_EFUSE_EB		17
#define CLK_GPIO_EB		18
#define CLK_MBOX_EB		19
#define CLK_KPD_EB		20
#define CLK_AON_SYST_EB		21
#define CLK_AP_SYST_EB		22
#define CLK_AON_TMR_EB		23
#define CLK_AON_DVFS_TOP_EB	24
#define CLK_AON_USB2_TOP_EB	25
#define CLK_OTG_PHY_EB		26
#define CLK_SPLK_EB		27
#define CLK_PIN_EB		28
#define CLK_ANA_EB		29
#define CLK_APCPU_BUSMON_EB	30
#define CLK_UFS_AO_EB		31
#define CLK_ISE_APB_EB		32
#define CLK_APCPU_TS0_EB	33
#define CLK_APB_BUSMON_EB	34
#define CLK_AON_IIS_EB		35
#define CLK_SCC_EB		36
#define CLK_SERDES_CTRL1_EB     37
#define CLK_AUX3_EB		38
#define CLK_THM0_EB		39
#define CLK_THM1_EB		40
#define CLK_THM2_EB		41
#define CLK_THM3_EB		42
#define CLK_AUDCP_INTC_EB	43
#define CLK_PMU_EB		44
#define CLK_ADI_EB		45
#define CLK_EIC_EB		46
#define CLK_AP_INTC0_EB		47
#define CLK_AP_INTC1_EB		48
#define CLK_AP_INTC2_EB		49
#define CLK_AP_INTC3_EB		50
#define CLK_AP_INTC4_EB		51
#define CLK_AP_INTC5_EB		52
#define CLK_AP_INTC6_EB		53
#define CLK_AP_INTC7_EB		54
#define CLK_PSCP_INTC_EB	55
#define CLK_PHYCP_INTC_EB	56
#define CLK_ISE_INTC_EB		57
#define CLK_AP_TMR0_EB		58
#define CLK_AP_TMR1_EB		59
#define CLK_AP_TMR2_EB		60
#define CLK_PWM0_EB		61
#define CLK_PWM1_EB		62
#define CLK_PWM2_EB		63
#define CLK_PWM3_EB		64
#define CLK_AP_WDG_EB		65
#define CLK_APCPU_WDG_EB	66
#define CLK_SERDES_CTRL0_EB	67
#define CLK_ARCH_RTC_EB		68
#define CLK_KPD_RTC_EB		69
#define CLK_AON_SYST_RTC_EB	70
#define CLK_AP_SYST_RTC_EB	71
#define CLK_AON_TMR_RTC_EB	72
#define CLK_EIC_RTC_EB		73
#define CLK_EIC_RTCDV5_EB	74
#define CLK_AP_WDG_RTC_EB	75
#define CLK_AC_WDG_RTC_EB	76
#define CLK_AP_TMR0_RTC_EB	77
#define CLK_AP_TMR1_RTC_EB	78
#define CLK_AP_TMR2_RTC_EB	79
#define CLK_DCXO_LC_RTC_EB	80
#define CLK_BB_CAL_RTC_EB	81
#define CLK_DSI_CSI_TEST_EB	82
#define CLK_DJTAG_TCK_EN	83
#define CLK_DPHY_REF_EB		84
#define CLK_DMC_REF_EB		85
#define CLK_OTG_REF_EB		86
#define CLK_TSEN_EB		87
#define CLK_TMR_EB		88
#define CLK_RC100M_REF_EB	89
#define CLK_RC100M_FDK_EB	90
#define CLK_DEBOUNCE_EB		91
#define CLK_DET_32K_EB		92
#define CLK_TOP_CSSYS_EB	93
#define CLK_AP_AXI_EN		94
#define CLK_SDIO0_2X_EN		95
#define CLK_SDIO0_1X_EN		96
#define CLK_SDIO1_2X_EN		97
#define CLK_SDIO1_1X_EN		98
#define CLK_SDIO2_2X_EN		99
#define CLK_SDIO2_1X_EN		100
#define CLK_EMMC_1X_EN		101
#define CLK_EMMC_2X_EN		102
#define CLK_PLL_TEST_EN		103
#define CLK_CPHY_CFG_EN		104
#define CLK_DEBUG_TS_EN		105
#define CLK_ACCESS_AUD_EN	106
#define CLK_BUSMON_CSTMR_PUB2	107
#define CLK_AUX0		108
#define CLK_AUX1		109
#define CLK_AUX2		110
#define CLK_PROBE		111
#define CLK_AUX3		112
#define CLK_AON_APB_GATE_NUM	(CLK_AUX3 + 1)

#define CLK_AON_APB		0
#define CLK_ADI			1
#define CLK_PWM0		2
#define CLK_PWM1		3
#define CLK_PWM2		4
#define CLK_PWM3		5
#define CLK_EFUSE		6
#define CLK_UART0		7
#define CLK_UART1		8
#define CLK_UART2		9
#define CLK_THM0		10
#define CLK_THM1		11
#define CLK_THM2		12
#define CLK_THM3		13
#define CLK_AON_IST		14
#define CLK_AON_IIS		15
#define CLK_SCC			16
#define CLK_APCPU_DAP		17
#define CLK_APCPU_TS		18
#define CLK_DEBUG_TS		19
#define CLK_PRI_SBI		20
#define CLK_XO_SEL		21
#define CLK_RFTI_LTH		22
#define CLK_AFC_LTH		23
#define CLK_RCO100M_FDK		24
#define CLK_RCO60M_FDK		25
#define CLK_RCO6M_REF		26
#define CLK_RCO6M_FDK		27
#define CLK_DJTAG_TCK		28
#define CLK_AON_TMR		29
#define CLK_AON_PMU		30
#define CLK_DEBOUNCE		31
#define CLK_APCPU_PMU		32
#define CLK_TOP_DVFS		33
#define CLK_PMU_26M		34
#define CLK_TZPC		35
#define CLK_OTG_REF		36
#define CLK_CSSYS		37
#define CLK_CSSYS_APB		38
#define CLK_SDIO0_2X		39
#define CLK_SDIO0_1X		40
#define CLK_SDIO1_2X		41
#define CLK_SDIO1_1X		42
#define CLK_SDIO2_2X		43
#define CLK_SDIO2_1X		44
#define CLK_SPI0		45
#define CLK_SPI1		46
#define CLK_SPI2		47
#define CLK_ANALOG_IO_APB	48
#define CLK_DMC_REF		49
#define CLK_USB			50
#define CLK_USB_SUSPEND		51
#define CLK_UFS_AON		52
#define CLK_UFS_PCK		53
#define CLK_AON_APB_NUM		(CLK_UFS_PCK + 1)

#define CLK_CORE0		0
#define CLK_CORE1		1
#define CLK_CORE2		2
#define CLK_CORE3		3
#define CLK_CORE4		4
#define CLK_CORE5		5
#define CLK_CORE6		6
#define CLK_CORE7		7
#define CLK_SCU			8
#define CLK_ACE			9
#define CLK_ATB			10
#define CLK_DEBUG_APB		11
#define CLK_CPS			12
#define CLK_GIC			13
#define CLK_PERIPH		14
#define CLK_TOPDVFS_CLK_NUM	(CLK_PERIPH + 1)

#define CLK_JPG_EN			0
#define CLK_CKG_EN			1
#define CLK_DVFS_EN			2
#define CLK_SYS_MTX_CFG_EN		3
#define CLK_SYS_CFG_MTX_BUSMON_EN	4
#define CLK_SYS_MST_BUSMON_EN		5
#define CLK_SYS_TCK_EN			6
#define CLK_MM_MTX_DATA_EN		7
#define CLK_ISP_EN			8
#define CLK_CPP_EN			9
#define CLK_ISP_MTX_EN			10
#define CLK_ISP_BLK_CFG_EN		11
#define CLK_ISP_BLK_MST_BUSMON_EN	12
#define CLK_ISP_TCK_EN			13
#define CLK_DCAM_IF_EN			14
#define CLK_DCAM_IF_LITE_EN		15
#define CLK_PHY_CFG_EN			16
#define CLK_DCAM_MTX_EN			17
#define CLK_DCAM_LITE_MTX_EN		18
#define CLK_DCAM_BLK_CFG_EN		19
#define CLK_SENSOR0_EN			20
#define CLK_SENSOR2_EN			21
#define CLK_SENSOR3_EN			22
#define CLK_DCAM_TCK_EN			23
#define CLK_CSI0_EN			24
#define CLK_CSI2_EN			25
#define CLK_CSI3_EN			26
#define CLK_IPA_EN			27
#define CLK_MM_GATE_NUM			(CLK_IPA_EN + 1)

#define CLK_ISP			1
#define CLK_CPP			2
#define CLK_DCAM0_1		3
#define CLK_DCAM0_1_AXI		4
#define CLK_DCAM2_3		5
#define CLK_DCAM2_3_AXI		6
#define CLK_MIPI_CSI0		7
#define CLK_MIPI_CSI2_1		8
#define CLK_MIPI_CSI2_2		9
#define CLK_MIPI_CSI3_1		10
#define CLK_MIPI_CSI3_2		11
#define CLK_DCAM_MTX		12
#define CLK_DCAM_BLK_CFG	13
#define CLK_MM_MTX_DATA		14
#define CLK_JPG			15
#define CLK_MM_SYS_CFG		16
#define CLK_SENSOR0		17
#define CLK_SENSOR2		18
#define CLK_SENSOR3		19
#define CLK_MM_CLK_NUM		(CLK_SENSOR3 + 1)

#define CLK_DPU_EB		0
#define CLK_DSI0_EB		1
#define CLK_DSI1_EB		2
#define CLK_VPU_ENC0_EB		3
#define CLK_VPU_DEC_EB		4
#define CLK_GSP0_EB		5
#define CLK_DPU_DVFS_EB		6
#define CLK_DPU_CKG_EB		7
#define CLK_DPU_BUSMON_EB	8
#define CLK_DSC0_EB		9
#define CLK_DSC1_EB		10
#define CLK_M_DIV6CLK_GATE_EN	11
#define CLK_S_DIV6CLK_GATE_EN	12
#define CLK_DPU_VSP_GATE_NUM	(CLK_S_DIV6CLK_GATE_EN + 1)

#define CLK_DPU_CFG		0
#define CLK_VPU_MTX		1
#define CLK_VPU_ENC		2
#define CLK_VPU_DEC		3
#define CLK_GSP0		4
#define CLK_DISPC0		5
#define CLK_DISPC0_DPI		6
#define CLK_DISPC0_DSC		7
#define CLK_DPU_VSP_CLK_NUM	(CLK_DISPC0_DSC + 1)

#define CLK_AUDCP_IIS0_EB		0
#define CLK_AUDCP_IIS1_EB		1
#define CLK_AUDCP_IIS2_EB		2
#define CLK_AUDCP_UART_EB		3
#define CLK_AUDCP_DMA_CP_EB		4
#define CLK_AUDCP_DMA_AP_EB		5
#define CLK_AUDCP_SRC48K_EB		6
#define CLK_AUDCP_MCDT_EB		7
#define CLK_AUDCP_VBC_EB		8
#define CLK_AUDCP_SPLK_EB		9
#define CLK_AUDCP_ICU_EB		10
#define CLK_AUDCP_DMA_AP_ASHB_EB	11
#define CLK_AUDCP_DMA_CP_ASHB_EB	12
#define CLK_AUDCP_AUD_EB		13
#define CLK_AUDIF_CKG_AUTO_EN		14
#define CLK_AUDCP_VBC_24M_EB		15
#define CLK_AUDCP_TMR_26M_EB		16
#define CLK_AUDCP_DVFS_ASPB_EB		17
#define CLK_AUDCP_MATRIX_CFG_EN		18
#define CLK_AUDCP_TDM_HF_EB		19
#define CLK_AUDCP_TDM_EB		20
#define CLK_AUDCP_VBC_AP_EB		21
#define CLK_AUDCP_MCDT_AP_EB		22
#define CLK_AUDCP_AUD_AP_EB		23
#define CLK_AUDCP_GLB_GATE_NUM		(CLK_AUDCP_AUD_AP_EB + 1)

#define CLK_AUDCP_VAD_EB		0
#define CLK_AUDCP_PDM_EB		1
#define CLK_AUDCP_AUDIF_EB		2
#define CLK_AUDCP_PDM_IIS_EB		3
#define CLK_AUDCP_VAD_APB_EB		4
#define CLK_AUDCP_PDM_AP_EB		5
#define CLK_AUDCP_APB_GATE_NUM		(CLK_AUDCP_PDM_AP_EB + 1)

#endif/* _DT_BINDINGS_CLK_UMS9621_H_ */
