/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2025 Hendrik Noack
 *
 * Configuration settings for the Samsung Exynos5420 Galaxy Tab boards.
 */

#ifndef __CONFIG_EXYNOS5420_GALAXY_TAB_H
#define __CONFIG_EXYNOS5420_GALAXY_TAB_H

#include <configs/exynos5420-common.h>
#include <configs/exynos5-dt-common.h>
#include <configs/exynos5-common.h>

#define CFG_SYS_SDRAM_BASE	0x20000000

/* DRAM Memory Banks */
#define SDRAM_BANK_SIZE		(512UL << 20UL)	/* 512 MB */

#define CFG_SYS_INIT_RAM_ADDR	0x20000000
#define CFG_SYS_INIT_RAM_SIZE	(512UL << 20UL)

#endif	/* __CONFIG_EXYNOS5420_GALAXY_TAB_H */
