# SPDX-License-Identifier: GPL-2.0-only
zram-y				:=	zcomp.o zram_drv.o
zram-$(CONFIG_ZRAM_DEDUP)	+=	zram_dedup.o

obj-$(CONFIG_ZRAM)	+=	zram.o

obj-$(CONFIG_ZRAM)      += hybridswap/
obj-$(CONFIG_MAPPED_PROTECT) += memload_opt/mapped_protect/
