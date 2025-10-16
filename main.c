// This file is Copyright (c) 2023 Victor Suarez Rovere <suarezvictor@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-only

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <irq.h>
#include <uart.h>


typedef void (*func_ptr) (void);
extern func_ptr __init_array_start, __init_array_end;
extern func_ptr __fini_array_start, __fini_array_end;

static void _init_array(void)
{
  for (func_ptr *f = &__init_array_start; f != &__init_array_end; ++f)
    (*f)();
}
 
static void _fini_array(void)
{
  for (func_ptr *f = &__fini_array_start; f != &__fini_array_end; ++f)
    (*f)();
}

void graphics_app(void);

int main(int argc, char **argv)
{
  irq_setmask(0);
  irq_setie(1);

  uart_init();
  _init_array(); //call constructors and initializers
  void graphics_app(void);
  graphics_app();
  _fini_array();

  irq_setie(0);
  irq_setmask(~0);
    
  return 0;
}

void isr_handler(void)
{
  __attribute__((unused)) unsigned int irqs;
  irqs = irq_pending() & irq_getmask();

#ifndef UART_POLLING
  if(irqs & (1 << UART_INTERRUPT))
    uart_isr();
#endif

#if defined(TIMER0_INTERRUPT) && !defined(TIMER0_POLLING)
	if(irqs & (1 << TIMER0_INTERRUPT))
	{
		void timer0_isr(void);
		timer0_isr();
	}
#endif

}

// helpers -----------------------------------------------------------------------------------------
void _putchar(char c) { uart_write(c); } //this is to make printf work

void assert(int c)
{
  if(c)
    return;
  printf("ASSERTION FAILURE\n");
  for(;;);
}

int __errno; //FIXME: this is just to avoid linker errors
