// This file is Copyright (c) 2023 Victor Suarez Rovere <suarezvictor@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-only

#ifndef __BUS_H__
#define __BUS_H__

#ifdef BUSMASTER_CPU
#define bus_bits() (8*sizeof(BUSMASTER_CPU(0)[0]))

#ifdef __SIZEOF_INT128__
#define busx_master(bus) BUSMASTER_CPU bus_w, BUSMASTER_CPU bus_r, uint128 bus_sel
#else
#if SDRAM_BUS_BITS > 64
#error Bus width not supported
#endif
#define busx_master(bus) BUSMASTER_CPU bus_w, BUSMASTER_CPU bus_r, uint64 bus_sel
#endif

#define busaddr_t intptr_t
#define busaddr_diff_t intptr_t
#define busx_setup32(bus) bus##_r = bus##_w = nullptr
#define busx_acquire(bus) 
#define busx_release(bus) 
#define busx_reading(bus) false
#define busx_writing(bus) false
#define busx_write_done(bus) true
#define busx_read_done(bus) true
#define busx_write_start(bus, data) *bus##_w = (*bus##_w & ~bus##_sel) | (data & bus##_sel)
#define busx_read_start(bus) 
#define busx_read_data(bus) *bus##_r
#define busx_stop(bus)
#define busx_set_read_address(bus, a) bus##_r = (busmaster_t)(a)
#define busx_set_write_address(bus, a) bus##_w = (busmaster_t)(a)
#define busx_inc_read_address(bus, a) (bus##_r += (a))
#define busx_inc_write_address(bus, a) (bus##_w += (a))
#define busx_next_read_address(bus) busx_inc_read_address(bus, 1)
#define busx_next_write_address(bus) busx_inc_write_address(bus, 1)
#define busx_set_mask(bus, mask) bus_sel = (\
    ((mask)&(1<<0)?(uint128(255)<<8*0):0) \
  | ((mask)&(1<<1)?(uint128(255)<<8*1):0) \
  | ((mask)&(1<<2)?(uint128(255)<<8*2):0) \
  | ((mask)&(1<<3)?(uint128(255)<<8*3):0) \
  | ((mask)&(1<<4)?(uint128(255)<<8*4):0) \
  | ((mask)&(1<<5)?(uint128(255)<<8*5):0) \
  | ((mask)&(1<<6)?(uint128(255)<<8*6):0) \
  | ((mask)&(1<<7)?(uint128(255)<<8*7):0) \
  | ((mask)&(1<<8)?(uint128(255)<<8*8):0) \
  | ((mask)&(1<<9)?(uint128(255)<<8*9):0) \
  | ((mask)&(1<<10)?(uint128(255)<<8*10):0) \
  | ((mask)&(1<<11)?(uint128(255)<<8*11):0) \
  | ((mask)&(1<<12)?(uint128(255)<<8*12):0) \
  | ((mask)&(1<<13)?(uint128(255)<<8*13):0) \
  | ((mask)&(1<<14)?(uint128(255)<<8*14):0) \
  | ((mask)&(1<<15)?(uint128(255)<<8*15):0))


#define BUSMASTER_ARG busmaster_t(), busmaster_t(), -1


#else

#ifndef SDRAM_BUS_BITS
#define __ASSEMBLER__ //this avoids function definitions in following header
#include <generated/soc.h>
#undef __ASSEMBLER__
#endif

#define bus_bits() SDRAM_BUS_BITS //FIXME: should be parametrizable

#define busx_setup32(bus) { bus##_cyc = 0; bus##_stb = 0; bus##_sel = 65535; } //up to 16 bytes
#define busx_acquire(bus) { bus##_cyc = 1; }
#define busx_release(bus) { bus##_cyc = 0; bus##_stb = 0; }
#define busx_reading(bus) (bus##_stb && !bus##_we)
#define busx_writing(bus) (bus##_stb && bus##_we)
#define busx_write_done(bus) (bus##_stb && bus##_w_ack)
#define busx_read_done(bus) (bus##_stb && bus##_r_ack)
#define busx_write_start(bus, data)  { bus##_dat_w = data; bus##_we = 1; bus##_stb = 1; bus##_cyc = 1; }
#define busx_read_start(bus) { bus##_we = 0; bus##_stb = 1; bus##_cyc = 1; }
#define busx_read_data(bus) bus##_dat_r
#define busx_stop(bus) bus##_stb = 0
#define busx_set_write_address(bus, a) bus##_adr_w = (a)
#define busx_set_read_address(bus, a) bus##_adr_r = (a)
#define busx_get_write_address(bus) bus##_adr_w
#define busx_get_read_address(bus) bus##_adr_r
#define busaddr_t uint32
#define busaddr_diff_t int32
#define busx_inc_write_address(bus, a) busx_set_write_address(bus, busx_get_write_address(bus) + (a)*bus_bytes())
#define busx_inc_read_address(bus, a) busx_set_read_address(bus, busx_get_read_address(bus) + (a)*bus_bytes())
#define busx_next_read_address(bus) busx_inc_read_address(bus, 1)
#define busx_next_write_address(bus) busx_inc_write_address(bus, 1)
#define busx_set_mask(bus, mask) bus##_sel = mask

typedef uintN(SDRAM_BUS_BITS) bus_data_t; //FIXME: should be parametrizable

#define wb_busmater(bus) \
  uint1& 		bus##_cyc, \
  uint1& 		bus##_stb, \
  uint32& 		bus##_adr_w, \
  uint32& 		bus##_adr_r, \
  uint1& 		bus##_we, \
  uintN(SDRAM_BUS_BITS)&	bus##_dat_w, \
  uint16& 		bus##_sel, \
  const uint1&	bus##_r_ack, \
  const uint1&	bus##_w_ack, \
  const uintN(SDRAM_BUS_BITS)&	bus##_dat_r
#define busx_master(bus) wb_busmater(bus)
#endif //bus_master

//assumes name is "bus"
#define bus_setup32() busx_setup32(bus)
#define bus_acquire() busx_acquire(bus)
#define bus_release() busx_release(bus)
#define bus_reading() busx_reading(bus)
#define bus_writing() busx_writing(bus)
#define bus_write_done() busx_write_done(bus)
#define bus_read_done() busx_read_done(bus)
#define bus_write_start(data)  busx_write_start(bus, data)
#define bus_read_start() busx_read_start(bus)
#define bus_read_data() busx_read_data(bus)
#define bus_stop() busx_stop(bus)
#define bus_set_write_address(a) busx_set_write_address(bus, a)
#define bus_set_read_address(a) busx_set_read_address(bus, a)
#define bus_get_read_address() busx_get_read_address(bus)
#define bus_get_write_address() busx_get_write_address(bus)
#define bus_set_mask(mask) busx_set_mask(bus, mask)
#define bus_master(bus) busx_master(bus)
#define bus_next_write_address() busx_next_write_address(bus)
#define bus_next_read_address() busx_next_read_address(bus)
#define bus_inc_read_address(a) busx_inc_read_address(bus, a)
#define bus_inc_write_address(a) busx_inc_write_address(bus, a)

//helpers
#define bus_bytes() (bus_bits()>>3)
#define bus_write_pending() (bus_writing() && !bus_write_done())
#define bus_read_pending() (bus_reading() && !bus_write_done())
#define bus_ready() (!bus_write_pending() && !bus_read_pending())

#endif
