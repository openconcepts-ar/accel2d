// (C) 2024 Victor Suarez Rovere <suarezvictor@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-only

#ifndef __DRIVER_UART_H__
#define __DRIVER_UART_H__

#include "ioregs.h"

typedef enum
{
	UART_BOOT = 0,
	UART_COMM = 1,
	UART_DEBUG = 3,
} UART_dev_t;

void uart_probe(UART_dev_t uart_n);


int driver_uart_putc_wontblock(UART_dev_t uart_n);
void driver_uart_putc(UART_dev_t uart_n, char c);
int driver_uart_getc_wontblock(UART_dev_t uart_n);
int driver_uart_getc(UART_dev_t uart_n);

#endif //__DRIVER_UART_H__
