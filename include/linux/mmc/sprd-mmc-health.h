/*
 * create in 2021/1/7.
 * create emmc node in  /proc/bootdevice
 */
#ifndef _SPRD_PROC_MMC_HEALTH_H_
#define _SPRD_PROC_MMC_HEALTH_H_
#include <linux/proc_fs.h>
#include <linux/proc_ns.h>
#include <linux/mmc/mmc.h>
#include <linux/fs.h>
#include <linux/seq_file.h>
#include <linux/module.h>
#include <linux/mmc/card.h>
#define MAX_NAME_LEN 32

struct __mmchealthdata {
	u8 buf[512];
};

void set_mmchealth_data(u8 *data);
int sprd_create_mmchealth_init(int flag);

#define YMTC_EC110_eMMC 1  //cjcc changjiangcunchu 32G
#define HFCS_32G_eMMC1 2 //zhaoxin 32G
#define HFCS_32G_eMMC2 3 //zhaoxin 32G
//#define HFCS_64G_eMMC1 4 //zhaoxin 64G
#define HFCS_64G_eMMC2 4 //zhaoxin 64G
#define Western_Digital_eMMC 5 //sandisk shandi
#define YMTC_EC110_eMMC1 6 //cjcc changjiangcunchu 128G
#define YMTC_EC110_eMMC2 7 //cjcc changjiangcunchu 64G
#define Micron_64G_eMMC 8 //Micron 64G
#define Micron_128G_eMMC 9 //Micron 128G
#define Foresee_64G_eMMC 10 //Jiangbolong 64G
#define Foresee_128G_eMMC 11 //Jiangbolong 128G
#define Phison_64G_eMMC 12 //Qunlian 64G
#define Phison_128G_eMMC 13 //Qunlian 64G
#define YMTC_EC110_eMMC3 14 //cjcc changjiangcunchu 128G
#define YMTC_EC230_eMMC 15 //cjcc changjiangcunchu 256G
#define BAIWEI_ARJ21X_64G_eMMC 16 //64G baiwei
#define BAIWEI_ARJ41X_128G_eMMC 17 //128G baiwei
#define BAIWEI_AKJ41X_256G_eMMC 18 //256G baiwei

int get_mmc_health(struct mmc_card *card);
int get_emmc_mode(void);
#endif
