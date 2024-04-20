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
// (C) 2021 bigmagic123 https://github.com/bigmagic123/d1-nezha-baremeta
// SPDX-License-Identifier: AGPL-3.0-only AND Apache-2.0

#include "ioregs.h"

const intptr_t UART_BASE = 0x02500000;
const int UART_LSR = 0x0014;
const uint8_t UART_LSR_DR = 0x01; // Receiver data ready
const int UART_RBR = 0x0000;

void uart_probe(void)
{
	uintptr_t addr;
	uint32_t val;

	/* Config GPIOE2 and GPIOE3 to txd0 and rxd0 */
	addr = 0x020000c0 + 0x0;
	val = io_read32(addr);
	val &= ~(0xf << ((2 & 0x7) << 2));
	val |= ((0x6 & 0xf) << ((2 & 0x7) << 2));
	io_write32(addr, val);

	val = io_read32(addr);
	val &= ~(0xf << ((3 & 0x7) << 2));
	val |= ((0x6 & 0xf) << ((3 & 0x7) << 2));
	io_write32(addr, val);

	/* Open the clock gate for uart0 */
	addr = 0x0200190c;
	val = io_read32(addr);
	val |= 1 << 0;
	io_write32(addr, val);

	/* Deassert uart0 reset */
	addr = 0x0200190c;
	val = io_read32(addr);
	val |= 1 << 16;
	io_write32(addr, val);

	/* Config uart0 to 115200-8-1-0 */
	addr = UART_BASE;
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

int driver_uart_putc_wontblock(void)
{
	return (io_read32(UART_BASE + 0x7c) & (0x1 << 1)) != 0;
}

void driver_uart_putc(char c)
{
	while(!driver_uart_putc_wontblock());
	io_write32(UART_BASE + 0x00, c);
}

int driver_uart_getc_wontblock(void)
{
  return (io_read32(UART_BASE + UART_LSR) & UART_LSR_DR) != 0;
}

int driver_uart_getc(void)
{
  if(!driver_uart_getc_wontblock())
    return -1;

  return io_read32(UART_BASE + UART_RBR);
}

