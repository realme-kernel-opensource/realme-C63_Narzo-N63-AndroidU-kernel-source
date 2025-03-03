/* SPDX-License-Identifier: GPL-2.0-or-later */

#ifndef SGM41513_REG
#define SGM41513_REG


/* Register 00h */
#define SGM41513_REG_00			0x00
#define SGM41513_ENHIZ_MASK		0x80
#define SGM41513_ENHIZ_SHIFT		7
#define SGM41513_HIZ_ENABLE		1
#define SGM41513_HIZ_DISABLE		0

#define SGM41513_STAT_CTRL_MASK		0x60
#define SGM41513_STAT_CTRL_SHIFT	5
#define SGM41513_STAT_CTRL_STAT		0
#define SGM41513_STAT_CTRL_ICHG		1
#define SGM41513_STAT_CTRL_IINDPM	2
#define SGM41513_STAT_CTRL_DISABLE	3

#define SGM41513_IINLIM_MASK		0x1F
#define SGM41513_IINLIM_SHIFT		0
#define SGM41513_IINLIM_MAX		3200
#define SGM41513_IINLIM_LSB		100
#define SGM41513_IINLIM_BASE		100


/* Register 01h */
#define SGM41513_REG_01			0x01
#define SGM41513_PFM_DIS_MASK		0x80
#define SGM41513_PFM_DIS_SHIFT		7
#define SGM41513_PFM_ENABLE		0
#define SGM41513_PFM_DISABLE		1

#define SGM41513_WDT_RESET_MASK		0x40
#define SGM41513_WDT_RESET_SHIFT	6
#define SGM41513_WDT_RESET		1

#define SGM41513_OTG_CONFIG_MASK	0x20
#define SGM41513_OTG_CONFIG_SHIFT	5
#define SGM41513_OTG_ENABLE		1
#define SGM41513_OTG_DISABLE		0

#define SGM41513_CHG_CONFIG_MASK	0x10
#define SGM41513_CHG_CONFIG_SHIFT	4
#define SGM41513_CHG_DISABLE		0
#define SGM41513_CHG_ENABLE		1

#define SGM41513_SYS_MINV_MASK		0x0E
#define SGM41513_SYS_MINV_SHIFT		1

#define SGM41513_MIN_VBAT_SEL_MASK	0x01
#define SGM41513_MIN_VBAT_SEL_SHIFT	0
#define SGM41513_MIN_VBAT_2P8V		0
#define SGM41513_MIN_VBAT_2P5V		1


/* Register 0x02*/
#define SGM41513_REG_02			0x02
#define SGM41513_BOOST_LIM_MASK		0x80
#define SGM41513_BOOST_LIM_SHIFT	7
#define SGM41513_BOOST_LIM_0P5A		0
#define SGM41513_BOOST_LIM_1P2A		1

#define SGM41513_Q1_FULLON_MASK		0x40
#define SGM41513_Q1_FULLON_SHIFT	6
#define SGM41513_Q1_FULLON_ENABLE	1
#define SGM41513_Q1_FULLON_DISABLE	0

#define SGM41513_ICHG_MASK		0x3F
#define SGM41513_ICHG_SHIFT		0


/* Register 0x03*/
#define SGM41513_REG_03			0x03
#define SGM41513_IPRECHG_MASK		0xF0
#define SGM41513_IPRECHG_SHIFT		4

#define SGM41513_ITERM_MASK		0x0F
#define SGM41513_ITERM_SHIFT		0


/* Register 0x04*/
#define SGM41513_REG_04			0x04
#define SGM41513_VREG_MASK		0xF8
#define SGM41513_VREG_SHIFT		3
#define SGM41513_VREG_BASE		3856
#define SGM41513_VREG_MAX		4624
#define SGM41513_VREG_LSB		32

#define SGM41513_TOPOFF_TIMER_MASK	0x06
#define SGM41513_TOPOFF_TIMER_SHIFT	1
#define SGM41513_TOPOFF_TIMER_DISABLE	0
#define SGM41513_TOPOFF_TIMER_15M	1
#define SGM41513_TOPOFF_TIMER_30M	2
#define SGM41513_TOPOFF_TIMER_45M	3

#define SGM41513_VRECHG_MASK		0x01
#define SGM41513_VRECHG_SHIFT		0
#define SGM41513_VRECHG_100MV		0
#define SGM41513_VRECHG_200MV		1

/* Register 0x05*/
#define SGM41513_REG_05			0x05
#define SGM41513_EN_TERM_MASK		0x80
#define SGM41513_EN_TERM_SHIFT		7
#define SGM41513_TERM_ENABLE		1
#define SGM41513_TERM_DISABLE		0

#define SGM41513_ITERM_TIMER_MASK	0x40
#define SGM41513_ITERM_TIMER_SHIFT	6
#define SGM41513_ITERM_TIMER_200MS	0
#define SGM41513_ITERM_TIMER_16MS	1

#define SGM41513_WDT_MASK		0x30
#define SGM41513_WDT_SHIFT		4
#define SGM41513_WDT_DISABLE		0
#define SGM41513_WDT_40S		1
#define SGM41513_WDT_80S		2
#define SGM41513_WDT_160S		3
#define SGM41513_WDT_BASE		0
#define SGM41513_WDT_LSB		40

#define SGM41513_EN_TIMER_MASK		0x08
#define SGM41513_EN_TIMER_SHIFT		3
#define SGM41513_CHG_TIMER_ENABLE	1
#define SGM41513_CHG_TIMER_DISABLE	0

#define SGM41513_CHG_TIMER_MASK		0x04
#define SGM41513_CHG_TIMER_SHIFT	2
#define SGM41513_CHG_TIMER_7HRS		0
#define SGM41513_CHG_TIMER_16HRS	1

#define SGM41513_TREG_MASK		0x02
#define SGM41513_TREG_SHIFT		1
#define SGM41513_TREG_80C		0
#define SGM41513_TREG_120C		1

#define SGM41513_JEITA_ISET_MASK	0x01
#define SGM41513_JEITA_ISET_SHIFT	0
#define SGM41513_JEITA_ISET_50PCT	0
#define SGM41513_JEITA_ISET_20PCT	1


/* Register 0x06*/
#define SGM41513_REG_06			0x06
#define SGM41513_OVP_MASK		0xC0
#define SGM41513_OVP_SHIFT		0x6
#define SGM41513_OVP_5P5V		0
#define SGM41513_OVP_6P5V		1
#define SGM41513_OVP_10P5V		2
#define SGM41513_OVP_14V		3

#define SGM41513_BOOSTV_MASK		0x30
#define SGM41513_BOOSTV_SHIFT		4
#define SGM41513_BOOSTV_4P85V		0
#define SGM41513_BOOSTV_5V		1
#define SGM41513_BOOSTV_5P15V		2
#define SGM41513_BOOSTV_5P3V		3

#define SGM41513_VINDPM_MASK		0x0F
#define SGM41513_VINDPM_SHIFT		0
#define SGM41513_VINDPM_OS_3P9V_MAX	5400
#define SGM41513_VINDPM_OS_3P9V_BASE	3900
#define SGM41513_VINDPM_OS_5P9V_MAX	7400
#define SGM41513_VINDPM_OS_5P9V_BASE	5900
#define SGM41513_VINDPM_OS_7P5V_MAX	9000
#define SGM41513_VINDPM_OS_7P5V_BASE	7500
#define SGM41513_VINDPM_OS_10P5V_MAX	12000
#define SGM41513_VINDPM_OS_10P5V_BASE	10500
#define SGM41513_VINDPM_LSB		100


/* Register 0x07*/
#define SGM41513_REG_07			0x07
#define SGM41513_IINDET_EN_MASK		0x80
#define SGM41513_IINDET_EN_SHIFT	7
#define SGM41513_IINDET_ENABLE		1
#define SGM41513_IINDET_DISABLE		0

#define SGM41513_TMR2X_EN_MASK		0x40
#define SGM41513_TMR2X_EN_SHIFT		6
#define SGM41513_TMR2X_ENABLE		1
#define SGM41513_TMR2X_DISABLE		0

#define SGM41513_BATFET_DIS_MASK	0x20
#define SGM41513_BATFET_DIS_SHIFT	5
#define SGM41513_BATFET_OFF		1
#define SGM41513_BATFET_ON		0

#define SGM41513_JEITA_VSET_MASK	0x10
#define SGM41513_JEITA_VSET_SHIFT	4
#define SGM41513_JEITA_VSET_4100	0
#define SGM41513_JEITA_VSET_VREG	1

#define SGM41513_BATFET_DLY_MASK	0x08
#define SGM41513_BATFET_DLY_SHIFT	3
#define SGM41513_BATFET_DLY_0S		0
#define SGM41513_BATFET_DLY_10S		1

#define SGM41513_BATFET_RST_EN_MASK	0x04
#define SGM41513_BATFET_RST_EN_SHIFT	2
#define SGM41513_BATFET_RST_DISABLE	0
#define SGM41513_BATFET_RST_ENABLE	1

#define SGM41513_VDPM_BAT_TRACK_MASK	0x03
#define SGM41513_VDPM_BAT_TRACK_SHIFT	0
#define SGM41513_VDPM_BAT_TRACK_DISABLE	0
#define SGM41513_VDPM_BAT_TRACK_200MV	1
#define SGM41513_VDPM_BAT_TRACK_250MV	2
#define SGM41513_VDPM_BAT_TRACK_300MV	3


/* Register 0x08*/
#define SGM41513_REG_08			0x08
#define SGM41513_VBUS_STAT_MASK		0xE0
#define SGM41513_VBUS_STAT_SHIFT	5
#define SGM41513_VBUS_TYPE_NONE		0
#define SGM41513_VBUS_TYPE_USB		1
#define SGM41513_VBUS_TYPE_ADAPTER	3
#define SGM41513_VBUS_TYPE_OTG		7

#define SGM41513_CHRG_STAT_MASK		0x18
#define SGM41513_CHRG_STAT_SHIFT	3
#define SGM41513_CHRG_STAT_IDLE		0
#define SGM41513_CHRG_STAT_PRECHG	1
#define SGM41513_CHRG_STAT_FASTCHG	2
#define SGM41513_CHRG_STAT_CHGDONE	3

#define SGM41513_PG_STAT_MASK		0x04
#define SGM41513_PG_STAT_SHIFT		2
#define SGM41513_POWER_GOOD		1

#define SGM41513_THERM_STAT_MASK	0x02
#define SGM41513_THERM_STAT_SHIFT	1

#define SGM41513_VSYS_STAT_MASK		0x01
#define SGM41513_VSYS_STAT_SHIFT	0
#define SGM41513_IN_VSYS_STAT		1


/* Register 0x09*/
#define SGM41513_REG_09			0x09
#define SGM41513_FAULT_WDT_MASK		0x80
#define SGM41513_FAULT_WDT_SHIFT	7
#define SGM41513_FAULT_WDT		1

#define SGM41513_FAULT_BOOST_MASK	0x40
#define SGM41513_FAULT_BOOST_SHIFT	6

#define SGM41513_FAULT_CHRG_MASK	0x30
#define SGM41513_FAULT_CHRG_SHIFT	4
#define SGM41513_FAULT_CHRG_NORMAL	0
#define SGM41513_FAULT_CHRG_INPUT	1
#define SGM41513_FAULT_CHRG_THERMAL	2
#define SGM41513_FAULT_CHRG_TIMER	3

#define SGM41513_FAULT_BAT_MASK		0x08
#define SGM41513_FAULT_BAT_SHIFT	3
#define SGM41513_FAULT_BAT_OVP		1

#define SGM41513_FAULT_NTC_MASK		0x07
#define SGM41513_FAULT_NTC_SHIFT	0
#define SGM41513_FAULT_NTC_NORMAL	0
#define SGM41513_FAULT_NTC_WARM		2
#define SGM41513_FAULT_NTC_COOL		3
#define SGM41513_FAULT_NTC_COLD		5
#define SGM41513_FAULT_NTC_HOT		6


/* Register 0x0A */
#define SGM41513_REG_0A			0x0A
#define SGM41513_VBUS_GD_MASK		0x80
#define SGM41513_VBUS_GD_SHIFT		7
#define SGM41513_VBUS_GD		1

#define SGM41513_VINDPM_STAT_MASK	0x40
#define SGM41513_VINDPM_STAT_SHIFT	6
#define SGM41513_VINDPM_ACTIVE		1

#define SGM41513_IINDPM_STAT_MASK	0x20
#define SGM41513_IINDPM_STAT_SHIFT	5
#define SGM41513_IINDPM_ACTIVE		1

#define SGM41513_TOPOFF_ACTIVE_MASK	0x08
#define SGM41513_TOPOFF_ACTIVE_SHIFT	3
#define SGM41513_TOPOFF_ACTIVE		1

#define SGM41513_ACOV_STAT_MASK		0x04
#define SGM41513_ACOV_STAT_SHIFT	2
#define SGM41513_ACOV_ACTIVE		1

#define SGM41513_VINDPM_INT_MASK	0x02
#define SGM41513_VINDPM_INT_SHIFT	1
#define SGM41513_VINDPM_INT_ENABLE	0
#define SGM41513_VINDPM_INT_DISABLE	1

#define SGM41513_IINDPM_INT_MASK	0x01
#define SGM41513_IINDPM_INT_SHIFT	0
#define SGM41513_IINDPM_INT_ENABLE	0
#define SGM41513_IINDPM_INT_DISABLE	1

#define SGM41513_INT_MASK_MASK		0x03
#define SGM41513_INT_MASK_SHIFT		0


/* Register 0x0B */
#define SGM41513_REG_0B			0x0B
#define SGM41513_REG_RESET_MASK		0x80
#define SGM41513_REG_RESET_SHIFT	7
#define SGM41513_REG_RESET		1

#define SGM41513_PN_MASK		0x78
#define SGM41513_PN_SHIFT		3

#define SGM41513_SGMPART_MASK		0x04
#define SGM41513_SGMPART_SHIFT		2

#define SGM41513_DEV_REV_MASK		0x03
#define SGM41513_DEV_REV_SHIFT		0


/* Register 0x0C */
#define SGM41513_REG_0C			0x0C


/* Register 0x0D */
#define SGM41513_REG_0D			0x0D


/* Register 0x0E */
#define SGM41513_REG_0E			0x0E


/* Register 0x0F */
#define SGM41513_REG_0F			0x0F

#define SGM41513_VINDPM_OS_MASK		0x03
#define SGM41513_VINDPM_OS_SHIFT	0
#define SGM41513_VINDPM_OS_3P9V		0
#define SGM41513_VINDPM_OS_5P9V		1
#define SGM41513_VINDPM_OS_7P5V		2
#define SGM41513_VINDPM_OS_10P5V	3

#endif

