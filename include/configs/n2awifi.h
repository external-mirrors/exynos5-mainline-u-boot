/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2025 Hendrik Noack
 *
 * Configuration settings for the Samsung Exynos5420 Galaxy Tab Pro 10.1 WiFi board.
 */

#ifndef __CONFIG_N2AWIFI_H
#define __CONFIG_N2AWIFI_H

#define MEM_LAYOUT_ENV_SETTINGS \
	"bootm_size=0x10000000\0" \
	"kernel_addr_r=0x22000000\0" \
	"fdt_addr_r=0x23000000\0" \
	"ramdisk_addr_r=0x23300000\0" \
	"scriptaddr=0x30000000\0" \
	"pxefile_addr_r=0x31000000\0" \
	"fdtfile=exynos5420-n2awifi.dtb\0"

#include <configs/exynos5420-galaxy-tab-common.h>

#endif	/* __CONFIG_N2AWIFI_H */
