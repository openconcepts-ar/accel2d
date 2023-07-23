// This file is Copyright (c) 2023 Victor Suarez Rovere <suarezvictor@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-only

#define BUSMASTER_CPU busmaster_t //this enable compilation/execution of cores on CPU

#ifdef __linux__
#include <stdint.h>
//FIXME: move the logic elsewhere
#if UINTPTR_MAX > 0xFFFFFFFF
#error 64-bit compilation would require that accelleration use a 64-bit offset to for busmaster)
#endif
#else
#warning use std types
typedef __INTPTR_TYPE__ intptr_t;
typedef unsigned long long uint64_t;
#endif


#include "cflexhdl.h"
#include "bus.h"
#include "misc.h" //ACCEL_STATIC_ASSERT
#include "accel_regs.h"

#if SDRAM_BUS_BITS==32
typedef uint32_t *busmaster_t;
#else
#error bus width not supported
#endif

#include "rectangle_fill32.cc"
#include "ellipse_fill32.cc"
#include "sw_cores.h"


void sw_rectangle_fill(accel_rectangle_fill32_layout_t *regs)
{
  uint16 x0 = regs->x0;
  uint16 x1 = regs->x1;
  uint16 y0 = regs->y0;
  uint16 y1 = regs->y1;
  uint32 rgba = regs->rgba;
  uint32 base = regs->base;
  uint32 xstride = regs->xstride;
  uint32 ystride = regs->ystride;
  
  rectangle_fill32(BUSMASTER_ARG, x0, x1, y0, y1, rgba, base, xstride, ystride);
}

void sw_ellipse_fill(accel_ellipse_fill32_layout_t *regs)
{
  uint16 x0 = regs->x0;
  uint16 x1 = regs->x1;
  uint16 y0 = regs->y0;
  uint16 y1 = regs->y1;
  uint32 rgba = regs->rgba;
  uint32 base = regs->base;
  uint32 xstride = regs->xstride;
  uint32 ystride = regs->ystride;
  
  ellipse_fill32(BUSMASTER_ARG, x0, x1, y0, y1, rgba, base, xstride, ystride);
}

