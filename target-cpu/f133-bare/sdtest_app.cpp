/* SPDX-License-Identifier: GPL-2.0+ */

#ifdef __cplusplus
//this hack is to use original headers that doesn't support C++
#define false _false
#define true _true
#define bool _bool
#endif

#define __DEBUG_H__ //this hack prevents log.h included from sys-gpio.h
#include "sys-gpio.h"
#undef __DEBUG_H__

#include "sdhci/sys-sdcard.h"
#include "sdhci/sys-sdhci.h"

sdhci_t sdhci0 =
{
		.name = "sdhci0",
		.id = 0,
		.reg = (sdhci_reg_t *) 0x04020000,
		.voltage = MMC_VDD_27_36,
		.width = MMC_BUS_WIDTH_4,
		.clock = MMC_CLK_25M, //TODO: test different frequencies
		.sdhci_pll = CCU_MMC_CTRL_PLL_PERIPH1X,
		.removable = 0,
		.isspi = false,
		.skew_auto_mode = true,

		//this matches board pins
		.gpio_d0 = {GPIO_PIN(GPIO_PORTF, 1), GPIO_PERIPH_MUX2},
		.gpio_d1 = {GPIO_PIN(GPIO_PORTF, 0), GPIO_PERIPH_MUX2},
		.gpio_d2 = {GPIO_PIN(GPIO_PORTF, 5), GPIO_PERIPH_MUX2},
		.gpio_d3 = {GPIO_PIN(GPIO_PORTF, 4), GPIO_PERIPH_MUX2},
		.gpio_cmd = {GPIO_PIN(GPIO_PORTF, 3), GPIO_PERIPH_MUX2},
		.gpio_clk = {GPIO_PIN(GPIO_PORTF, 2), GPIO_PERIPH_MUX2},
};

extern "C" void test_app(void)
{
    // Initialize the SD host controller
    if (sunxi_sdhci_init(&sdhci0) != 0)
        printk_error("SMHC: %s controller init failed\n", sdhci0.name);
    else
    {
        printk_info("SMHC: %s controller v%x initialized\n", sdhci0.name, sdhci0.reg->vers);

        // Initialize the SD card, and dump info
	    if (sdmmc_init(&card0, &sdhci0) != 0)
	        printk_warning("SMHC: init failed\n");
	    else
	        printk_info("SMHC: init successful\n");
    }
}


