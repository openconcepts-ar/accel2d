# Copyright (C) 2024 Victor Suarez Rovere <suarezvictor@gmail.com>
# SPDX-License-Identifier: AGPL-3.0-only

from umachine import SoftI2C

#in the CPU board, SCL is PE12, SDA is PE13 (maps respectively to VGA pins 15 and 12)
i2c = SoftI2C(scl=12, sda=13, freq=100000)
scan = i2c.scan() #VGA DDC returns 0x37, 0x49, 0x50, 0x59

assert(0x50 in scan)
bytes = i2c.readfrom(0x50, 128)
assert(len(bytes) == 128 and sum(bytes) % 256 == 0) #CRC check

for i in range(38, 54, 2):
  if i == 38: print("\nStandard resolutions:")
  if bytes[i] != 1 or bytes[i+1] != 1:
    xres = (bytes[i]+31)*8
    aspect = [(16, 10), (4, 3), (5, 4), (16, 9)][bytes[i+1] >> 6]
    yres = xres * aspect[1] / aspect[0]
    vfreq = (bytes[i+1] & 63) + 60
    #print('  X res: %d, aspect %d:%d, Y res (derived): %d), vertical frequency: %d' % (xres, aspect[0], aspect[1], yres, vfreq))
    print('\t%4d x %4d\t@ %d Hz refresh' % (xres, yres, vfreq))

for n in range(1, 5):
  if n == 1: print("\nNative resolutions:")
  i = n * 18 + 36
  if bytes[i] != 0 or bytes[i+1] != 0:
    b = bytes[i:i+18]
    h = b[2] | ((b[4]&0xF0) << 4)
    v = b[5] | ((b[7]&0xF0) << 4)
    clk = (b[0] | (b[1]<<8)) / 100.0
    print('\t%4d x %4d\t%3.1f MHz pixel clock' % (h, v, clk))

print('\nScreen size: %d x %dcm' % (bytes[21], bytes[22]))

