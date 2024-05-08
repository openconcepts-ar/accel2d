// (C) 2024 Victor Suarez Rovere <suarezvictor@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-only

#ifndef __IOREGS_H__
#define __IOREGS_H__

#include <stdint.h>

typedef int gpio_pin_t;

//Register defintions generated from d1_ioregs.svd using custom tool, based on:
//see http://github.com/postspectacular/cmsis-svd-srcgen (or custom fork)
#include "d1_ioregs.h"

static inline __attribute__((__always_inline__)) uint32_t io_read32(uintptr_t addr)
{
	return (*((volatile uint32_t *)(addr)));
}

static inline __attribute__((__always_inline__)) void io_write32(uintptr_t addr, uint32_t value)
{
	*((volatile uint32_t *)(addr)) = value;
}

#endif //__IOREGS_H__
