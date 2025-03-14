// This file is Copyright (c) 2023-2025 Victor Suarez Rovere <suarezvictor@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-only
#ifndef __MISC_H__
#define __MISC_H__

#ifndef DISABLE_HARDWARE_ACCEL
#include <generated/csr.h>

#ifdef CSR_TIMER0_UPTIME_CYCLES_ADDR
static inline uint64_t highres_ticks(void) { timer0_uptime_latch_write(1);  return timer0_uptime_cycles_read(); }
static inline uint64_t highres_ticks_freq(void) { return CONFIG_CLOCK_FREQUENCY; }
#endif
#endif

#define ACCEL_STATIC_ASSERT(cond, msg) typedef char static_assertion_##msg[(cond)?1:-1];
//#define ACCEL_STATIC_ASSERT(cond, msg) _Static_assert(cond, msg);
//#define ACCEL_STATIC_ASSERT(X, msg) ({ extern int __attribute__((error("assertion failure: '" #X ##msg))) compile_time_check(); ((X)?0:compile_time_check()),0; })

#endif // __MISC_H__
