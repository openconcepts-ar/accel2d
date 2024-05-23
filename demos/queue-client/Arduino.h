// (C) 2024 Victor Suarez Rovere <suarezvictor@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-only

//basic implementation of Wiring API for Attiny85

#ifndef __ARDUINO_H__
#define __ARDUINO_H__

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include <stdio.h>

#ifndef F_CPU
#error F_CPU not defined (should be in Hz)
#endif

#ifndef UART_TX_PIN
#define UART_TX_PIN PB1
#endif

static inline void digitalWrite(int pin, int value)
{
	if(value)
		PORTB |= (1 << pin);
	else  
        PORTB &= ~(1 << pin);
}

static inline int digitalRead(int pin)
{
	return (PINB & (1 << pin)) != 0;
}

enum HI_LO { LOW=0, HIGH };
enum PIN_MODE { INPUT, OUTPUT, INPUT_PULLUP };
#define delay(x) _delay_ms(x)
#define delayMicroseconds(x) _delay_us(x) //FIXME: requires constant as argument

static inline void pinMode(int pin, int mode)
{
	switch(mode)
	{
		case OUTPUT:
		    DDRB |= (1 << pin);
		    break;
		case INPUT_PULLUP:
			PORTB |= (1 << pin);
			//fall back
		case INPUT:
		    DDRB &= ~(1 << pin);
		    break;
	}
}

static int uart_baudrate;
void uart_init(int baudrate)
{
    pinMode(UART_TX_PIN, OUTPUT);
    digitalWrite(UART_TX_PIN, HIGH);
    uart_baudrate = baudrate;
}

static void uart_bit_delay(void)
{
	switch(uart_baudrate)
	{
		case 9600: delayMicroseconds(1000000ul/9600); break;
		case 115200: delayMicroseconds(1000000ul/115200); break;
	}
}

int uart_transmit(uint8_t data)
{
    // Start bit
    digitalWrite(UART_TX_PIN, LOW);
    uart_bit_delay();

    // Transmit 8 data bits
    for (uint8_t i = 0; i < 8; i++)
    {
        digitalWrite(UART_TX_PIN, data & 0x01);
        uart_bit_delay();
        data >>= 1;
    }

    // Stop bit
    digitalWrite(UART_TX_PIN, HIGH);
    uart_bit_delay();
    
    return 0;
}


struct SoftwareSerial
{
	void (*begin)(int);
	void (*write)(uint8_t);
} static Serial =
{
	.begin = uart_init,
	.write = uart_transmit,
};

static int uart_putc(char ch, FILE *stream) { uart_transmit(ch); return 0; }
static int uart_getc(FILE *stream) { return -1; }

FILE uart_output = FDEV_SETUP_STREAM(uart_putc, NULL, _FDEV_SETUP_WRITE);
FILE uart_input = FDEV_SETUP_STREAM(NULL, uart_getc, _FDEV_SETUP_READ);
FILE uart_io = FDEV_SETUP_STREAM(uart_putc, uart_getc, _FDEV_SETUP_RW);

static void init(void)
{
    stdout = &uart_output;
    stdin  = &uart_input;
}

void setup();
void loop();

int main(void)
{
	init();
	setup();
	for(;;)
		loop();
    return 0;
}
#endif
