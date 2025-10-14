// SPDX-License-Identifier: GPL-2.0
/*
 * Exynos5250 pinctrl driver.
 *
 * Copyright (c) 2026 Lukas Timmermann <uboot@timmermann.space>
 */

#include <dm.h>
#include <dm/pinctrl.h>
#include "pinctrl-exynos.h"

static const struct pinctrl_ops exynos5250_pinctrl_ops = {
	.set_state = exynos_pinctrl_set_state
};

static const struct samsung_pin_bank_data exynos5250_pin_banks0[] = {
	EXYNOS_PIN_BANK(8, 0x000, "gpa0"),
	EXYNOS_PIN_BANK(6, 0x020, "gpa1"),
	EXYNOS_PIN_BANK(8, 0x040, "gpa2"),
	EXYNOS_PIN_BANK(5, 0x060, "gpb0"),
	EXYNOS_PIN_BANK(5, 0x080, "gpb1"),
	EXYNOS_PIN_BANK(4, 0x0a0, "gpb2"),
	EXYNOS_PIN_BANK(4, 0x0c0, "gpb3"),
	EXYNOS_PIN_BANK(7, 0x0e0, "gpc0"),
	EXYNOS_PIN_BANK(4, 0x100, "gpc1"),
	EXYNOS_PIN_BANK(7, 0x120, "gpc2"),
	EXYNOS_PIN_BANK(7, 0x140, "gpc3"),
	EXYNOS_PIN_BANK(4, 0x160, "gpd0"),
	EXYNOS_PIN_BANK(8, 0x180, "gpd1"),
	EXYNOS_PIN_BANK(7, 0x2e0, "gpc4"),
	EXYNOS_PIN_BANK(6, 0x1a0, "gpy0"),
	EXYNOS_PIN_BANK(4, 0x1c0, "gpy1"),
	EXYNOS_PIN_BANK(6, 0x1e0, "gpy2"),
	EXYNOS_PIN_BANK(8, 0x200, "gpy3"),
	EXYNOS_PIN_BANK(8, 0x220, "gpy4"),
	EXYNOS_PIN_BANK(8, 0x240, "gpy5"),
	EXYNOS_PIN_BANK(8, 0x260, "gpy6"),
	EXYNOS_PIN_BANK(8, 0xc00, "gpx0"),
	EXYNOS_PIN_BANK(8, 0xc20, "gpx1"),
	EXYNOS_PIN_BANK(8, 0xc40, "gpx2"),
	EXYNOS_PIN_BANK(8, 0xc60, "gpx3"),
};

static const struct samsung_pin_bank_data exynos5250_pin_banks1[] = {
	EXYNOS_PIN_BANK(8, 0x000, "gpe0"),
	EXYNOS_PIN_BANK(2, 0x020, "gpe1"),
	EXYNOS_PIN_BANK(4, 0x040, "gpf0"),
	EXYNOS_PIN_BANK(4, 0x060, "gpf1"),
	EXYNOS_PIN_BANK(8, 0x080, "gpg0"),
	EXYNOS_PIN_BANK(8, 0x0a0, "gpg1"),
	EXYNOS_PIN_BANK(2, 0x0c0, "gpg2"),
	EXYNOS_PIN_BANK(4, 0x0e0, "gph0"),
	EXYNOS_PIN_BANK(8, 0x100, "gph1"),
};

static const struct samsung_pin_bank_data exynos5250_pin_banks2[] = {
	EXYNOS_PIN_BANK(8, 0x000, "gpv0"),
	EXYNOS_PIN_BANK(8, 0x020, "gpv1"),
	EXYNOS_PIN_BANK(8, 0x060, "gpv2"),
	EXYNOS_PIN_BANK(8, 0x080, "gpv3"),
	EXYNOS_PIN_BANK(2, 0x0c0, "gpv4"),
};

static const struct samsung_pin_bank_data exynos5250_pin_banks3[] = {
	EXYNOS_PIN_BANK(7, 0x000, "gpz"),
};

static const struct samsung_pin_ctrl exynos5250_pin_ctrl[] = {
	{
		.pin_banks	= exynos5250_pin_banks0,
		.nr_banks	= ARRAY_SIZE(exynos5250_pin_banks0),
	}, {
		.pin_banks	= exynos5250_pin_banks1,
		.nr_banks	= ARRAY_SIZE(exynos5250_pin_banks1),
	}, {
		.pin_banks	= exynos5250_pin_banks2,
		.nr_banks	= ARRAY_SIZE(exynos5250_pin_banks2),
	}, {
		.pin_banks	= exynos5250_pin_banks3,
		.nr_banks	= ARRAY_SIZE(exynos5250_pin_banks3),
	},
	{/* list terminator */}
};

static const struct udevice_id exynos5250_pinctrl_ids[] = {
	{ .compatible = "samsung,exynos5250-pinctrl",
		.data = (ulong)exynos5250_pin_ctrl },
	{ }
};

U_BOOT_DRIVER(pinctrl_exynos5250) = {
	.name		= "pinctrl_exynos5250",
	.id		= UCLASS_PINCTRL,
	.of_match	= exynos5250_pinctrl_ids,
	.priv_auto	= sizeof(struct exynos_pinctrl_priv),
	.ops		= &exynos5250_pinctrl_ops,
	.probe		= exynos_pinctrl_probe,
	.bind		= exynos_pinctrl_bind,
};
