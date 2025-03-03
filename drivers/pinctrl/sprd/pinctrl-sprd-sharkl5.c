// SPDX-License-Identifier: GPL-2.0-only
/*
 * Unisoc ums312 pinctrl driver
 *
 * Copyright (C) 2021 Unisoc, Inc.
 * Author: luting guo<luting.guo@unisoc.com>
 */


#include <linux/module.h>
#include <linux/mod_devicetable.h>
#include <linux/platform_device.h>

#include "pinctrl-sprd.h"

#define	PINCTRL_REG_OFFSET		0x34
#define	PINCTRL_REG_MISC_OFFSET		0x434

enum sprd_sharkl5_pins {
	/* UART_MATRIX_MTX_CFG */
	SHARKL5_UART_INF6_SYS_SEL = SPRD_PIN_INFO(0, GLOBAL_CTRL_PIN, 28, 4, 1),
	SHARKL5_UART_INF5_SYS_SEL = SPRD_PIN_INFO(1, GLOBAL_CTRL_PIN, 24, 4, 1),
	SHARKL5_UART_INF4_SYS_SEL = SPRD_PIN_INFO(2, GLOBAL_CTRL_PIN, 20, 4, 1),
	SHARKL5_UART_INF3_SYS_SEL = SPRD_PIN_INFO(3, GLOBAL_CTRL_PIN, 16, 4, 1),
	SHARKL5_UART_INF2_INF3_LOOP = SPRD_PIN_INFO(4, GLOBAL_CTRL_PIN, 15, 1, 1),
	SHARKL5_UART_INF2_INF4_LOOP = SPRD_PIN_INFO(5, GLOBAL_CTRL_PIN, 14, 1, 1),
	SHARKL5_UART_INF2_SYS_SEL = SPRD_PIN_INFO(6, GLOBAL_CTRL_PIN, 10, 4, 1),
	SHARKL5_UART_INF1_INF4_LOOP = SPRD_PIN_INFO(7, GLOBAL_CTRL_PIN, 9, 1, 1),
	SHARKL5_UART_INF1_INF3_LOOP = SPRD_PIN_INFO(8, GLOBAL_CTRL_PIN, 8, 1, 1),
	SHARKL5_UART_INF1_SYS_SEL = SPRD_PIN_INFO(9, GLOBAL_CTRL_PIN, 4, 4, 1),
	SHARKL5_UART_INF0_SYS_SEL = SPRD_PIN_INFO(10, GLOBAL_CTRL_PIN, 0, 4, 1),

	/* UART_MATRIX_MTX_CFG1 */
	SHARKL5_UART_INF9_SYS_SEL = SPRD_PIN_INFO(11, GLOBAL_CTRL_PIN, 9, 4, 2),
	SHARKL5_UART_INF8_SYS_SEL = SPRD_PIN_INFO(12, GLOBAL_CTRL_PIN, 5, 4, 2),
	SHARKL5_UART_INF7_INF8_LOOP = SPRD_PIN_INFO(13, GLOBAL_CTRL_PIN, 4, 1, 2),
	SHARKL5_UART_INF7_SYS_SEL = SPRD_PIN_INFO(14, GLOBAL_CTRL_PIN, 0, 4, 2),

	/* IIS_MATRIX_MTX_CFG */
	SHARKL5_IIS_INF4_INF3_LOOP = SPRD_PIN_INFO(15, GLOBAL_CTRL_PIN, 23, 1, 3),
	SHARKL5_IIS_INF4_SYS_SEL = SPRD_PIN_INFO(16, GLOBAL_CTRL_PIN, 19, 4, 3),
	SHARKL5_IIS_INF3_SYS_SEL = SPRD_PIN_INFO(17, GLOBAL_CTRL_PIN, 15, 4, 3),
	SHARKL5_IIS_INF2_SYS_SEL = SPRD_PIN_INFO(18, GLOBAL_CTRL_PIN, 11, 4, 3),
	SHARKL5_IIS_INF1_INF2_LOOP = SPRD_PIN_INFO(19, GLOBAL_CTRL_PIN, 10, 1, 3),
	SHARKL5_IIS_INF1_SYS_SEL = SPRD_PIN_INFO(20, GLOBAL_CTRL_PIN, 6, 4, 3),
	SHARKL5_IIS_INF0_INF2_LOOP = SPRD_PIN_INFO(21, GLOBAL_CTRL_PIN, 5, 1, 3),
	SHARKL5_IIS_INF0_INF1_LOOP = SPRD_PIN_INFO(22, GLOBAL_CTRL_PIN, 4, 1, 3),
	SHARKL5_IIS_INF0_SYS_SEL = SPRD_PIN_INFO(23, GLOBAL_CTRL_PIN, 0, 4, 3),

	/* SIM_MATRIX_MTX_CFG */
	SHARKL5_SIM_INF2_SYS_SEL = SPRD_PIN_INFO(24, GLOBAL_CTRL_PIN, 2, 1, 4),
	SHARKL5_SIM_INF1_SYS_SEL = SPRD_PIN_INFO(25, GLOBAL_CTRL_PIN, 1, 1, 4),
	SHARKL5_SIM_INFO_SYS_SEL = SPRD_PIN_INFO(26, GLOBAL_CTRL_PIN, 0, 1, 4),

	/* SPI_MATRIX_MTX_CFG */
	SHARKL5_SPI_INF3_SYS_SEL = SPRD_PIN_INFO(27, GLOBAL_CTRL_PIN, 3, 1, 5),
	SHARKL5_SPI_INF2_SYS_SEL = SPRD_PIN_INFO(28, GLOBAL_CTRL_PIN, 2, 1, 5),
	SHARKL5_SPI_INF1_SYS_SEL = SPRD_PIN_INFO(29, GLOBAL_CTRL_PIN, 1, 1, 5),
	SHARKL5_SPI_INF0_SYS_SEL = SPRD_PIN_INFO(30, GLOBAL_CTRL_PIN, 0, 1, 5),

	/* IIC_MATRIX_MTX_CFG */
	SHARKL5_IIC_INF6_SYS_SEL = SPRD_PIN_INFO(31, GLOBAL_CTRL_PIN, 18, 3, 6),
	SHARKL5_IIC_INF5_SYS_SEL = SPRD_PIN_INFO(32, GLOBAL_CTRL_PIN, 15, 3, 6),
	SHARKL5_IIC_INF4_SYS_SEL = SPRD_PIN_INFO(33, GLOBAL_CTRL_PIN, 12, 3, 6),
	SHARKL5_IIC_INF3_SYS_SEL = SPRD_PIN_INFO(34, GLOBAL_CTRL_PIN, 9, 3, 6),
	SHARKL5_IIC_INF2_SYS_SEL = SPRD_PIN_INFO(35, GLOBAL_CTRL_PIN, 6, 3, 6),
	SHARKL5_IIC_INF1_SYS_SEL = SPRD_PIN_INFO(36, GLOBAL_CTRL_PIN, 3, 3, 6),
	SHARKL5_IIC_INF0_SYS_SEL = SPRD_PIN_INFO(37, GLOBAL_CTRL_PIN, 0, 3, 6),

	/* PIN_CTRL_REG0 */
	SHARKL5_PIN_CTRL_REG0 = SPRD_PIN_INFO(38, GLOBAL_CTRL_PIN, 0, 1, 7),

	/* PIN_CTRL_REG1 */
	SHARKL5_PIN_CTRL_REG1 = SPRD_PIN_INFO(39, GLOBAL_CTRL_PIN, 28, 4, 8),

	/* PIN_CTRL_REG2 */
	SHARKL5_UART_USB_PHY_SEL = SPRD_PIN_INFO(40, GLOBAL_CTRL_PIN, 31, 1, 9),
	SHARKL5_USB_PHY_DM_OE = SPRD_PIN_INFO(41, GLOBAL_CTRL_PIN, 30, 1, 9),
	SHARKL5_USB_PHY_DP_OE = SPRD_PIN_INFO(42, GLOBAL_CTRL_PIN, 29, 1, 9),

	/* PIN_CTRL_REG3 */
	SHARKL5_SP_EIC_DPAD3 = SPRD_PIN_INFO(43, GLOBAL_CTRL_PIN, 24, 8, 10),
	SHARKL5_SP_EIC_DPAD2 = SPRD_PIN_INFO(44, GLOBAL_CTRL_PIN, 16, 8, 10),
	SHARKL5_SP_EIC_DPAD1 = SPRD_PIN_INFO(45, GLOBAL_CTRL_PIN, 8, 8, 10),
	SHARKL5_SP_EIC_DPAD0 = SPRD_PIN_INFO(46, GLOBAL_CTRL_PIN, 0, 8, 10),

	/* PIN_CTRL_REG4 */
	SHARKL5_SP_EIC_DPAD7 = SPRD_PIN_INFO(47, GLOBAL_CTRL_PIN, 24, 8, 11),
	SHARKL5_SP_EIC_DPAD6 = SPRD_PIN_INFO(48, GLOBAL_CTRL_PIN, 16, 8, 11),
	SHARKL5_SP_EIC_DPAD5 = SPRD_PIN_INFO(49, GLOBAL_CTRL_PIN, 8, 8, 11),
	SHARKL5_SP_EIC_DPAD4 = SPRD_PIN_INFO(50, GLOBAL_CTRL_PIN, 0, 8, 11),

	/* PIN_CTRL_REG5 */
	SHARKL5_VBC_IIS_INF_SYS_SEL = SPRD_PIN_INFO(51, GLOBAL_CTRL_PIN, 20, 1, 12),
	SHARKL5_CARD_DET_SEL = SPRD_PIN_INFO(52, GLOBAL_CTRL_PIN, 17, 3, 12),
	SHARKL5_SIM0_DET_SEL = SPRD_PIN_INFO(53, GLOBAL_CTRL_PIN, 16, 1, 12),
	SHARKL5_AP_SIM0_BD_EB = SPRD_PIN_INFO(54, GLOBAL_CTRL_PIN, 15, 1, 12),
	SHARKL5_AP_EMMC_BD_EB = SPRD_PIN_INFO(55, GLOBAL_CTRL_PIN, 14, 1, 12),
	SHARKL5_AP_SDIO2_BD_EB = SPRD_PIN_INFO(56, GLOBAL_CTRL_PIN, 13, 1, 12),
	SHARKL5_AP_SDIO1_BD_EB = SPRD_PIN_INFO(57, GLOBAL_CTRL_PIN, 12, 1, 12),
	SHARKL5_AP_SDIO0_BD_EB = SPRD_PIN_INFO(58, GLOBAL_CTRL_PIN, 11, 1, 12),
	SHARKL5_PUBCP_SDIO_BD_EB = SPRD_PIN_INFO(59, GLOBAL_CTRL_PIN, 10, 1, 12),
	SHARKL5_PUBCP_SIM1_BD_EB = SPRD_PIN_INFO(60, GLOBAL_CTRL_PIN, 9, 1, 12),
	SHARKL5_PUBCP_SIM0_BD_EB = SPRD_PIN_INFO(61, GLOBAL_CTRL_PIN, 8, 1, 12),

	/* Common pin registers definitions */
	SHARKL5_EMMC_RST = SPRD_PIN_INFO(62, COMMON_PIN, 0, 0, 0),
	SHARKL5_EMMC_CMD = SPRD_PIN_INFO(63, COMMON_PIN, 0, 0, 0),
	SHARKL5_EMMC_D0 = SPRD_PIN_INFO(64, COMMON_PIN, 0, 0, 0),
	SHARKL5_EMMC_D3 = SPRD_PIN_INFO(65, COMMON_PIN, 0, 0, 0),
	SHARKL5_EMMC_D2 = SPRD_PIN_INFO(66, COMMON_PIN, 0, 0, 0),
	SHARKL5_EMMC_D5 = SPRD_PIN_INFO(67, COMMON_PIN, 0, 0, 0),
	SHARKL5_EMMC_CLK = SPRD_PIN_INFO(68, COMMON_PIN, 0, 0, 0),
	SHARKL5_EMMC_DS = SPRD_PIN_INFO(69, COMMON_PIN, 0, 0, 0),
	SHARKL5_EMMC_D1 = SPRD_PIN_INFO(70, COMMON_PIN, 0, 0, 0),
	SHARKL5_EMMC_D4 = SPRD_PIN_INFO(71, COMMON_PIN, 0, 0, 0),
	SHARKL5_EMMC_D6 = SPRD_PIN_INFO(72, COMMON_PIN, 0, 0, 0),
	SHARKL5_EMMC_D7 = SPRD_PIN_INFO(73, COMMON_PIN, 0, 0, 0),
	SHARKL5_LCM_RSTN = SPRD_PIN_INFO(74, COMMON_PIN, 0, 0, 0),
	SHARKL5_DSI_TE = SPRD_PIN_INFO(75, COMMON_PIN, 0, 0, 0),
	SHARKL5_DCDC_ARM1_EN = SPRD_PIN_INFO(76, COMMON_PIN, 0, 0, 0),
	SHARKL5_PTEST = SPRD_PIN_INFO(77, COMMON_PIN, 0, 0, 0),
	SHARKL5_EXT_RST_B = SPRD_PIN_INFO(78, COMMON_PIN, 0, 0, 0),
	SHARKL5_ADI_SCLK = SPRD_PIN_INFO(79, COMMON_PIN, 0, 0, 0),
	SHARKL5_CLK_32K = SPRD_PIN_INFO(80, COMMON_PIN, 0, 0, 0),
	SHARKL5_ANA_INT = SPRD_PIN_INFO(81, COMMON_PIN, 0, 0, 0),
	SHARKL5_ADI_D = SPRD_PIN_INFO(82, COMMON_PIN, 0, 0, 0),
	SHARKL5_AUD_SCLK = SPRD_PIN_INFO(83, COMMON_PIN, 0, 0, 0),
	SHARKL5_DCDC_ARM0_EN = SPRD_PIN_INFO(84, COMMON_PIN, 0, 0, 0),
	SHARKL5_AUD_ADD0 = SPRD_PIN_INFO(85, COMMON_PIN, 0, 0, 0),
	SHARKL5_XTL_EN0 = SPRD_PIN_INFO(86, COMMON_PIN, 0, 0, 0),
	SHARKL5_AUD_ADSYNC = SPRD_PIN_INFO(87, COMMON_PIN, 0, 0, 0),
	SHARKL5_AUD_DAD0 = SPRD_PIN_INFO(88, COMMON_PIN, 0, 0, 0),
	SHARKL5_XTL_EN1 = SPRD_PIN_INFO(89, COMMON_PIN, 0, 0, 0),
	SHARKL5_AUD_DASYNC = SPRD_PIN_INFO(90, COMMON_PIN, 0, 0, 0),
	SHARKL5_AUD_DAD1 = SPRD_PIN_INFO(91, COMMON_PIN, 0, 0, 0),
	SHARKL5_CHIP_SLEEP = SPRD_PIN_INFO(92, COMMON_PIN, 0, 0, 0),
	SHARKL5_SIMCLK2 = SPRD_PIN_INFO(93, COMMON_PIN, 0, 0, 0),
	SHARKL5_SIMDA2 = SPRD_PIN_INFO(94, COMMON_PIN, 0, 0, 0),
	SHARKL5_SIMRST2 = SPRD_PIN_INFO(95, COMMON_PIN, 0, 0, 0),
	SHARKL5_SD0_CMD = SPRD_PIN_INFO(96, COMMON_PIN, 0, 0, 0),
	SHARKL5_SD0_D0 = SPRD_PIN_INFO(97, COMMON_PIN, 0, 0, 0),
	SHARKL5_SD0_D1 = SPRD_PIN_INFO(98, COMMON_PIN, 0, 0, 0),
	SHARKL5_SD0_CLK = SPRD_PIN_INFO(99, COMMON_PIN, 0, 0, 0),
	SHARKL5_SD0_D2 = SPRD_PIN_INFO(100, COMMON_PIN, 0, 0, 0),
	SHARKL5_SD0_D3 = SPRD_PIN_INFO(101, COMMON_PIN, 0, 0, 0),
	SHARKL5_SIMCLK0 = SPRD_PIN_INFO(102, COMMON_PIN, 0, 0, 0),
	SHARKL5_SIMDA0 = SPRD_PIN_INFO(103, COMMON_PIN, 0, 0, 0),
	SHARKL5_SIMRST0 = SPRD_PIN_INFO(104, COMMON_PIN, 0, 0, 0),
	SHARKL5_SIMCLK1 = SPRD_PIN_INFO(105, COMMON_PIN, 0, 0, 0),
	SHARKL5_SIMDA1 = SPRD_PIN_INFO(106, COMMON_PIN, 0, 0, 0),
	SHARKL5_SIMRST1 = SPRD_PIN_INFO(107, COMMON_PIN, 0, 0, 0),
	SHARKL5_SD2_CMD = SPRD_PIN_INFO(108, COMMON_PIN, 0, 0, 0),
	SHARKL5_SD2_D0 = SPRD_PIN_INFO(109, COMMON_PIN, 0, 0, 0),
	SHARKL5_SD2_D1 = SPRD_PIN_INFO(110, COMMON_PIN, 0, 0, 0),
	SHARKL5_SD2_CLK = SPRD_PIN_INFO(111, COMMON_PIN, 0, 0, 0),
	SHARKL5_SD2_D2 = SPRD_PIN_INFO(112, COMMON_PIN, 0, 0, 0),
	SHARKL5_SD2_D3 = SPRD_PIN_INFO(113, COMMON_PIN, 0, 0, 0),
	SHARKL5_RFCTL0 = SPRD_PIN_INFO(114, COMMON_PIN, 0, 0, 0),
	SHARKL5_RFCTL1 = SPRD_PIN_INFO(115, COMMON_PIN, 0, 0, 0),
	SHARKL5_RFCTL2 = SPRD_PIN_INFO(116, COMMON_PIN, 0, 0, 0),
	SHARKL5_RFCTL3 = SPRD_PIN_INFO(117, COMMON_PIN, 0, 0, 0),
	SHARKL5_RFCTL4 = SPRD_PIN_INFO(118, COMMON_PIN, 0, 0, 0),
	SHARKL5_RFCTL5 = SPRD_PIN_INFO(119, COMMON_PIN, 0, 0, 0),
	SHARKL5_RFCTL6 = SPRD_PIN_INFO(120, COMMON_PIN, 0, 0, 0),
	SHARKL5_RFCTL7 = SPRD_PIN_INFO(121, COMMON_PIN, 0, 0, 0),
	SHARKL5_RFCTL8 = SPRD_PIN_INFO(122, COMMON_PIN, 0, 0, 0),
	SHARKL5_RFCTL9 = SPRD_PIN_INFO(123, COMMON_PIN, 0, 0, 0),
	SHARKL5_RFCTL10 = SPRD_PIN_INFO(124, COMMON_PIN, 0, 0, 0),
	SHARKL5_RFCTL11 = SPRD_PIN_INFO(125, COMMON_PIN, 0, 0, 0),
	SHARKL5_GPIO31 = SPRD_PIN_INFO(126, COMMON_PIN, 0, 0, 0),
	SHARKL5_GPIO32 = SPRD_PIN_INFO(127, COMMON_PIN, 0, 0, 0),
	SHARKL5_GPIO33 = SPRD_PIN_INFO(128, COMMON_PIN, 0, 0, 0),
	SHARKL5_RFCTL16 = SPRD_PIN_INFO(129, COMMON_PIN, 0, 0, 0),
	SHARKL5_RFCTL17 = SPRD_PIN_INFO(130, COMMON_PIN, 0, 0, 0),
	SHARKL5_GPIO9 = SPRD_PIN_INFO(131, COMMON_PIN, 0, 0, 0),
	SHARKL5_RFCTL19 = SPRD_PIN_INFO(132, COMMON_PIN, 0, 0, 0),
	SHARKL5_RFCTL20 = SPRD_PIN_INFO(133, COMMON_PIN, 0, 0, 0),
	SHARKL5_RFSCK0 = SPRD_PIN_INFO(134, COMMON_PIN, 0, 0, 0),
	SHARKL5_RFSDA0 = SPRD_PIN_INFO(135, COMMON_PIN, 0, 0, 0),
	SHARKL5_RFSEN0 = SPRD_PIN_INFO(136, COMMON_PIN, 0, 0, 0),
	SHARKL5_RFSCK1 = SPRD_PIN_INFO(137, COMMON_PIN, 0, 0, 0),
	SHARKL5_RFSDA1 = SPRD_PIN_INFO(138, COMMON_PIN, 0, 0, 0),
	SHARKL5_RFSEN1 = SPRD_PIN_INFO(139, COMMON_PIN, 0, 0, 0),
	SHARKL5_RFFE0_SCK = SPRD_PIN_INFO(140, COMMON_PIN, 0, 0, 0),
	SHARKL5_RFFE0_SDA = SPRD_PIN_INFO(141, COMMON_PIN, 0, 0, 0),
	SHARKL5_RFFE1_SCK = SPRD_PIN_INFO(142, COMMON_PIN, 0, 0, 0),
	SHARKL5_RFFE1_SDA = SPRD_PIN_INFO(143, COMMON_PIN, 0, 0, 0),
	SHARKL5_U1TXD = SPRD_PIN_INFO(144, COMMON_PIN, 0, 0, 0),
	SHARKL5_U1RXD = SPRD_PIN_INFO(145, COMMON_PIN, 0, 0, 0),
	SHARKL5_SCL6 = SPRD_PIN_INFO(146, COMMON_PIN, 0, 0, 0),
	SHARKL5_SDA6 = SPRD_PIN_INFO(147, COMMON_PIN, 0, 0, 0),
	SHARKL5_MTCK_ARM = SPRD_PIN_INFO(148, COMMON_PIN, 0, 0, 0),
	SHARKL5_MTMS_ARM = SPRD_PIN_INFO(149, COMMON_PIN, 0, 0, 0),
	SHARKL5_PWMC = SPRD_PIN_INFO(150, COMMON_PIN, 0, 0, 0),
	SHARKL5_KEYOUT0 = SPRD_PIN_INFO(151, COMMON_PIN, 0, 0, 0),
	SHARKL5_KEYOUT1 = SPRD_PIN_INFO(152, COMMON_PIN, 0, 0, 0),
	SHARKL5_KEYOUT2 = SPRD_PIN_INFO(153, COMMON_PIN, 0, 0, 0),
	SHARKL5_KEYIN0 = SPRD_PIN_INFO(154, COMMON_PIN, 0, 0, 0),
	SHARKL5_KEYIN1 = SPRD_PIN_INFO(155, COMMON_PIN, 0, 0, 0),
	SHARKL5_KEYIN2 = SPRD_PIN_INFO(156, COMMON_PIN, 0, 0, 0),
	SHARKL5_SCL0 = SPRD_PIN_INFO(157, COMMON_PIN, 0, 0, 0),
	SHARKL5_SDA0 = SPRD_PIN_INFO(158, COMMON_PIN, 0, 0, 0),
	SHARKL5_SDA1 = SPRD_PIN_INFO(159, COMMON_PIN, 0, 0, 0),
	SHARKL5_SCL1 = SPRD_PIN_INFO(160, COMMON_PIN, 0, 0, 0),
	SHARKL5_CMMCLK0 = SPRD_PIN_INFO(161, COMMON_PIN, 0, 0, 0),
	SHARKL5_CMMCLK1 = SPRD_PIN_INFO(162, COMMON_PIN, 0, 0, 0),
	SHARKL5_CMRST0 = SPRD_PIN_INFO(163, COMMON_PIN, 0, 0, 0),
	SHARKL5_CMRST1 = SPRD_PIN_INFO(164, COMMON_PIN, 0, 0, 0),
	SHARKL5_CMPD0 = SPRD_PIN_INFO(165, COMMON_PIN, 0, 0, 0),
	SHARKL5_CMPD1 = SPRD_PIN_INFO(166, COMMON_PIN, 0, 0, 0),
	SHARKL5_CMMCLK2 = SPRD_PIN_INFO(167, COMMON_PIN, 0, 0, 0),
	SHARKL5_CMPD2 = SPRD_PIN_INFO(168, COMMON_PIN, 0, 0, 0),
	SHARKL5_CMRST2 = SPRD_PIN_INFO(169, COMMON_PIN, 0, 0, 0),
	SHARKL5_SPI0_CSN = SPRD_PIN_INFO(170, COMMON_PIN, 0, 0, 0),
	SHARKL5_SPI0_DO = SPRD_PIN_INFO(171, COMMON_PIN, 0, 0, 0),
	SHARKL5_SPI0_DI = SPRD_PIN_INFO(172, COMMON_PIN, 0, 0, 0),
	SHARKL5_SPI0_CLK = SPRD_PIN_INFO(173, COMMON_PIN, 0, 0, 0),
	SHARKL5_EXTINT9 = SPRD_PIN_INFO(174, COMMON_PIN, 0, 0, 0),
	SHARKL5_EXTINT10 = SPRD_PIN_INFO(175, COMMON_PIN, 0, 0, 0),
	SHARKL5_IIS1DI = SPRD_PIN_INFO(176, COMMON_PIN, 0, 0, 0),
	SHARKL5_IIS1DO = SPRD_PIN_INFO(177, COMMON_PIN, 0, 0, 0),
	SHARKL5_IIS1CLK = SPRD_PIN_INFO(178, COMMON_PIN, 0, 0, 0),
	SHARKL5_IIS1LRCK = SPRD_PIN_INFO(179, COMMON_PIN, 0, 0, 0),
	SHARKL5_SCL2 = SPRD_PIN_INFO(180, COMMON_PIN, 0, 0, 0),
	SHARKL5_SDA2 = SPRD_PIN_INFO(181, COMMON_PIN, 0, 0, 0),
	SHARKL5_MEMS_MIC_CLK0 = SPRD_PIN_INFO(182, COMMON_PIN, 0, 0, 0),
	SHARKL5_MEMS_MIC_DATA0 = SPRD_PIN_INFO(183, COMMON_PIN, 0, 0, 0),
	SHARKL5_MEMS_MIC_CLK1 = SPRD_PIN_INFO(184, COMMON_PIN, 0, 0, 0),
	SHARKL5_MEMS_MIC_DATA1 = SPRD_PIN_INFO(185, COMMON_PIN, 0, 0, 0),
	SHARKL5_SPI2_CSN = SPRD_PIN_INFO(186, COMMON_PIN, 0, 0, 0),
	SHARKL5_SPI2_DO = SPRD_PIN_INFO(187, COMMON_PIN, 0, 0, 0),
	SHARKL5_SPI2_DI = SPRD_PIN_INFO(188, COMMON_PIN, 0, 0, 0),
	SHARKL5_SPI2_CLK = SPRD_PIN_INFO(189, COMMON_PIN, 0, 0, 0),
	SHARKL5_IIS0DI = SPRD_PIN_INFO(190, COMMON_PIN, 0, 0, 0),
	SHARKL5_IIS0DO = SPRD_PIN_INFO(191, COMMON_PIN, 0, 0, 0),
	SHARKL5_IIS0CLK = SPRD_PIN_INFO(192, COMMON_PIN, 0, 0, 0),
	SHARKL5_IIS0LRCK = SPRD_PIN_INFO(193, COMMON_PIN, 0, 0, 0),
	SHARKL5_U5TXD = SPRD_PIN_INFO(194, COMMON_PIN, 0, 0, 0),
	SHARKL5_U5RXD = SPRD_PIN_INFO(195, COMMON_PIN, 0, 0, 0),
	SHARKL5_CLK_AUX0 = SPRD_PIN_INFO(196, COMMON_PIN, 0, 0, 0),
	SHARKL5_U0TXD = SPRD_PIN_INFO(197, COMMON_PIN, 0, 0, 0),
	SHARKL5_U0RXD = SPRD_PIN_INFO(198, COMMON_PIN, 0, 0, 0),
	SHARKL5_U0CTS = SPRD_PIN_INFO(199, COMMON_PIN, 0, 0, 0),
	SHARKL5_U0RTS = SPRD_PIN_INFO(200, COMMON_PIN, 0, 0, 0),
	SHARKL5_U4TXD = SPRD_PIN_INFO(201, COMMON_PIN, 0, 0, 0),
	SHARKL5_U4RXD = SPRD_PIN_INFO(202, COMMON_PIN, 0, 0, 0),
	SHARKL5_U4CTS = SPRD_PIN_INFO(203, COMMON_PIN, 0, 0, 0),
	SHARKL5_U4RTS = SPRD_PIN_INFO(204, COMMON_PIN, 0, 0, 0),
	SHARKL5_SD1_CMD = SPRD_PIN_INFO(205, COMMON_PIN, 0, 0, 0),
	SHARKL5_SD1_D0 = SPRD_PIN_INFO(206, COMMON_PIN, 0, 0, 0),
	SHARKL5_SD1_D1 = SPRD_PIN_INFO(207, COMMON_PIN, 0, 0, 0),
	SHARKL5_SD1_CLK = SPRD_PIN_INFO(208, COMMON_PIN, 0, 0, 0),
	SHARKL5_SD1_D2 = SPRD_PIN_INFO(209, COMMON_PIN, 0, 0, 0),
	SHARKL5_SD1_D3 = SPRD_PIN_INFO(210, COMMON_PIN, 0, 0, 0),
	SHARKL5_EXTINT0 = SPRD_PIN_INFO(211, COMMON_PIN, 0, 0, 0),
	SHARKL5_EXTINT1 = SPRD_PIN_INFO(212, COMMON_PIN, 0, 0, 0),
	SHARKL5_SDA3 = SPRD_PIN_INFO(213, COMMON_PIN, 0, 0, 0),
	SHARKL5_SCL3 = SPRD_PIN_INFO(214, COMMON_PIN, 0, 0, 0),

	/* MSIC pin registers definitions */
	SHARKL5_EMMC_RST_MISC = SPRD_PIN_INFO(215, MISC_PIN, 0, 0, 0),
	SHARKL5_EMMC_CMD_MISC = SPRD_PIN_INFO(216, MISC_PIN, 0, 0, 0),
	SHARKL5_EMMC_D0_MISC = SPRD_PIN_INFO(217, MISC_PIN, 0, 0, 0),
	SHARKL5_EMMC_D3_MISC = SPRD_PIN_INFO(218, MISC_PIN, 0, 0, 0),
	SHARKL5_EMMC_D2_MISC = SPRD_PIN_INFO(219, MISC_PIN, 0, 0, 0),
	SHARKL5_EMMC_D5_MISC = SPRD_PIN_INFO(220, MISC_PIN, 0, 0, 0),
	SHARKL5_EMMC_CLK_MISC = SPRD_PIN_INFO(221, MISC_PIN, 0, 0, 0),
	SHARKL5_EMMC_DS_MISC = SPRD_PIN_INFO(222, MISC_PIN, 0, 0, 0),
	SHARKL5_EMMC_D1_MISC = SPRD_PIN_INFO(223, MISC_PIN, 0, 0, 0),
	SHARKL5_EMMC_D4_MISC = SPRD_PIN_INFO(224, MISC_PIN, 0, 0, 0),
	SHARKL5_EMMC_D6_MISC = SPRD_PIN_INFO(225, MISC_PIN, 0, 0, 0),
	SHARKL5_EMMC_D7_MISC = SPRD_PIN_INFO(226, MISC_PIN, 0, 0, 0),
	SHARKL5_LCM_RSTN_MISC = SPRD_PIN_INFO(227, MISC_PIN, 0, 0, 0),
	SHARKL5_DSI_TE_MISC = SPRD_PIN_INFO(228, MISC_PIN, 0, 0, 0),
	SHARKL5_DCDC_ARM1_EN_MISC = SPRD_PIN_INFO(229, MISC_PIN, 0, 0, 0),
	SHARKL5_PTEST_MISC = SPRD_PIN_INFO(230, MISC_PIN, 0, 0, 0),
	SHARKL5_EXT_RST_B_MISC = SPRD_PIN_INFO(231, MISC_PIN, 0, 0, 0),
	SHARKL5_ADI_SCLK_MISC = SPRD_PIN_INFO(232, MISC_PIN, 0, 0, 0),
	SHARKL5_CLK_32K_MISC = SPRD_PIN_INFO(233, MISC_PIN, 0, 0, 0),
	SHARKL5_ANA_INT_MISC = SPRD_PIN_INFO(234, MISC_PIN, 0, 0, 0),
	SHARKL5_ADI_D_MISC = SPRD_PIN_INFO(235, MISC_PIN, 0, 0, 0),
	SHARKL5_AUD_SCLK_MISC = SPRD_PIN_INFO(236, MISC_PIN, 0, 0, 0),
	SHARKL5_DCDC_ARM0_EN_MISC = SPRD_PIN_INFO(237, MISC_PIN, 0, 0, 0),
	SHARKL5_AUD_ADD0_MISC = SPRD_PIN_INFO(238, MISC_PIN, 0, 0, 0),
	SHARKL5_XTL_EN0_MISC = SPRD_PIN_INFO(239, MISC_PIN, 0, 0, 0),
	SHARKL5_AUD_ADSYNC_MISC = SPRD_PIN_INFO(240, MISC_PIN, 0, 0, 0),
	SHARKL5_AUD_DAD0_MISC = SPRD_PIN_INFO(241, MISC_PIN, 0, 0, 0),
	SHARKL5_XTL_EN1_MISC = SPRD_PIN_INFO(242, MISC_PIN, 0, 0, 0),
	SHARKL5_AUD_DASYNC_MISC = SPRD_PIN_INFO(243, MISC_PIN, 0, 0, 0),
	SHARKL5_AUD_DAD1_MISC = SPRD_PIN_INFO(244, MISC_PIN, 0, 0, 0),
	SHARKL5_CHIP_SLEEP_MISC = SPRD_PIN_INFO(245, MISC_PIN, 0, 0, 0),
	SHARKL5_SIMCLK2_MISC = SPRD_PIN_INFO(246, MISC_PIN, 0, 0, 0),
	SHARKL5_SIMDA2_MISC = SPRD_PIN_INFO(247, MISC_PIN, 0, 0, 0),
	SHARKL5_SIMRST2_MISC = SPRD_PIN_INFO(248, MISC_PIN, 0, 0, 0),
	SHARKL5_SD0_CMD_MISC = SPRD_PIN_INFO(249, MISC_PIN, 0, 0, 0),
	SHARKL5_SD0_D0_MISC = SPRD_PIN_INFO(250, MISC_PIN, 0, 0, 0),
	SHARKL5_SD0_D1_MISC = SPRD_PIN_INFO(251, MISC_PIN, 0, 0, 0),
	SHARKL5_SD0_CLK_MISC = SPRD_PIN_INFO(252, MISC_PIN, 0, 0, 0),
	SHARKL5_SD0_D2_MISC = SPRD_PIN_INFO(253, MISC_PIN, 0, 0, 0),
	SHARKL5_SD0_D3_MISC = SPRD_PIN_INFO(254, MISC_PIN, 0, 0, 0),
	SHARKL5_SIMCLK0_MISC = SPRD_PIN_INFO(255, MISC_PIN, 0, 0, 0),
	SHARKL5_SIMDA0_MISC = SPRD_PIN_INFO(256, MISC_PIN, 0, 0, 0),
	SHARKL5_SIMRST0_MISC = SPRD_PIN_INFO(257, MISC_PIN, 0, 0, 0),
	SHARKL5_SIMCLK1_MISC = SPRD_PIN_INFO(258, MISC_PIN, 0, 0, 0),
	SHARKL5_SIMDA1_MISC = SPRD_PIN_INFO(259, MISC_PIN, 0, 0, 0),
	SHARKL5_SIMRST1_MISC = SPRD_PIN_INFO(260, MISC_PIN, 0, 0, 0),
	SHARKL5_SD2_CMD_MISC = SPRD_PIN_INFO(261, MISC_PIN, 0, 0, 0),
	SHARKL5_SD2_D0_MISC = SPRD_PIN_INFO(262, MISC_PIN, 0, 0, 0),
	SHARKL5_SD2_D1_MISC = SPRD_PIN_INFO(263, MISC_PIN, 0, 0, 0),
	SHARKL5_SD2_CLK_MISC = SPRD_PIN_INFO(264, MISC_PIN, 0, 0, 0),
	SHARKL5_SD2_D2_MISC = SPRD_PIN_INFO(265, MISC_PIN, 0, 0, 0),
	SHARKL5_SD2_D3_MISC = SPRD_PIN_INFO(266, MISC_PIN, 0, 0, 0),
	SHARKL5_RFCTL0_MISC = SPRD_PIN_INFO(267, MISC_PIN, 0, 0, 0),
	SHARKL5_RFCTL1_MISC = SPRD_PIN_INFO(268, MISC_PIN, 0, 0, 0),
	SHARKL5_RFCTL2_MISC = SPRD_PIN_INFO(269, MISC_PIN, 0, 0, 0),
	SHARKL5_RFCTL3_MISC = SPRD_PIN_INFO(270, MISC_PIN, 0, 0, 0),
	SHARKL5_RFCTL4_MISC = SPRD_PIN_INFO(271, MISC_PIN, 0, 0, 0),
	SHARKL5_RFCTL5_MISC = SPRD_PIN_INFO(272, MISC_PIN, 0, 0, 0),
	SHARKL5_RFCTL6_MISC = SPRD_PIN_INFO(273, MISC_PIN, 0, 0, 0),
	SHARKL5_RFCTL7_MISC = SPRD_PIN_INFO(274, MISC_PIN, 0, 0, 0),
	SHARKL5_RFCTL8_MISC = SPRD_PIN_INFO(275, MISC_PIN, 0, 0, 0),
	SHARKL5_RFCTL9_MISC = SPRD_PIN_INFO(276, MISC_PIN, 0, 0, 0),
	SHARKL5_RFCTL10_MISC = SPRD_PIN_INFO(277, MISC_PIN, 0, 0, 0),
	SHARKL5_RFCTL11_MISC = SPRD_PIN_INFO(278, MISC_PIN, 0, 0, 0),
	SHARKL5_GPIO31_MISC = SPRD_PIN_INFO(279, MISC_PIN, 0, 0, 0),
	SHARKL5_GPIO32_MISC = SPRD_PIN_INFO(280, MISC_PIN, 0, 0, 0),
	SHARKL5_GPIO33_MISC = SPRD_PIN_INFO(281, MISC_PIN, 0, 0, 0),
	SHARKL5_RFCTL16_MISC = SPRD_PIN_INFO(282, MISC_PIN, 0, 0, 0),
	SHARKL5_RFCTL17_MISC = SPRD_PIN_INFO(283, MISC_PIN, 0, 0, 0),
	SHARKL5_GPIO9_MISC = SPRD_PIN_INFO(284, MISC_PIN, 0, 0, 0),
	SHARKL5_RFCTL19_MISC = SPRD_PIN_INFO(285, MISC_PIN, 0, 0, 0),
	SHARKL5_RFCTL20_MISC = SPRD_PIN_INFO(286, MISC_PIN, 0, 0, 0),
	SHARKL5_RFSCK0_MISC = SPRD_PIN_INFO(287, MISC_PIN, 0, 0, 0),
	SHARKL5_RFSDA0_MISC = SPRD_PIN_INFO(288, MISC_PIN, 0, 0, 0),
	SHARKL5_RFSEN0_MISC = SPRD_PIN_INFO(289, MISC_PIN, 0, 0, 0),
	SHARKL5_RFSCK1_MISC = SPRD_PIN_INFO(290, MISC_PIN, 0, 0, 0),
	SHARKL5_RFSDA1_MISC = SPRD_PIN_INFO(291, MISC_PIN, 0, 0, 0),
	SHARKL5_RFSEN1_MISC = SPRD_PIN_INFO(292, MISC_PIN, 0, 0, 0),
	SHARKL5_RFFE0_SCK_MISC = SPRD_PIN_INFO(293, MISC_PIN, 0, 0, 0),
	SHARKL5_RFFE0_SDA_MISC = SPRD_PIN_INFO(294, MISC_PIN, 0, 0, 0),
	SHARKL5_RFFE1_SCK_MISC = SPRD_PIN_INFO(295, MISC_PIN, 0, 0, 0),
	SHARKL5_RFFE1_SDA_MISC = SPRD_PIN_INFO(296, MISC_PIN, 0, 0, 0),
	SHARKL5_U1TXD_MISC = SPRD_PIN_INFO(297, MISC_PIN, 0, 0, 0),
	SHARKL5_U1RXD_MISC = SPRD_PIN_INFO(298, MISC_PIN, 0, 0, 0),
	SHARKL5_SCL6_MISC = SPRD_PIN_INFO(299, MISC_PIN, 0, 0, 0),
	SHARKL5_SDA6_MISC = SPRD_PIN_INFO(300, MISC_PIN, 0, 0, 0),
	SHARKL5_MTCK_ARM_MISC = SPRD_PIN_INFO(301, MISC_PIN, 0, 0, 0),
	SHARKL5_MTMS_ARM_MISC = SPRD_PIN_INFO(302, MISC_PIN, 0, 0, 0),
	SHARKL5_PWMC_MISC = SPRD_PIN_INFO(303, MISC_PIN, 0, 0, 0),
	SHARKL5_KEYOUT0_MISC = SPRD_PIN_INFO(304, MISC_PIN, 0, 0, 0),
	SHARKL5_KEYOUT1_MISC = SPRD_PIN_INFO(305, MISC_PIN, 0, 0, 0),
	SHARKL5_KEYOUT2_MISC = SPRD_PIN_INFO(306, MISC_PIN, 0, 0, 0),
	SHARKL5_KEYIN0_MISC = SPRD_PIN_INFO(307, MISC_PIN, 0, 0, 0),
	SHARKL5_KEYIN1_MISC = SPRD_PIN_INFO(308, MISC_PIN, 0, 0, 0),
	SHARKL5_KEYIN2_MISC = SPRD_PIN_INFO(309, MISC_PIN, 0, 0, 0),
	SHARKL5_SCL0_MISC = SPRD_PIN_INFO(310, MISC_PIN, 0, 0, 0),
	SHARKL5_SDA0_MISC = SPRD_PIN_INFO(311, MISC_PIN, 0, 0, 0),
	SHARKL5_SDA1_MISC = SPRD_PIN_INFO(312, MISC_PIN, 0, 0, 0),
	SHARKL5_SCL1_MISC = SPRD_PIN_INFO(313, MISC_PIN, 0, 0, 0),
	SHARKL5_CMMCLK0_MISC = SPRD_PIN_INFO(314, MISC_PIN, 0, 0, 0),
	SHARKL5_CMMCLK1_MISC = SPRD_PIN_INFO(315, MISC_PIN, 0, 0, 0),
	SHARKL5_CMRST0_MISC = SPRD_PIN_INFO(316, MISC_PIN, 0, 0, 0),
	SHARKL5_CMRST1_MISC = SPRD_PIN_INFO(317, MISC_PIN, 0, 0, 0),
	SHARKL5_CMPD0_MISC = SPRD_PIN_INFO(318, MISC_PIN, 0, 0, 0),
	SHARKL5_CMPD1_MISC = SPRD_PIN_INFO(319, MISC_PIN, 0, 0, 0),
	SHARKL5_CMMCLK2_MISC = SPRD_PIN_INFO(320, MISC_PIN, 0, 0, 0),
	SHARKL5_CMPD2_MISC = SPRD_PIN_INFO(321, MISC_PIN, 0, 0, 0),
	SHARKL5_CMRST2_MISC = SPRD_PIN_INFO(322, MISC_PIN, 0, 0, 0),
	SHARKL5_SPI0_CSN_MISC = SPRD_PIN_INFO(323, MISC_PIN, 0, 0, 0),
	SHARKL5_SPI0_DO_MISC = SPRD_PIN_INFO(324, MISC_PIN, 0, 0, 0),
	SHARKL5_SPI0_DI_MISC = SPRD_PIN_INFO(325, MISC_PIN, 0, 0, 0),
	SHARKL5_SPI0_CLK_MISC = SPRD_PIN_INFO(326, MISC_PIN, 0, 0, 0),
	SHARKL5_EXTINT9_MISC = SPRD_PIN_INFO(327, MISC_PIN, 0, 0, 0),
	SHARKL5_EXTINT10_MISC = SPRD_PIN_INFO(328, MISC_PIN, 0, 0, 0),
	SHARKL5_IIS1DI_MISC = SPRD_PIN_INFO(329, MISC_PIN, 0, 0, 0),
	SHARKL5_IIS1DO_MISC = SPRD_PIN_INFO(330, MISC_PIN, 0, 0, 0),
	SHARKL5_IIS1CLK_MISC = SPRD_PIN_INFO(331, MISC_PIN, 0, 0, 0),
	SHARKL5_IIS1LRCK_MISC = SPRD_PIN_INFO(332, MISC_PIN, 0, 0, 0),
	SHARKL5_SCL2_MISC = SPRD_PIN_INFO(333, MISC_PIN, 0, 0, 0),
	SHARKL5_SDA2_MISC = SPRD_PIN_INFO(334, MISC_PIN, 0, 0, 0),
	SHARKL5_MEMS_MIC_CLK0_MISC = SPRD_PIN_INFO(335, MISC_PIN, 0, 0, 0),
	SHARKL5_MEMS_MIC_DATA0_MISC = SPRD_PIN_INFO(336, MISC_PIN, 0, 0, 0),
	SHARKL5_MEMS_MIC_CLK1_MISC = SPRD_PIN_INFO(337, MISC_PIN, 0, 0, 0),
	SHARKL5_MEMS_MIC_DATA1_MISC = SPRD_PIN_INFO(338, MISC_PIN, 0, 0, 0),
	SHARKL5_SPI2_CSN_MISC = SPRD_PIN_INFO(339, MISC_PIN, 0, 0, 0),
	SHARKL5_SPI2_DO_MISC = SPRD_PIN_INFO(340, MISC_PIN, 0, 0, 0),
	SHARKL5_SPI2_DI_MISC = SPRD_PIN_INFO(341, MISC_PIN, 0, 0, 0),
	SHARKL5_SPI2_CLK_MISC = SPRD_PIN_INFO(342, MISC_PIN, 0, 0, 0),
	SHARKL5_IIS0DI_MISC = SPRD_PIN_INFO(343, MISC_PIN, 0, 0, 0),
	SHARKL5_IIS0DO_MISC = SPRD_PIN_INFO(344, MISC_PIN, 0, 0, 0),
	SHARKL5_IIS0CLK_MISC = SPRD_PIN_INFO(345, MISC_PIN, 0, 0, 0),
	SHARKL5_IIS0LRCK_MISC = SPRD_PIN_INFO(346, MISC_PIN, 0, 0, 0),
	SHARKL5_U5TXD_MISC = SPRD_PIN_INFO(347, MISC_PIN, 0, 0, 0),
	SHARKL5_U5RXD_MISC = SPRD_PIN_INFO(348, MISC_PIN, 0, 0, 0),
	SHARKL5_CLK_AUX0_MISC = SPRD_PIN_INFO(349, MISC_PIN, 0, 0, 0),
	SHARKL5_U0TXD_MISC = SPRD_PIN_INFO(350, MISC_PIN, 0, 0, 0),
	SHARKL5_U0RXD_MISC = SPRD_PIN_INFO(351, MISC_PIN, 0, 0, 0),
	SHARKL5_U0CTS_MISC = SPRD_PIN_INFO(352, MISC_PIN, 0, 0, 0),
	SHARKL5_U0RTS_MISC = SPRD_PIN_INFO(353, MISC_PIN, 0, 0, 0),
	SHARKL5_U4TXD_MISC = SPRD_PIN_INFO(354, MISC_PIN, 0, 0, 0),
	SHARKL5_U4RXD_MISC = SPRD_PIN_INFO(355, MISC_PIN, 0, 0, 0),
	SHARKL5_U4CTS_MISC = SPRD_PIN_INFO(356, MISC_PIN, 0, 0, 0),
	SHARKL5_U4RTS_MISC = SPRD_PIN_INFO(357, MISC_PIN, 0, 0, 0),
	SHARKL5_SD1_CMD_MISC = SPRD_PIN_INFO(358, MISC_PIN, 0, 0, 0),
	SHARKL5_SD1_D0_MISC = SPRD_PIN_INFO(359, MISC_PIN, 0, 0, 0),
	SHARKL5_SD1_D1_MISC = SPRD_PIN_INFO(360, MISC_PIN, 0, 0, 0),
	SHARKL5_SD1_CLK_MISC = SPRD_PIN_INFO(361, MISC_PIN, 0, 0, 0),
	SHARKL5_SD1_D2_MISC = SPRD_PIN_INFO(362, MISC_PIN, 0, 0, 0),
	SHARKL5_SD1_D3_MISC = SPRD_PIN_INFO(363, MISC_PIN, 0, 0, 0),
	SHARKL5_EXTINT0_MISC = SPRD_PIN_INFO(364, MISC_PIN, 0, 0, 0),
	SHARKL5_EXTINT1_MISC = SPRD_PIN_INFO(365, MISC_PIN, 0, 0, 0),
	SHARKL5_SDA3_MISC = SPRD_PIN_INFO(366, MISC_PIN, 0, 0, 0),
	SHARKL5_SCL3_MISC = SPRD_PIN_INFO(367, MISC_PIN, 0, 0, 0),
};

static struct sprd_pins_info sprd_sharkl5_pins_info[] = {
	SPRD_PINCTRL_PIN(SHARKL5_UART_INF6_SYS_SEL),
	SPRD_PINCTRL_PIN(SHARKL5_UART_INF5_SYS_SEL),
	SPRD_PINCTRL_PIN(SHARKL5_UART_INF4_SYS_SEL),
	SPRD_PINCTRL_PIN(SHARKL5_UART_INF3_SYS_SEL),
	SPRD_PINCTRL_PIN(SHARKL5_UART_INF2_INF3_LOOP),
	SPRD_PINCTRL_PIN(SHARKL5_UART_INF2_INF4_LOOP),
	SPRD_PINCTRL_PIN(SHARKL5_UART_INF2_SYS_SEL),
	SPRD_PINCTRL_PIN(SHARKL5_UART_INF1_INF4_LOOP),
	SPRD_PINCTRL_PIN(SHARKL5_UART_INF1_INF3_LOOP),
	SPRD_PINCTRL_PIN(SHARKL5_UART_INF1_SYS_SEL),
	SPRD_PINCTRL_PIN(SHARKL5_UART_INF0_SYS_SEL),

	SPRD_PINCTRL_PIN(SHARKL5_UART_INF9_SYS_SEL),
	SPRD_PINCTRL_PIN(SHARKL5_UART_INF8_SYS_SEL),
	SPRD_PINCTRL_PIN(SHARKL5_UART_INF7_INF8_LOOP),
	SPRD_PINCTRL_PIN(SHARKL5_UART_INF7_SYS_SEL),

	SPRD_PINCTRL_PIN(SHARKL5_IIS_INF4_INF3_LOOP),
	SPRD_PINCTRL_PIN(SHARKL5_IIS_INF4_SYS_SEL),
	SPRD_PINCTRL_PIN(SHARKL5_IIS_INF3_SYS_SEL),
	SPRD_PINCTRL_PIN(SHARKL5_IIS_INF2_SYS_SEL),
	SPRD_PINCTRL_PIN(SHARKL5_IIS_INF1_INF2_LOOP),
	SPRD_PINCTRL_PIN(SHARKL5_IIS_INF1_SYS_SEL),
	SPRD_PINCTRL_PIN(SHARKL5_IIS_INF0_INF2_LOOP),
	SPRD_PINCTRL_PIN(SHARKL5_IIS_INF0_INF1_LOOP),
	SPRD_PINCTRL_PIN(SHARKL5_IIS_INF0_SYS_SEL),

	SPRD_PINCTRL_PIN(SHARKL5_SIM_INF2_SYS_SEL),
	SPRD_PINCTRL_PIN(SHARKL5_SIM_INF1_SYS_SEL),
	SPRD_PINCTRL_PIN(SHARKL5_SIM_INFO_SYS_SEL),

	SPRD_PINCTRL_PIN(SHARKL5_SPI_INF3_SYS_SEL),
	SPRD_PINCTRL_PIN(SHARKL5_SPI_INF2_SYS_SEL),
	SPRD_PINCTRL_PIN(SHARKL5_SPI_INF1_SYS_SEL),
	SPRD_PINCTRL_PIN(SHARKL5_SPI_INF0_SYS_SEL),

	SPRD_PINCTRL_PIN(SHARKL5_IIC_INF6_SYS_SEL),
	SPRD_PINCTRL_PIN(SHARKL5_IIC_INF5_SYS_SEL),
	SPRD_PINCTRL_PIN(SHARKL5_IIC_INF4_SYS_SEL),
	SPRD_PINCTRL_PIN(SHARKL5_IIC_INF3_SYS_SEL),
	SPRD_PINCTRL_PIN(SHARKL5_IIC_INF2_SYS_SEL),
	SPRD_PINCTRL_PIN(SHARKL5_IIC_INF1_SYS_SEL),
	SPRD_PINCTRL_PIN(SHARKL5_IIC_INF0_SYS_SEL),

	SPRD_PINCTRL_PIN(SHARKL5_PIN_CTRL_REG0),

	SPRD_PINCTRL_PIN(SHARKL5_PIN_CTRL_REG1),

	SPRD_PINCTRL_PIN(SHARKL5_UART_USB_PHY_SEL),
	SPRD_PINCTRL_PIN(SHARKL5_USB_PHY_DM_OE),
	SPRD_PINCTRL_PIN(SHARKL5_USB_PHY_DP_OE),

	SPRD_PINCTRL_PIN(SHARKL5_SP_EIC_DPAD3),
	SPRD_PINCTRL_PIN(SHARKL5_SP_EIC_DPAD2),
	SPRD_PINCTRL_PIN(SHARKL5_SP_EIC_DPAD1),
	SPRD_PINCTRL_PIN(SHARKL5_SP_EIC_DPAD0),

	SPRD_PINCTRL_PIN(SHARKL5_SP_EIC_DPAD7),
	SPRD_PINCTRL_PIN(SHARKL5_SP_EIC_DPAD6),
	SPRD_PINCTRL_PIN(SHARKL5_SP_EIC_DPAD5),
	SPRD_PINCTRL_PIN(SHARKL5_SP_EIC_DPAD4),

	SPRD_PINCTRL_PIN(SHARKL5_VBC_IIS_INF_SYS_SEL),
	SPRD_PINCTRL_PIN(SHARKL5_CARD_DET_SEL),
	SPRD_PINCTRL_PIN(SHARKL5_SIM0_DET_SEL),
	SPRD_PINCTRL_PIN(SHARKL5_AP_SIM0_BD_EB),
	SPRD_PINCTRL_PIN(SHARKL5_AP_EMMC_BD_EB),
	SPRD_PINCTRL_PIN(SHARKL5_AP_SDIO2_BD_EB),
	SPRD_PINCTRL_PIN(SHARKL5_AP_SDIO1_BD_EB),
	SPRD_PINCTRL_PIN(SHARKL5_AP_SDIO0_BD_EB),
	SPRD_PINCTRL_PIN(SHARKL5_PUBCP_SDIO_BD_EB),
	SPRD_PINCTRL_PIN(SHARKL5_PUBCP_SIM1_BD_EB),
	SPRD_PINCTRL_PIN(SHARKL5_PUBCP_SIM0_BD_EB),

	SPRD_PINCTRL_PIN(SHARKL5_EMMC_RST),
	SPRD_PINCTRL_PIN(SHARKL5_EMMC_CMD),
	SPRD_PINCTRL_PIN(SHARKL5_EMMC_D0),
	SPRD_PINCTRL_PIN(SHARKL5_EMMC_D3),
	SPRD_PINCTRL_PIN(SHARKL5_EMMC_D2),
	SPRD_PINCTRL_PIN(SHARKL5_EMMC_D5),
	SPRD_PINCTRL_PIN(SHARKL5_EMMC_CLK),
	SPRD_PINCTRL_PIN(SHARKL5_EMMC_DS),
	SPRD_PINCTRL_PIN(SHARKL5_EMMC_D1),
	SPRD_PINCTRL_PIN(SHARKL5_EMMC_D4),
	SPRD_PINCTRL_PIN(SHARKL5_EMMC_D6),
	SPRD_PINCTRL_PIN(SHARKL5_EMMC_D7),
	SPRD_PINCTRL_PIN(SHARKL5_LCM_RSTN),
	SPRD_PINCTRL_PIN(SHARKL5_DSI_TE),
	SPRD_PINCTRL_PIN(SHARKL5_DCDC_ARM1_EN),
	SPRD_PINCTRL_PIN(SHARKL5_PTEST),
	SPRD_PINCTRL_PIN(SHARKL5_EXT_RST_B),
	SPRD_PINCTRL_PIN(SHARKL5_ADI_SCLK),
	SPRD_PINCTRL_PIN(SHARKL5_CLK_32K),
	SPRD_PINCTRL_PIN(SHARKL5_ANA_INT),
	SPRD_PINCTRL_PIN(SHARKL5_ADI_D),
	SPRD_PINCTRL_PIN(SHARKL5_AUD_SCLK),
	SPRD_PINCTRL_PIN(SHARKL5_DCDC_ARM0_EN),
	SPRD_PINCTRL_PIN(SHARKL5_AUD_ADD0),
	SPRD_PINCTRL_PIN(SHARKL5_XTL_EN0),
	SPRD_PINCTRL_PIN(SHARKL5_AUD_ADSYNC),
	SPRD_PINCTRL_PIN(SHARKL5_AUD_DAD0),
	SPRD_PINCTRL_PIN(SHARKL5_XTL_EN1),
	SPRD_PINCTRL_PIN(SHARKL5_AUD_DASYNC),
	SPRD_PINCTRL_PIN(SHARKL5_AUD_DAD1),
	SPRD_PINCTRL_PIN(SHARKL5_CHIP_SLEEP),
	SPRD_PINCTRL_PIN(SHARKL5_SIMCLK2),
	SPRD_PINCTRL_PIN(SHARKL5_SIMDA2),
	SPRD_PINCTRL_PIN(SHARKL5_SIMRST2),
	SPRD_PINCTRL_PIN(SHARKL5_SD0_CMD),
	SPRD_PINCTRL_PIN(SHARKL5_SD0_D0),
	SPRD_PINCTRL_PIN(SHARKL5_SD0_D1),
	SPRD_PINCTRL_PIN(SHARKL5_SD0_CLK),
	SPRD_PINCTRL_PIN(SHARKL5_SD0_D2),
	SPRD_PINCTRL_PIN(SHARKL5_SD0_D3),
	SPRD_PINCTRL_PIN(SHARKL5_SIMCLK0),
	SPRD_PINCTRL_PIN(SHARKL5_SIMDA0),
	SPRD_PINCTRL_PIN(SHARKL5_SIMRST0),
	SPRD_PINCTRL_PIN(SHARKL5_SIMCLK1),
	SPRD_PINCTRL_PIN(SHARKL5_SIMDA1),
	SPRD_PINCTRL_PIN(SHARKL5_SIMRST1),
	SPRD_PINCTRL_PIN(SHARKL5_SD2_CMD),
	SPRD_PINCTRL_PIN(SHARKL5_SD2_D0),
	SPRD_PINCTRL_PIN(SHARKL5_SD2_D1),
	SPRD_PINCTRL_PIN(SHARKL5_SD2_CLK),
	SPRD_PINCTRL_PIN(SHARKL5_SD2_D2),
	SPRD_PINCTRL_PIN(SHARKL5_SD2_D3),
	SPRD_PINCTRL_PIN(SHARKL5_RFCTL0),
	SPRD_PINCTRL_PIN(SHARKL5_RFCTL1),
	SPRD_PINCTRL_PIN(SHARKL5_RFCTL2),
	SPRD_PINCTRL_PIN(SHARKL5_RFCTL3),
	SPRD_PINCTRL_PIN(SHARKL5_RFCTL4),
	SPRD_PINCTRL_PIN(SHARKL5_RFCTL5),
	SPRD_PINCTRL_PIN(SHARKL5_RFCTL6),
	SPRD_PINCTRL_PIN(SHARKL5_RFCTL7),
	SPRD_PINCTRL_PIN(SHARKL5_RFCTL8),
	SPRD_PINCTRL_PIN(SHARKL5_RFCTL9),
	SPRD_PINCTRL_PIN(SHARKL5_RFCTL10),
	SPRD_PINCTRL_PIN(SHARKL5_RFCTL11),
	SPRD_PINCTRL_PIN(SHARKL5_GPIO31),
	SPRD_PINCTRL_PIN(SHARKL5_GPIO32),
	SPRD_PINCTRL_PIN(SHARKL5_GPIO33),
	SPRD_PINCTRL_PIN(SHARKL5_RFCTL16),
	SPRD_PINCTRL_PIN(SHARKL5_RFCTL17),
	SPRD_PINCTRL_PIN(SHARKL5_GPIO9),
	SPRD_PINCTRL_PIN(SHARKL5_RFCTL19),
	SPRD_PINCTRL_PIN(SHARKL5_RFCTL20),
	SPRD_PINCTRL_PIN(SHARKL5_RFSCK0),
	SPRD_PINCTRL_PIN(SHARKL5_RFSDA0),
	SPRD_PINCTRL_PIN(SHARKL5_RFSEN0),
	SPRD_PINCTRL_PIN(SHARKL5_RFSCK1),
	SPRD_PINCTRL_PIN(SHARKL5_RFSDA1),
	SPRD_PINCTRL_PIN(SHARKL5_RFSEN1),
	SPRD_PINCTRL_PIN(SHARKL5_RFFE0_SCK),
	SPRD_PINCTRL_PIN(SHARKL5_RFFE0_SDA),
	SPRD_PINCTRL_PIN(SHARKL5_RFFE1_SCK),
	SPRD_PINCTRL_PIN(SHARKL5_RFFE1_SDA),
	SPRD_PINCTRL_PIN(SHARKL5_U1TXD),
	SPRD_PINCTRL_PIN(SHARKL5_U1RXD),
	SPRD_PINCTRL_PIN(SHARKL5_SCL6),
	SPRD_PINCTRL_PIN(SHARKL5_SDA6),
	SPRD_PINCTRL_PIN(SHARKL5_MTCK_ARM),
	SPRD_PINCTRL_PIN(SHARKL5_MTMS_ARM),
	SPRD_PINCTRL_PIN(SHARKL5_PWMC),
	SPRD_PINCTRL_PIN(SHARKL5_KEYOUT0),
	SPRD_PINCTRL_PIN(SHARKL5_KEYOUT1),
	SPRD_PINCTRL_PIN(SHARKL5_KEYOUT2),
	SPRD_PINCTRL_PIN(SHARKL5_KEYIN0),
	SPRD_PINCTRL_PIN(SHARKL5_KEYIN1),
	SPRD_PINCTRL_PIN(SHARKL5_KEYIN2),
	SPRD_PINCTRL_PIN(SHARKL5_SCL0),
	SPRD_PINCTRL_PIN(SHARKL5_SDA0),
	SPRD_PINCTRL_PIN(SHARKL5_SDA1),
	SPRD_PINCTRL_PIN(SHARKL5_SCL1),
	SPRD_PINCTRL_PIN(SHARKL5_CMMCLK0),
	SPRD_PINCTRL_PIN(SHARKL5_CMMCLK1),
	SPRD_PINCTRL_PIN(SHARKL5_CMRST0),
	SPRD_PINCTRL_PIN(SHARKL5_CMRST1),
	SPRD_PINCTRL_PIN(SHARKL5_CMPD0),
	SPRD_PINCTRL_PIN(SHARKL5_CMPD1),
	SPRD_PINCTRL_PIN(SHARKL5_CMMCLK2),
	SPRD_PINCTRL_PIN(SHARKL5_CMPD2),
	SPRD_PINCTRL_PIN(SHARKL5_CMRST2),
	SPRD_PINCTRL_PIN(SHARKL5_SPI0_CSN),
	SPRD_PINCTRL_PIN(SHARKL5_SPI0_DO),
	SPRD_PINCTRL_PIN(SHARKL5_SPI0_DI),
	SPRD_PINCTRL_PIN(SHARKL5_SPI0_CLK),
	SPRD_PINCTRL_PIN(SHARKL5_EXTINT9),
	SPRD_PINCTRL_PIN(SHARKL5_EXTINT10),
	SPRD_PINCTRL_PIN(SHARKL5_IIS1DI),
	SPRD_PINCTRL_PIN(SHARKL5_IIS1DO),
	SPRD_PINCTRL_PIN(SHARKL5_IIS1CLK),
	SPRD_PINCTRL_PIN(SHARKL5_IIS1LRCK),
	SPRD_PINCTRL_PIN(SHARKL5_SCL2),
	SPRD_PINCTRL_PIN(SHARKL5_SDA2),
	SPRD_PINCTRL_PIN(SHARKL5_MEMS_MIC_CLK0),
	SPRD_PINCTRL_PIN(SHARKL5_MEMS_MIC_DATA0),
	SPRD_PINCTRL_PIN(SHARKL5_MEMS_MIC_CLK1),
	SPRD_PINCTRL_PIN(SHARKL5_MEMS_MIC_DATA1),
	SPRD_PINCTRL_PIN(SHARKL5_SPI2_CSN),
	SPRD_PINCTRL_PIN(SHARKL5_SPI2_DO),
	SPRD_PINCTRL_PIN(SHARKL5_SPI2_DI),
	SPRD_PINCTRL_PIN(SHARKL5_SPI2_CLK),
	SPRD_PINCTRL_PIN(SHARKL5_IIS0DI),
	SPRD_PINCTRL_PIN(SHARKL5_IIS0DO),
	SPRD_PINCTRL_PIN(SHARKL5_IIS0CLK),
	SPRD_PINCTRL_PIN(SHARKL5_IIS0LRCK),
	SPRD_PINCTRL_PIN(SHARKL5_U5TXD),
	SPRD_PINCTRL_PIN(SHARKL5_U5RXD),
	SPRD_PINCTRL_PIN(SHARKL5_CLK_AUX0),
	SPRD_PINCTRL_PIN(SHARKL5_U0TXD),
	SPRD_PINCTRL_PIN(SHARKL5_U0RXD),
	SPRD_PINCTRL_PIN(SHARKL5_U0CTS),
	SPRD_PINCTRL_PIN(SHARKL5_U0RTS),
	SPRD_PINCTRL_PIN(SHARKL5_U4TXD),
	SPRD_PINCTRL_PIN(SHARKL5_U4RXD),
	SPRD_PINCTRL_PIN(SHARKL5_U4CTS),
	SPRD_PINCTRL_PIN(SHARKL5_U4RTS),
	SPRD_PINCTRL_PIN(SHARKL5_SD1_CMD),
	SPRD_PINCTRL_PIN(SHARKL5_SD1_D0),
	SPRD_PINCTRL_PIN(SHARKL5_SD1_D1),
	SPRD_PINCTRL_PIN(SHARKL5_SD1_CLK),
	SPRD_PINCTRL_PIN(SHARKL5_SD1_D2),
	SPRD_PINCTRL_PIN(SHARKL5_SD1_D3),
	SPRD_PINCTRL_PIN(SHARKL5_EXTINT0),
	SPRD_PINCTRL_PIN(SHARKL5_EXTINT1),
	SPRD_PINCTRL_PIN(SHARKL5_SDA3),
	SPRD_PINCTRL_PIN(SHARKL5_SCL3),

	SPRD_PINCTRL_PIN(SHARKL5_EMMC_RST_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_EMMC_CMD_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_EMMC_D0_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_EMMC_D3_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_EMMC_D2_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_EMMC_D5_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_EMMC_CLK_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_EMMC_DS_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_EMMC_D1_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_EMMC_D4_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_EMMC_D6_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_EMMC_D7_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_LCM_RSTN_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_DSI_TE_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_DCDC_ARM1_EN_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_PTEST_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_EXT_RST_B_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_ADI_SCLK_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_CLK_32K_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_ANA_INT_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_ADI_D_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_AUD_SCLK_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_DCDC_ARM0_EN_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_AUD_ADD0_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_XTL_EN0_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_AUD_ADSYNC_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_AUD_DAD0_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_XTL_EN1_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_AUD_DASYNC_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_AUD_DAD1_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_CHIP_SLEEP_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SIMCLK2_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SIMDA2_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SIMRST2_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SD0_CMD_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SD0_D0_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SD0_D1_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SD0_CLK_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SD0_D2_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SD0_D3_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SIMCLK0_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SIMDA0_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SIMRST0_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SIMCLK1_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SIMDA1_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SIMRST1_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SD2_CMD_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SD2_D0_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SD2_D1_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SD2_CLK_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SD2_D2_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SD2_D3_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_RFCTL0_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_RFCTL1_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_RFCTL2_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_RFCTL3_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_RFCTL4_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_RFCTL5_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_RFCTL6_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_RFCTL7_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_RFCTL8_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_RFCTL9_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_RFCTL10_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_RFCTL11_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_GPIO31_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_GPIO32_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_GPIO33_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_RFCTL16_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_RFCTL17_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_GPIO9_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_RFCTL19_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_RFCTL20_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_RFSCK0_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_RFSDA0_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_RFSEN0_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_RFSCK1_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_RFSDA1_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_RFSEN1_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_RFFE0_SCK_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_RFFE0_SDA_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_RFFE1_SCK_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_RFFE1_SDA_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_U1TXD_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_U1RXD_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SCL6_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SDA6_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_MTCK_ARM_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_MTMS_ARM_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_PWMC_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_KEYOUT0_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_KEYOUT1_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_KEYOUT2_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_KEYIN0_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_KEYIN1_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_KEYIN2_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SCL0_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SDA0_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SDA1_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SCL1_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_CMMCLK0_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_CMMCLK1_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_CMRST0_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_CMRST1_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_CMPD0_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_CMPD1_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_CMMCLK2_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_CMPD2_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_CMRST2_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SPI0_CSN_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SPI0_DO_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SPI0_DI_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SPI0_CLK_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_EXTINT9_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_EXTINT10_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_IIS1DI_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_IIS1DO_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_IIS1CLK_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_IIS1LRCK_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SCL2_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SDA2_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_MEMS_MIC_CLK0_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_MEMS_MIC_DATA0_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_MEMS_MIC_CLK1_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_MEMS_MIC_DATA1_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SPI2_CSN_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SPI2_DO_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SPI2_DI_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SPI2_CLK_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_IIS0DI_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_IIS0DO_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_IIS0CLK_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_IIS0LRCK_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_U5TXD_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_U5RXD_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_CLK_AUX0_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_U0TXD_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_U0RXD_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_U0CTS_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_U0RTS_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_U4TXD_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_U4RXD_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_U4CTS_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_U4RTS_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SD1_CMD_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SD1_D0_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SD1_D1_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SD1_CLK_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SD1_D2_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SD1_D3_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_EXTINT0_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_EXTINT1_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SDA3_MISC),
	SPRD_PINCTRL_PIN(SHARKL5_SCL3_MISC),
};

static int sprd_pinctrl_probe(struct platform_device *pdev)
{
	return sprd_pinctrl_core_probe(pdev, sprd_sharkl5_pins_info,
				       ARRAY_SIZE(sprd_sharkl5_pins_info),
				       PINCTRL_REG_OFFSET,
				       PINCTRL_REG_MISC_OFFSET);
}

static const struct of_device_id sprd_pinctrl_of_match[] = {
	{
		.compatible = "sprd,sharkl5-pinctrl",
	},
	{ },
};
MODULE_DEVICE_TABLE(of, sprd_pinctrl_of_match);

static struct platform_driver sprd_pinctrl_driver = {
	.driver = {
		.name = "sprd-pinctrl",
		.of_match_table = sprd_pinctrl_of_match,
	},
	.probe = sprd_pinctrl_probe,
	.remove = sprd_pinctrl_remove,
	.shutdown = sprd_pinctrl_shutdown,
};

module_platform_driver(sprd_pinctrl_driver);

MODULE_DESCRIPTION("SPREADTRUM Pin Controller Driver");
MODULE_AUTHOR("luting guo <luting.guo@unisoc.com>");
MODULE_LICENSE("GPL v2");
