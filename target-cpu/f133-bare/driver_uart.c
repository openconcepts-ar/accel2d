/*
 * Copyright(c) 2007-2022 Jianjun Jiang <8192542@qq.com>
 * Official site: http://xboot.org
 * Mobile phone: +86-18665388956
 * QQ: 8192542
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */
// (C) 2024 Victor Suarez Rovere <suarezvictor@gmail.com>
// (C) 2021 bigmagic123
// SPDX-License-Identifier: AGPL-3.0-only and Apache-2.0

#include "driver_uart.h"

const int UART_LSR = UART0_lsr_OFFSET;
const int UART_USR = UART0_usr_OFFSET;
const uint8_t UART_LSR_DR_MASK = UART0_lsr_dr; // Receiver data ready
const int UART_RBR = UART0_rbr_OFFSET;

#define UART_BASE_n(n) (UART0 + 0x400*n)

/*
CPU BOARD v0.09

PE2: BOOT TX (UART0-TX) / TP8 -- GPIO Function 6
PE3: BOOT RX (UART0-RX) / TP7 -- GPIO Function 6

PB6: DEBUG TX (UART3-TX) / J6 -- GPIO Function 7
PB7: DEBUG RX (UART3-RX) / J6 -- GPIO Function 7

PG6: COMM TX  (UART1-TX ) / J8 -- GPIO Function 2
PG7: COMM RX  (UART1-RX ) / J8 -- GPIO Function 2
PG8: COMM RTS (UART1-RTS) / J8 -- GPIO Function 2
PG9: COMM CTS (UART1-CTS) / J8 -- GPIO Function 2
*/

void uart_probe(UART_dev_t uart_n)
{
	uintptr_t addr;
	uint32_t val;

	switch(uart_n)
	{
	  case 0: //UART 0
		// Config GPIOE2 and GPIOE3 to txd0 and rxd0
		addr = GPIO_pe_cfg0;
		val = io_read32(addr);
		val &= ~(0xf << ((2 & 0x7) << 2)); //GPIOE2 - TX
		val |= ((0x6 & 0xf) << ((2 & 0x7) << 2));
		io_write32(addr, val);

		val = io_read32(addr);
		val &= ~(0xf << ((3 & 0x7) << 2)); //GPIOE3 - RX
		val |= ((0x6 & 0xf) << ((3 & 0x7) << 2));
		io_write32(addr, val);
		break;
	  case 1: //UART 1
		// Config GPIOG6 and GPIOG7 to txd1 and rxd1
		addr = GPIO_pg_cfg0;
		val = io_read32(addr);
		val &= ~GPIO_pg_cfg0_pg6_select; //TX
		val |= 2 << GPIO_pg_cfg0_pg6_select_SHIFT;
		io_write32(addr, val);

		val = io_read32(addr);
		val &= ~GPIO_pg_cfg0_pg7_select; //RX
		val |= 2 << GPIO_pg_cfg0_pg7_select_SHIFT;
		io_write32(addr, val);
		break;
	  default:
		return;
	}

	// Open the clock gate
	addr = CCU_uart_bgr;
	val = io_read32(addr);
	val |= 1 << uart_n;
	io_write32(addr, val);
	// Deassert reset
	val |= (1<<16) << uart_n;
	io_write32(addr, val);

	// Config baud to 115200-8-1-0
	addr = UART_BASE_n(uart_n);
	io_write32(addr + 0x04, 0x0);
	io_write32(addr + 0x08, 0xf7);
	io_write32(addr + 0x10, 0x0);
	val = io_read32(addr + 0x0c);
	val |= (1 << 7);
	io_write32(addr + 0x0c, val);
	io_write32(addr + 0x00, 0xd & 0xff);
	io_write32(addr + 0x04, (0xd >> 8) & 0xff);
	val = io_read32(addr + 0x0c);
	val &= ~(1 << 7);
	io_write32(addr + 0x0c, val);
	val = io_read32(addr + 0x0c);
	val &= ~0x1f;
	val |= (0x3 << 0) | (0 << 2) | (0x0 << 3);
	io_write32(addr + 0x0c, val);
}
int driver_uart_putc_wontblock(UART_dev_t uart_n)
{
	return (io_read32(UART_BASE_n(uart_n) + UART_USR) & (0x1 << 1)) != 0;
}

void driver_uart_putc(UART_dev_t uart_n, char c)
{
	while(!driver_uart_putc_wontblock(uart_n));
	io_write32(UART_BASE_n(uart_n) + 0x00, c);
}

int driver_uart_getc_wontblock(UART_dev_t uart_n)
{
  return (io_read32(UART_BASE_n(uart_n) + UART_LSR) & UART_LSR_DR_MASK) != 0;
}

int driver_uart_getc(UART_dev_t uart_n)
{
  if(!driver_uart_getc_wontblock(uart_n))
    return -1;

  return io_read32(UART_BASE_n(uart_n) + UART_RBR);
}

