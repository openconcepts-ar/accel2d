// (C) 2024 Victor Suarez Rovere <suarezvictor@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-only

#include <stdint.h>

#define iabs(x) ((x) < 0 ? -(x) : (x))

#define DISABLE_HARDWARE_ACCEL
#define BUSMASTER_CPU busmaster_t //this enable compilation/execution of cores on CPU
typedef uint32_t *busmaster_t;
#include "accel_cores.h"
#include "rectangle_fill32.cc"
#include "ellipse_fill32.cc"
#include "line32.cc"
#include "litex/accel_cores.c"

