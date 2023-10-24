// This file is Copyright (c) 2023 Victor Suarez Rovere <suarezvictor@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-only

#ifndef __SW_CORES_H__
#define __SW_CORES_H__

#ifdef __cplusplus
extern "C" {
#endif

void sw_rectangle_fill(accel_rectangle_fill32_layout_t *regs);
void sw_ellipse_fill(accel_ellipse_fill32_layout_t *regs);
void sw_line(accel_line32_layout_t *regs);

#ifdef __cplusplus
}
#endif

#endif //__SW_CORES_H__
