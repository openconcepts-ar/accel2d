/*
Copyright (c) 2023 Victor Suarez Rovere <suarezvictor@gmail.com>
SPDX-License-Identifier: AGPL-3.0-only

This program is free software: you can redistribute it and/or modify it under the terms of the
GNU Affero General Public License as published by the Free Software Foundation, version 3.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License along with this program.
If not, see <https://www.gnu.org/licenses/>.

This file uses portions from LiteX and MiSoC projects under BSD 2-Clause license
Unless otherwise noted, LiteX is copyright (C) 2012-2022 Enjoy-Digital & LiteX developers.
Unless otherwise noted, MiSoC is copyright (C) 2012-2015 Enjoy-Digital.
Unless otherwise noted, MiSoC is copyright (C) 2007-2015 M-Labs Ltd.

See LITEX-CONTRIBUTORS file for additional authors that may have written code used in this file

*/
typedef struct {
	volatile uint32_t	run;	//offset  0x0
	volatile uint32_t	done;	//offset  0x4
	volatile uint32_t	dx;	//offset  0x8
	volatile uint32_t	dy;	//offset  0xc
	volatile uint32_t	rgba;	//offset  0x10
	volatile uint32_t	tint;	//offset  0x14
	volatile uint32_t	dst_base;	//offset  0x18
	volatile uint32_t	dst_xstride;	//offset  0x1c
	volatile uint32_t	dst_ystride;	//offset  0x20
	volatile uint32_t	src_base;	//offset  0x24
	volatile uint32_t	src_xstride;	//offset  0x28
	volatile uint32_t	src_ystride;	//offset  0x2c
} accel_line32a_layout_t;
#define ACCEL_LINE32A_CSR_PAGE_SIZE 0x30
#define ACCEL_LINE32A_CSR_PAGE_OFFSET 0x0
ACCEL_STATIC_ASSERT(sizeof(accel_line32a_layout_t)==ACCEL_LINE32A_CSR_PAGE_SIZE, non_matching_struct_size)

