// (C) 2024 Victor Suarez Rovere <suarezvictor@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-only

#ifndef __DRIVER_UART_H__
#define __DRIVER_UART_H__

int driver_uart_putc_wontblock(void);
void driver_uart_putc(char c);
int driver_uart_getc_wontblock(void);
int driver_uart_getc(void);

#endif //__DRIVER_UART_H__
