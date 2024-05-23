// (C) 2024 Victor Suarez Rovere <suarezvictor@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-only

#include "Arduino.h"

#define BUTTON_PIN PB2
#define A0_PIN PB3
#define A1_PIN PB4
#define A2_PIN PB0

void setup()
{
	Serial.begin(9600);
	pinMode(A0_PIN, OUTPUT);
	pinMode(A1_PIN, OUTPUT);
	pinMode(A2_PIN, OUTPUT);
	pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop()
{
	for(int i = 0; i < 8; ++i) //scans keys
	{
		digitalWrite(A0_PIN, i & 1);
		digitalWrite(A1_PIN, i & 2);
		digitalWrite(A2_PIN, i & 4);

		if(digitalRead(BUTTON_PIN))
			Serial.write(i+'0'); //outputs digit
	}
	delay(100); //debounce time
}


