/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2025 Hendrik Noack
 *
 * Configuration settings for the Samsung Exynos5420 Galaxy Tab boards.
 */

#ifndef __CONFIG_EXYNOS5420_GALAXY_TAB_H
#define __CONFIG_EXYNOS5420_GALAXY_TAB_H

#include <configs/exynos5420-common.h>
#include <configs/exynos5-common.h>

#define CFG_SYS_SDRAM_BASE	0x20000000

/* DRAM Memory Banks */
#define SDRAM_BANK_SIZE		(512UL << 20UL)	/* 512 MB */

#define CFG_SYS_INIT_RAM_ADDR	0x20000000
#define CFG_SYS_INIT_RAM_SIZE	(512UL << 20UL)

#undef BOOT_TARGET_DEVICES
#define BOOT_TARGET_DEVICES(func) \
	func(MMC, mmc, 2)

#undef MEM_LAYOUT_ENV_SETTINGS
#define MEM_LAYOUT_ENV_SETTINGS \
	"bootm_size=0x10000000\0" \
	"kernel_addr_r=0x22000000\0" \
	"fdt_addr_r=0x23000000\0" \
	"ramdisk_addr_r=0x23300000\0" \
	"scriptaddr=0x30000000\0" \
	"pxefile_addr_r=0x31000000\0"

#undef CFG_EXTRA_ENV_SETTINGS
#define CFG_EXTRA_ENV_SETTINGS \
	EXYNOS_FDTFILE_SETTING \
	MEM_LAYOUT_ENV_SETTINGS \
	BOOTENV

#endif	/* __CONFIG_EXYNOS5420_GALAXY_TAB_H */
