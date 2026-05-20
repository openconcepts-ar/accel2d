/* SPDX-License-Identifier: GPL-2.0+ */

#include <stdbool.h>

#include "log.h"
#include "uart.h"

extern sunxi_serial_t uart_dbg;

void test_app(void);

int main(void)
{
    // Initialize the debug serial interface
    sunxi_serial_init(&uart_dbg);

    // Initialize the system clock
    sunxi_clk_init();

    // Initialize the DRAM FIXME: not working in D1s, but not needed in FEL
    //uint32_t dram_size = sunxi_dram_init(&dram_para);

    // Dump information about the system clocks
    sunxi_clk_dump();
    
    // Run test
    test_app();

    for(;;);
    return 0;
}

sunxi_serial_t uart_dbg = {
		.base = SUNXI_UART0_BASE,
		.id = 0,
		.baud_rate = UART_BAUDRATE_115200,
		.dlen = UART_DLEN_8,
		.stop = UART_STOP_BIT_0,
		.parity = UART_PARITY_NO,
		.gpio_pin =
				{
						//this matches board pins
						.gpio_tx = {GPIO_PIN(GPIO_PORTE, 2), GPIO_PERIPH_MUX6},
						.gpio_rx = {GPIO_PIN(GPIO_PORTE, 3), GPIO_PERIPH_MUX6},
				},
		.uart_clk =
				{
						.gate_reg_base = CCU_BASE + CCU_UART_BGR_REG,
						.gate_reg_offset = SERIAL_DEFAULT_CLK_GATE_OFFSET(0),
						.rst_reg_base = CCU_BASE + CCU_UART_BGR_REG,
						.rst_reg_offset = SERIAL_DEFAULT_CLK_RST_OFFSET(0),
						.parent_clk = SERIAL_DEFAULT_PARENT_CLK,
				},
};

//SyterKit dependencies
#include "uart.c"
#include "drivers/sys-uart.c" //used in main
#include "drivers/chips/sun20iw1/sys-clk.c" //used in main
#include "arch/riscv/riscv64_c906/timer.c" //used in sys-sdcard.c
#include "log/log.c"
#include "log/xformat.c"

//sd card demo dependencies
#include "drivers/sdhci/sys-sdcard.c" //800 lines, used in main: sdmmc_init, card0
#include "drivers/sdhci/sys-sdhci.c" //750 lines, sunxi_sdhci_init (set gpios), used in main
#include "drivers/gpio/sys-gpio-v2.c" //used by sys-sdhci.c

//general dependencies
#include "driver_uart.c"


