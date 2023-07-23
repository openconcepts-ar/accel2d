// This file is Copyright (c) 2023 Victor Suarez Rovere <suarezvictor@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-only

#ifndef __ACCEL_CORES_H__
#define __ACCEL_CORES_H__

//This file could be generated automatically
#include <stddef.h> //just for NULL
#ifndef DISABLE_HARDWARE_ACCEL
#include <generated/csr.h>
#endif

// accel_rectangle_fill32 --------------------------------------------------------------------------
#include "accel_rectangle_fill32.inl"

#if !defined(CSR_ACCEL_RECTANGLE_FILL32_BASE) && defined(ACCEL_RECTANGLE_FILL32_REGION)
#define CSR_ACCEL_RECTANGLE_FILL32_BASE (size_t)(ACCEL_RECTANGLE_FILL32_REGION+ACCEL_RECTANGLE_FILL32_CSR_PAGE_OFFSET)
#endif

#ifdef CSR_ACCEL_RECTANGLE_FILL32_BASE
static accel_rectangle_fill32_layout_t * const accel_rectangle_fill32_regs =
  (accel_rectangle_fill32_layout_t *) CSR_ACCEL_RECTANGLE_FILL32_BASE;
#else
static accel_rectangle_fill32_layout_t * const accel_rectangle_fill32_regs = NULL;
#endif

unsigned accel_rectangle_fill(accel_rectangle_fill32_layout_t *regs, int x0, int y0, int x1, int y1, uint32_t rgba);


// accel_ellipse_fill32 ----------------------------------------------------------------------------
#include "accel_ellipse_fill32.inl"

#if !defined(CSR_ACCEL_ELLIPSE_FILL32_BASE) && defined(ACCEL_ELLIPSE_FILL32_REGION)
#define CSR_ACCEL_ELLIPSE_FILL32_BASE (size_t)(ACCEL_ELLIPSE_FILL32_REGION+ACCEL_ELLIPSE_FILL32_CSR_PAGE_OFFSET)
#endif

#ifdef CSR_ACCEL_ELLIPSE_FILL32_BASE
static accel_ellipse_fill32_layout_t * const accel_ellipse_fill32_regs =
  (accel_ellipse_fill32_layout_t *) CSR_ACCEL_ELLIPSE_FILL32_BASE;
#else
static accel_ellipse_fill32_layout_t * const accel_ellipse_fill32_regs = NULL;
#endif

unsigned accel_ellipse_fill(accel_ellipse_fill32_layout_t *regs, int x0, int y0, int x1, int y1, uint32_t rgba);

#endif //__ACCEL_CORES_H__
