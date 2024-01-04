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
// SPDX-License-Identifier: AGPL-3.0-only

void sys_dram_init(void)
{
/*
	// Copy ddr bin to 0x00030000
	la t1, _ddr_bin_start
	LREG t1, (t1)
	la t2, _ddr_bin_end
	LREG t2, (t2)
	sub a2, t2, t1
	la t1, _image_start
	LREG t1, (t1)
	la t2, _ddr_bin_start
	LREG t2, (t2)
	sub t0, t2, t1
	la a1, _start
	add a1, a1, t0
	li a0, 0x00030000
	call memcpy
*/
}

struct pt_regs_t {
	unsigned long x[32];
	unsigned long status;
	unsigned long epc;
	unsigned long badvaddr;
	unsigned long cause;
	unsigned long insn;
};

void riscv64_handle_exception(struct pt_regs_t * regs)
{
}

void sys_uart_init()
{
  void uart_probe();
  uart_probe();
}
