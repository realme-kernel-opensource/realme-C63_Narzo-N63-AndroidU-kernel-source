/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (C) 2021 Unisoc Inc.
 */

#ifndef __HL7139_HEADER__
#define __HL7139_HEADER__


/* HL7139 Register 00h */
#define HL7139_REG_00		0x00

#define HL7139_DEV_REV_MASK	0xF0
#define HL7139_DEV_REV_SHIFT	4
#define HL7139_DEV_REV_1ST	0
#define HL7139_DEV_REV_2ND	1

#define HL7139_DEV_ID_MASK	0x0F
#define HL7139_DEV_ID_SHIFT	0
#define HL7139_DEV_ID		0x0A


/* HL7139 Register 01h */
#define HL7139_REG_01			0x01
#define HL7139_STATE_CHG_I_MASK		0x80
#define HL7139_STATE_CHG_I_SHIFT	7

#define HL7139_REG_I_MASK		0x40
#define HL7139_REG_I_SHIFT		6

#define HL7139_TS_TEMP_I_MASK		0x20
#define HL7139_TS_TEMP_I_SHIFT		5

#define HL7139_V_OK_I_MASK		0x10
#define HL7139_V_OK_I_SHIFT		4

#define HL7139_CUR_I_MASK		0x08
#define HL7139_CUR_I_SHIFT		3

#define HL7139_SHORT_I_MASK		0x04
#define HL7139_SHORT_I_SHIFT		2

#define HL7139_WDOG_I_MASK		0x02
#define HL7139_WDOG_I_SHIFT		1


/* HL7139 Register 02h */
#define HL7139_REG_02			0x02
#define HL7139_STATE_CHG_M_MASK		0x80
#define HL7139_STATE_CHG_M_SHIFT	7
#define HL7139_STATE_CHG_M_DISABLE	0
#define HL7139_STATE_CHG_M_ENABLE	1

#define HL7139_REG_M_MASK		0x40
#define HL7139_REG_M_SHIFT		6
#define HL7139_REG_M_DISABLE		0
#define HL7139_REG_M_ENABLE		1

#define HL7139_TS_TEMP_M_MASK		0x20
#define HL7139_TS_TEMP_M_SHIFT		5
#define HL7139_TS_TEMP_M_DISABLE	0
#define HL7139_TS_TEMP_M_ENABLE		1

#define HL7139_V_OK_M_MASK		0x10
#define HL7139_V_OK_M_SHIFT		4
#define HL7139_V_OK_M_DISABLE		0
#define HL7139_V_OK_M_ENABLE		1

#define HL7139_CUR_M_MASK		0x08
#define HL7139_CUR_M_SHIFT		3
#define HL7139_CUR_M_DISABLE		0
#define HL7139_CUR_M_ENABLE		1

#define HL7139_SHORT_M_MASK		0x04
#define HL7139_SHORT_M_SHIFT		2
#define HL7139_SHORT_M_DISABLE		0
#define HL7139_SHORT_M_ENABLE		1

#define HL7139_WDOG_M_MASK		0x02
#define HL7139_WDOG_M_SHIFT		1
#define HL7139_WDOG_M_DISABLE		0
#define HL7139_WDOG_M_ENABLE		1


/* HL7139 Register 03h */
#define HL7139_REG_03				0x03
#define HL7139_STATE_CHG_STS_MASK		0xC0
#define HL7139_STATE_CHG_STS_SHIFT		6
#define HL7139_STATE_CHG_STS_SHUTDOWN_STATE	0
#define HL7139_STATE_CHG_STS_STANDBY_STATE	1
#define HL7139_STATE_CHG_STS_CP_ACTIVE_STATE	2
#define HL7139_STATE_CHG_STS_BP_ACTIVE_STATE	3

#define HL7139_REG_STS_MASK			0x3C
#define HL7139_REG_STS_SHIFT			2
#define HL7139_REG_STS_NOT_ACTIVE		0
#define HL7139_REG_STS_VBAT_ACTIVE		1
#define HL7139_REG_STS_IIN_ACTIVE		2
#define HL7139_REG_STS_IBAT_ACTIVE		4
#define HL7139_REG_STS_DIE_TEMP_ACTIVE		8

#define HL7139_TS_TEMP_STS_MASK			0x02
#define HL7139_TS_TEMP_STS_SHIFT		1


/* HL7139 Register 04h */
#define HL7139_REG_04			0x04

#define HL7139_V_NOT_OK_STS_MASK	0x10
#define HL7139_V_NOT_OK_STS_SHIFT	4

#define HL7139_CUR_STS_MASK		0x08
#define HL7139_CUR_STS_SHIFT		3

#define HL7139_SHORT_STS_MASK		0x04
#define HL7139_SHORT_STS_SHIFT		2

#define HL7139_WDOG_STS_MASK		0x02
#define HL7139_WDOG_STS_SHIFT		1


/* HL7139 Register 05h */
#define HL7139_REG_05			0x05
#define HL7139_VIN_OVP_STS_MASK		0x80
#define HL7139_VIN_OVP_STS_SHIFT	7

#define HL7139_VIN_UVLO_STS_MASK	0x40
#define HL7139_VIN_UVLO_STS_SHIFT	6

#define HL7139_TRACK_OV_STS_MASK	0x20
#define HL7139_TRACK_OV_STS_SHIFT	5

#define HL7139_TRACK_UV_STS_MASK	0x10
#define HL7139_TRACK_UV_STS_SHIFT	4

#define HL7139_VBAT_OVP_STS_MASK	0x08
#define HL7139_VBAT_OVP_STS_SHIFT	3

#define HL7139_VOUT_OVP_STS_MASK	0x04
#define HL7139_VOUT_OVP_STS_SHIFT	2

#define HL7139_PMID_QUAL_STS_MASK	0x02
#define HL7139_PMID_QUAL_STS_SHIFT	1

#define HL7139_VBUS_UV_STS_MASK		0x01
#define HL7139_VBUS_UV_STS_SHIFT	0


/* HL7139 Register 06h */
#define HL7139_REG_06			0x06
#define HL7139_IIN_OCP_STS_MASK		0x80
#define HL7139_IIN_OCP_STS_SHIFT	7

#define HL7139_IBAT_OCP_STS_MASK	0x40
#define HL7139_IBAT_OCP_STS_SHIFT	6

#define HL7139_IIN_UCP_STS_MASK		0x20
#define HL7139_IIN_UCP_STS_SHIFT	5

#define HL7139_FET_SHORT_STS_MASK	0x10
#define HL7139_FET_SHORT_STS_SHIFT	4

#define HL7139_CFLY_SHORT_STS_MASK	0x08
#define HL7139_CFLY_SHORT_STS_SHIFT	3

#define HL7139_DEV_MODE_STS_MASK	0x06
#define HL7139_DEV_MODE_STS_SHIFT	1
#define HL7139_DEV_MODE_STS_SLAVE_MODE	2
#define HL7139_DEV_MODE_STS_MASTER_MODE	3

#define HL7139_THSD_STS_MASK		0x01
#define HL7139_THSD_STS_SHIFT		0


/* HL7139 Register 07h */
#define HL7139_REG_07			0x07
#define HL7139_QPUMP_STS_MASK		0x80
#define HL7139_QPUMP_STS_SHIFT		7

#define HL7139_VIN_OVP_S_MASK		0x40
#define HL7139_VIN_OVP_S_SHIFT		6

#define HL7139_VIN_UVLO_S_MASK		0x20
#define HL7139_VIN_UVLO_S_SHIFT		5

#define HL7139_TRACK_OV_S_MASK		0x10
#define HL7139_TRACK_OV_S_SHIFT		4

#define HL7139_TRACK_UV_S_MASK		0x08
#define HL7139_TRACK_UV_S_SHIFT		3

#define HL7139_VBAT_OVP_S_MASK		0x04
#define HL7139_VBAT_OVP_S_SHIFT		2

#define HL7139_VOUT_OVP_S_MASK		0x02
#define HL7139_VOUT_OVP_S_SHIFT		1

#define HL7139_VBUS_GOOD_S_MASK		0x01
#define HL7139_VBUS_GOOD_S_SHIFT	0


/* HL7139 Register 08h */
#define HL7139_REG_08			0x08
#define HL7139_VBAT_OVP_DIS_MASK	0x80
#define HL7139_VBAT_OVP_DIS_SHIFT	7
#define HL7139_VBAT_OVP_ENABLE		0
#define HL7139_VBAT_OVP_DISABLE		1

#define HL7139_TVBAT_OVP_DEB_MASK	0x40
#define HL7139_TVBAT_OVP_DEB_SHIFT	6
#define HL7139_TVBAT_OVP_DEB_80US	0
#define HL7139_TVBAT_OVP_DEB_2MS	1

#define HL7139_VBAT_REG_TH_MASK		0x3F
#define HL7139_VBAT_REG_TH_SHIFT	0
#define HL7139_VBAT_REG_TH_BASE		4000
#define HL7139_VBAT_REG_TH_MAX		4600
#define HL7139_VBAT_REG_TH_LSB		10


/* HL7139 Register 09h */
#define HL7139_REG_09			0x09

#define HL7139_DIG_CLK_DIS_MASK		0x02
#define HL7139_DIG_CLK_DIS_SHIFT	1

#define HL7139_DEEP_STBY_EN_MASK	0x01
#define HL7139_DEEP_STBY_EN_SHIFT	0


/* HL7139 Register 0Ah */
#define HL7139_REG_0A			0x0A
#define HL7139_IBAT_OCP_DIS_MASK	0x80
#define HL7139_IBAT_OCP_DIS_SHIFT	7
#define HL7139_IBAT_OCP_ENABLE		0
#define HL7139_IBAT_OCP_DISABLE		1

#define HL7139_TIBAT_OCP_DEB_MASK	0x40
#define HL7139_TIBAT_OCP_DEB_SHIFT	6
#define HL7139_TIBAT_OCP_DEB_80US	0
#define HL7139_TIBAT_OCP_DEB_120US	1

#define HL7139_IBAT_REG_TH_MASK		0x3F
#define HL7139_IBAT_REG_TH_SHIFT	0
#define HL7139_IBAT_REG_TH_BASE		2000
#define HL7139_IBAT_REG_TH_MAX		6600
#define HL7139_IBAT_REG_TH_LSB		100


/* HL7139 Register 0Bh */
#define HL7139_REG_0B			0x0B
#define HL7139_EXT_NFET_USE_MASK	0x80
#define HL7139_EXT_NFET_USE_SHIFT	7
#define HL7139_EXT_NFET_USE_DISABLE	0
#define HL7139_EXT_NFET_USE_ENABLE	1

#define HL7139_VBUS_PD_EN_MASK		0x40
#define HL7139_VBUS_PD_EN_SHIFT		6
#define HL7139_VBUS_PD_EN_DISABLE	0
#define HL7139_VBUS_PD_EN_ENABLE	1

#define HL7139_VGS_SEL_MASK		0x30
#define HL7139_VGS_SEL_SHIFT		4
#define HL7139_VGS_SEL_7V		0
#define HL7139_VGS_SEL_7P5V		1
#define HL7139_VGS_SEL_8V		2
#define HL7139_VGS_SEL_8P5V		3

#define HL7139_VBUS_OVP_TH_MASK		0x0F
#define HL7139_VBUS_OVP_TH_SHIFT	0
#define HL7139_VBUS_OVP_TH_BASE		4000
#define HL7139_VBUS_OVP_TH_MAX		19000
#define HL7139_VBUS_OVP_TH_LSB		1000


/* HL7139 Register 0Ch */
#define HL7139_REG_0C			0x0C

#define HL7139_VIN_PD_CFG_MASK		0x20
#define HL7139_VIN_PD_CFG_SHIFT		5
#define HL7139_VIN_PD_CFG_AUTO_MODE	0
#define HL7139_VIN_PD_CFG_FORCED_MODE	1

#define HL7139_VIN_OVP_DIS_MASK		0x10
#define HL7139_VIN_OVP_DIS_SHIFT	4
#define HL7139_VIN_OVP_ENABLE		0
#define HL7139_VIN_OVP_DISABLE		1

#define HL7139_VIN_OVP_MASK		0x0F
#define HL7139_VIN_OVP_SHIFT		0
#define HL7139_VIN_OVP_CP_MODE_BASE	10200
#define HL7139_VIN_OVP_CP_MODE_MAX	11700
#define HL7139_VIN_OVP_CP_MODE_LSB	100
#define HL7139_VIN_OVP_BP_MODE_BASE	5100
#define HL7139_VIN_OVP_BP_MODE_MAX	5850
#define HL7139_VIN_OVP_BP_MODE_LSB	50


/* HL7139 Register 0Eh */
#define HL7139_REG_0E			0x0E
#define HL7139_IIN_OCP_DIS_MASK		0x80
#define HL7139_IIN_OCP_DIS_SHIFT	7
#define HL7139_IIN_OCP_ENABLE		0
#define HL7139_IIN_OCP_DISABLE		1

#define HL7139_IIN_REG_TH_MASK		0x3F
#define HL7139_IIN_REG_TH_SHIFT		0
#define HL7139_IIN_REG_TH_CP_WORK_BASE	1000
#define HL7139_IIN_REG_TH_CP_WORK_MAX	3500
#define HL7139_IIN_REG_TH_CP_WORK_LSB	50
#define HL7139_IIN_REG_TH_BP_WORK_BASE	2000
#define HL7139_IIN_REG_TH_BP_WORK_MAX	7000
#define HL7139_IIN_REG_TH_BP_WORK_LSB	100


/* HL7139 Register 0Fh */
#define HL7139_REG_0F			0x0F
#define HL7139_TIIN_OCP_DEB_MASK	0x80
#define HL7139_TIIN_OCP_DEB_SHIFT	7
#define HL7139_TIIN_OCP_DEB_80US	0
#define HL7139_TIIN_OCP_DEB_200US	1

#define HL7139_IIN_OCP_TH_MASK		0x60
#define HL7139_IIN_OCP_TH_SHIFT		5
#define HL7139_IIN_OCP_TH_CP_MODE_BASE	150
#define HL7139_IIN_OCP_TH_CP_MODE_MAX	300
#define HL7139_IIN_OCP_TH_CP_MODE_LSB	50
#define HL7139_IIN_OCP_TH_BP_MODE_BASE	300
#define HL7139_IIN_OCP_TH_BP_MODE_MAX	600
#define HL7139_IIN_OCP_TH_BP_MODE_LSB	100


/* HL7139 Register 10h */
#define HL7139_REG_10			0x10
#define HL7139_TDIE_REG_DIS_MASK	0x80
#define HL7139_TDIE_REG_DIS_SHIFT	7
#define HL7139_TDIE_REG_ENABLE		0
#define HL7139_TDIE_REG_DISABLE		1

#define HL7139_IIN_REG_DIS_MASK		0x40
#define HL7139_IIN_REG_DIS_SHIFT	6
#define HL7139_IIN_REG_ENABLE		0
#define HL7139_IIN_REG_DISABLE		1

#define HL7139_TDIE_REG_TH_MASK		0x30
#define HL7139_TDIE_REG_TH_SHIFT	4
#define HL7139_TDIE_REG_TH_BASE		80
#define HL7139_TDIE_REG_TH_MAX		110
#define HL7139_TDIE_REG_TH_LSB		10


/* HL7139 Register 11h */
#define HL7139_REG_11			0x11

#define HL7139_VBAT_REG_DIS_MASK	0x80
#define HL7139_VBAT_REG_DIS_SHIFT	7
#define HL7139_VBAT_REG_ENABLE		0
#define HL7139_VBAT_REG_DISABLE		1

#define HL7139_IBAT_REG_DIS_MASK	0x40
#define HL7139_IBAT_REG_DIS_SHIFT	6
#define HL7139_IBAT_REG_ENABLE		0
#define HL7139_IBAT_REG_DISABLE		1

#define HL7139_BAT_OVP_TH_MASK		0x30
#define HL7139_BAT_OVP_TH_SHIFT		4
#define HL7139_BAT_OVP_TH_BASE		80
#define HL7139_BAT_OVP_TH_MAX		110
#define HL7139_BAT_OVP_TH_LSB		10
#define HL7139_BAT_OVP_TH_DEFAULT	90

#define HL7139_BAT_OCP_TH_MASK		0x0C
#define HL7139_BAT_OCP_TH_SHIFT		2
#define HL7139_BAT_OCP_TH_BASE		200
#define HL7139_BAT_OCP_TH_MAX		500
#define HL7139_BAT_OCP_TH_LSB		100
#define HL7139_BAT_OCP_TH_DEFAULT	500

/* HL7139 Register 12h */
#define HL7139_REG_12			0x12
#define HL7139_CHG_EN_MASK		0x80
#define HL7139_CHG_EN_SHIFT		7
#define HL7139_CHG_ENABLE		1
#define HL7139_CHG_DISABLE		0

#define HL7139_FSW_SET_MASK		0x78
#define HL7139_FSW_SET_SHIFT		3
#define HL7139_FSW_SET_BASE		500
#define HL7139_FSW_SET_MAX		1600
#define HL7139_FSW_SET_LSB		100

#define HL7139_UNPLUG_DET_EN_MASK	0x04
#define HL7139_UNPLUG_DET_EN_SHIFT	2
#define HL7139_UNPLUG_DET_ENABLE	1
#define HL7139_UNPLUG_DET_DISABLE	0

#define HL7139_IIN_UCP_TH_MASK		0x03
#define HL7139_IIN_UCP_TH_SHIFT		0
#define HL7139_IIN_UCP_TH_CP_MODE_BASE	100
#define HL7139_IIN_UCP_TH_CP_MODE_MAX	250
#define HL7139_IIN_UCP_TH_CP_MODE_LSB	50
#define HL7139_IIN_UCP_TH_BP_MODE_BASE	200
#define HL7139_IIN_UCP_TH_BP_MODE_MAX	500
#define HL7139_IIN_UCP_TH_BP_MODE_LSB	100


/* HL7139 Register 13h */
#define HL7139_REG_13			0x13
#define HL7139_UCP_DEB_SEL_MASK		0xC0
#define HL7139_UCP_DEB_SEL_SHIFT	6
#define HL7139_UCP_DEB_SEL_10MS		0
#define HL7139_UCP_DEB_SEL_100MS	1
#define HL7139_UCP_DEB_SEL_500MS	2
#define HL7139_UCP_DEB_SEL_1000MS	3

#define HL7139_VOUT_OVP_DIS_MASK	0x20
#define HL7139_VOUT_OVP_DIS_SHIFT	5
#define HL7139_VOUT_OVP_ENABLE		0
#define HL7139_VOUT_OVP_DISABLE		1

#define HL7139_TS_PROT_EN_MASK		0x10
#define HL7139_TS_PROT_EN_SHIFT		4
#define HL7139_TS_PROT_ENABLE		1
#define HL7139_TS_PROT_DISABLE		0

#define HL7139_AUTO_V_REC_EN_MASK	0x04
#define HL7139_AUTO_V_REC_EN_SHIFT	2
#define HL7139_AUTO_V_REC_ENABLE	1
#define HL7139_AUTO_V_REC_DISABLE	0

#define HL7139_AUTO_I_REC_EN_MASK	0x02
#define HL7139_AUTO_I_REC_EN_SHIFT	1
#define HL7139_AUTO_I_REC_ENABLE	1
#define HL7139_AUTO_I_REC_DISABLE	0

#define HL7139_AUTO_UCP_REC_EN_MASK	0x01
#define HL7139_AUTO_UCP_REC_EN_SHIFT	0
#define HL7139_AUTO_UCP_REC_ENABLE	1
#define HL7139_AUTO_UCP_REC_DISABLE	0


/* HL7139 Register 14h */
#define HL7139_REG_14		0x14
#define HL7139_RST_MASK		0xF0
#define HL7139_RST_SHIFT	4
#define HL7139_RST_ENABLE	0xC
#define HL7139_RST_DISABLE	0x0

#define HL7139_WD_DIS_MASK	0x08
#define HL7139_WD_DIS_SHIFT	3
#define HL7139_WD_ENABLE	0
#define HL7139_WD_DISABLE	1

#define HL7139_WD_TIMEOUT_MASK	0x07
#define HL7139_WD_TIMEOUT_SHIFT	0
#define HL7139_WD_TIMEOUT_0P2S	0
#define HL7139_WD_TIMEOUT_0P5S	1
#define HL7139_WD_TIMEOUT_1S	2
#define HL7139_WD_TIMEOUT_2S	3
#define HL7139_WD_TIMEOUT_5S	4
#define HL7139_WD_TIMEOUT_10S	5
#define HL7139_WD_TIMEOUT_20S	6
#define HL7139_WD_TIMEOUT_40S	7


/* HL7139 Register 15h */
#define HL7139_REG_15				0x15
#define HL7139_DEV_MODE_MASK			0x80
#define HL7139_DEV_MODE_SHIFT			7
#define HL7139_DEV_MODE_CP_MODE			0
#define HL7139_DEV_MODE_BP_MODE			1

#define HL7139_DPDM_CFG_MASK			0x04
#define HL7139_DPDM_CFG_SHIFT			2
#define HL7139_DPDM_CFG_DP_DM_MODE		0
#define HL7139_DPDM_CFG_SYNC_AND_TS_MODE	1

#define HL7139_GPP_CFG_MASK			0x03
#define HL7139_GPP_CFG_SHIFT			0
#define HL7139_GPP_CFG_BATN_SNSN_FUNC		0
#define HL7139_GPP_CFG_GPP_SNSN_FUNC		1
#define HL7139_GPP_CFG_SYNC_FUNC		2
#define HL7139_GPP_CFG_NO_FUNC			3


/* HL7139 Register 16h */
#define HL7139_REG_16			0x16
#define HL7139_TRACK_OV_DIS_MASK	0x80
#define HL7139_TRACK_OV_DIS_SHIFT	7
#define HL7139_TRACK_OV_ENABLE		0
#define HL7139_TRACK_OV_DISABLE		1

#define HL7139_TRACK_UV_DIS_MASK	0x40
#define HL7139_TRACK_UV_DIS_SHIFT	6
#define HL7139_TRACK_UV_ENABLE		0
#define HL7139_TRACK_UV_DISABLE		1

#define HL7139_TRACK_OV_MASK		0x38
#define HL7139_TRACK_OV_SHIFT		3
#define HL7139_TRACK_OV_DELTA_TH_BASE	200
#define HL7139_TRACK_OV_DELTA_TH_MAX	900
#define HL7139_TRACK_OV_DELTA_TH_LSB	100

#define HL7139_TRACK_UV_MASK		0x07
#define HL7139_TRACK_UV_SHIFT		0
#define HL7139_TRACK_UV_DELTA_TH_BASE	50
#define HL7139_TRACK_UV_DELTA_TH_MAX	400
#define HL7139_TRACK_UV_DELTA_TH_LSB	50


/* HL7139 Register 17h */
#define HL7139_REG_17			0x17
#define HL7139_TS_TH_MASK		0xFF
#define HL7139_TS_TH_SHIFT		0


/* Register 40h */
#define HL7139_REG_40				0x40
#define HL7139_ADC_REG_COPY_MASK		0x80
#define HL7139_ADC_REG_COPY_SHIFT		7
#define HL7139_ADC_REG_COPY_FREE_RUNNING_MODE	0
#define HL7139_ADC_REG_COPY_MANUAL_MODE		1

#define HL7139_ADC_MAN_COPY_MASK		0x40
#define HL7139_ADC_MAN_COPY_SHIFT		6
#define HL7139_ADC_MAN_COPY_DISABLE		0
#define HL7139_ADC_MAN_COPY_ENABLE		1

#define HL7139_ADC_MODE_CFG_MASK		0x18
#define HL7139_ADC_MODE_CFG_SHIFT		3
#define HL7139_ADC_MODE_CFG_AUTO_MODE		0
#define HL7139_ADC_MODE_CFG_FORCE_ENABLE_MODE	1
#define HL7139_ADC_MODE_CFG_FORCE_DISABLE_MODE	2

#define HL7139_ADC_AVG_TIME_MASK		0x06
#define HL7139_ADC_AVG_TIME_SHIFT		1
#define HL7139_ADC_AVG_TIME_1			0
#define HL7139_ADC_AVG_TIME_2			1
#define HL7139_ADC_AVG_TIME_4			2

#define HL7139_ADC_READ_EN_MASK			0x01
#define HL7139_ADC_READ_EN_SHIFT		0
#define HL7139_ADC_READ_DISABLE			0
#define HL7139_ADC_READ_ENABLE			1


/* Register 41h */
#define HL7139_REG_41			0x41
#define HL7139_VIN_ADC_DIS_MASK		0x80
#define HL7139_VIN_ADC_DIS_SHIFT	7
#define HL7139_VIN_ADC_ENABLE		0
#define HL7139_VIN_ADC_DISABLE		1

#define HL7139_IIN_ADC_DIS_MASK		0x40
#define HL7139_IIN_ADC_DIS_SHIFT	6
#define HL7139_IIN_ADC_ENABLE		0
#define HL7139_IIN_ADC_DISABLE		1

#define HL7139_VBAT_ADC_DIS_MASK	0x20
#define HL7139_VBAT_ADC_DIS_SHIFT	5
#define HL7139_VBAT_ADC_ENABLE		0
#define HL7139_VBAT_ADC_DISABLE		1

#define HL7139_IBAT_ADC_DIS_MASK	0x10
#define HL7139_IBAT_ADC_DIS_SHIFT	4
#define HL7139_IBAT_ADC_ENABLE		0
#define HL7139_IBAT_ADC_DISABLE		1

#define HL7139_TS_ADC_DIS_MASK		0x08
#define HL7139_TS_ADC_DIS_SHIFT		3
#define HL7139_TS_ADC_ENABLE		0
#define HL7139_TS_ADC_DISABLE		1

#define HL7139_TDIE_ADC_DIS_MASK	0x04
#define HL7139_TDIE_ADC_DIS_SHIFT	2
#define HL7139_TDIE_ADC_ENABLE		0
#define HL7139_TDIE_ADC_DISABLE		1

#define HL7139_VOUT_ADC_DIS_MASK	0x02
#define HL7139_VOUT_ADC_DIS_SHIFT	1
#define HL7139_VOUT_ADC_ENABLE		0
#define HL7139_VOUT_ADC_DISABLE		1


/* Register 42h */
#define HL7139_REG_42		0x42
#define HL7139_VIN_POL_H_MASK	0xFF


/* Register 43h */
#define HL7139_REG_43		0x43
#define HL7139_VIN_POL_L_MASK	0x0F


/* Register 44h */
#define HL7139_REG_44		0x44
#define HL7139_IIN_POL_H_MASK	0xFF


/* Register 45h */
#define HL7139_REG_45		0x45
#define HL7139_IIN_POL_L_MASK	0x0F


/* Register 46h */
#define HL7139_REG_46		0x46
#define HL7139_VBAT_POL_H_MASK	0xFF


/* Register 47h */
#define HL7139_REG_47		0x47
#define HL7139_VBAT_POL_L_MASK	0x0F


/* Register 48h */
#define HL7139_REG_48		0x48
#define HL7139_IBAT_POL_H_MASK	0xFF


/* Register 49h */
#define HL7139_REG_49		0x49
#define HL7139_IBAT_POL_L_MASK	0x0F


/* Register 4Ah */
#define HL7139_REG_4A		0x4A
#define HL7139_VTS_POL_H_MASK	0xFF


/* Register 4Bh */
#define HL7139_REG_4B		0x4B
#define HL7139_VTS_POL_L_MASK	0x0F


/* Register 4Ch */
#define HL7139_REG_4C		0x4C
#define HL7139_VOUT_POL_H_MASK	0xFF


/* Register 4Dh */
#define HL7139_REG_4D		0x4D
#define HL7139_VOUT_POL_L_MASK	0x0F


/* Register 4Eh */
#define HL7139_REG_4E		0x4E
#define HL7139_TDIE_POL_H_MASK	0xFF


/* Register 4Fh */
#define HL7139_REG_4F		0x4F
#define HL7139_TDIE_POL_L_MASK	0x0F

#endif
