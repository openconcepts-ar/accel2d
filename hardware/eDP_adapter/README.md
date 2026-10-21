# LVDS to eDP

## Build in a first terminal
```
$ python3 ./gsd_orangecrab.py --with-gpio --pixel-bus-width=32 --timer-uptime --cpu-type=vexriscv --uart-baudrate 921600 --sys-clk-freq 75e6
```

In a second terminal:
```
$ cd micropython/ports/litex
$ . /sh/litex.sh #for riscv gcc
$ make BUILD_DIRECTORY=../../../build/gsd_orangecrab
$ litex_term /dev/ttyUSB1 --speed 921600 --kernel=build/firmware.bin
```
Back to the first terminal
```
$ openFPGALoader -c ft2232 build/gsd_orangecrab/gateware/gsd_orangecrab.bit
```

## ITE board

First terminal:
```
$ python3 micropython/tools/pyboard.py -d /dev/ttyUSB1 -b 921600 demos/micropython/i2c_it6251_test.py
```
(Or paste in the micropython REPL with Ctrl-E if file size is an issue)  
This activates the LVDS to eDP conversion and produces at the console:

```
Screen size: 34 x 19cm
Native resolutions:
	1366 x  768	71.1 MHz pixel clock
	1366 x  768	60.2 MHz pixel clock
reg0E = 90, Link Rate = HBR
reg0D = 3e,  HPD Video Stable
frequency = 34260000, xCnt = 807
Data Enable start: (71, 8)
The following is the current Modeline, not from EDID:
Modeline "1366x768@30_0" 34.260 1366 1400 1432 1469 768 772 774 778 +HSync +VSync
```
  
**Which is a truly correct modeline deduced from actual register values.**

# Smoke test
Step up for backlight outputs 11.85V (no-load).  
LDO 1.8V works.  
DC-DC for 3.3V display supply: outputs 1.2V since incorrect 100K/100K divider. Corrected by disabling the DC-DC and taking 3.3V from the main board using the jumper for that purpose (but is **not recommended** since extra current can make DRAM to not pass checks).  
I2C communication works (tested with FPGA board)  
