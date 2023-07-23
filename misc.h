// This file is Copyright (c) 2023 Victor Suarez Rovere <suarezvictor@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-only

#define ACCEL_STATIC_ASSERT(cond, msg) typedef char static_assertion_##msg[(cond)?1:-1];
//#define ACCEL_STATIC_ASSERT(cond, msg) _Static_assert(cond, msg);
//#define ACCEL_STATIC_ASSERT(X, msg) ({ extern int __attribute__((error("assertion failure: '" #X ##msg))) compile_time_check(); ((X)?0:compile_time_check()),0; })
