// This file is Copyright (c) 2023 Victor Suarez Rovere <suarezvictor@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-only

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <irq.h>
#include <uart.h>

#include "misc.h" //just for ACCEL_STATIC_ASSERT
#include "accel_cores.h"
#include "graphics.h"


void isr_handler(void)
{
  __attribute__((unused)) unsigned int irqs;
  irqs = irq_pending() & irq_getmask();

#ifndef UART_POLLING
  if(irqs & (1 << UART_INTERRUPT))
    uart_isr();
#endif
}

// helpers -----------------------------------------------------------------------------------------

void _putchar(char c) { uart_write(c); } //this is to make printf work
extern uint8_t __heap_start[];
extern uint8_t __heap_end[];

void assert(int c)
{
  if(c)
    return;
  printf("ASSERTION FAILURE\n");
  for(;;);
}

void timer_init(void)
{
  timer0_en_write(0);
  timer0_reload_write(0xFFFFFFFF); //reload value, to wrap around
  timer0_load_write(0xFFFFFFFF); //start value
  timer0_en_write(1);
}

uint64_t higres_ticks(void)
{
  timer0_update_value_write(1);
  static uint32_t last_read = 0;
  static uint32_t wrapcount = 0;
  uint32_t r = ~timer0_value_read(); //makes increasing
  wrapcount += (last_read > r); //assumes non-infrequent reading (less than about 20s at 100MHz)
  last_read = r;
  return ((uint64_t)wrapcount<<32) | r; 
}

uint64_t higres_ticks_freq(void) { return CONFIG_CLOCK_FREQUENCY; }

typedef union {
  uint32_t rgba;
  struct { uint32_t r:8; uint32_t g:8; uint32_t b:8; uint32_t a:8; };
} pix_t;

#define FRAMEBUFFER_CACHE_HANDLING
#include "drawing_test.c"

int main(int argc, char **argv)
{
  irq_setmask(0);
  irq_setie(1);

  uart_init();
  timer_init();

  printf("System freq %d MHz, framebuffer address %p, heap %p to %p\n\n", CONFIG_CLOCK_FREQUENCY/1000000, (void*)VIDEO_FRAMEBUFFER_BASE, __heap_start, __heap_end);
  printf("Enabled accelerators:\n");
  #ifdef CSR_ACCEL_RECTANGLE_FILL32_BASE
  printf("\tCSR_ACCEL_RECTANGLE_FILL32_BASE %p, vram %p\n", (void*)CSR_ACCEL_RECTANGLE_FILL32_BASE, (void*)VRAM_ORIGIN_ACCEL_RECTANGLE_FILL32);
  #endif
  #ifdef CSR_ACCEL_ELLIPSE_FILL32_BASE
  printf("\tCSR_ACCEL_ELLIPSE_FILL32_BASE %p, vram %p\n", (void*)CSR_ACCEL_ELLIPSE_FILL32_BASE, (void*)VRAM_ORIGIN_ACCEL_ELLIPSE_FILL32);
  #endif

  int passed = (drawing_test() == 0);
  
  printf("\n==========================================\n");
  if(passed)
    printf("TESTS PASSED\n");
  else
    printf("*** TESTS FAILED ***\n");
  printf("==========================================\n");

  for(;;) //loop forever, passed or not, so results of test are visible
  {
    if(passed) 
      draw_clock(); //demo drawing
  }

  irq_setie(0);
  irq_setmask(~0);
    
  return 0;
}

