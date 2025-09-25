# BLITTING CORE
## Simultaneous access to multiple buses from a same accelerator core

This accelerator core permits to copy a block of pixels from a region to another (for example to draw a bitmap in residing in main memory), optionally colorized, and with rectangle fill mode which also allows optional alpha blending.  
The accelerator allows performance improvements of **2X to 10X** depending on mode, with room for more optimizations.

## Interface
As can be appreciated below, parameters src_base and dst_base respectively select source and destination:
```
    MODULE line32a(
      bus_master(bus),
      const int16&	dx,
      const int16&	dy,
      const uint32&	rgba, //color to add
      const uint32&	tint, //source color multiply factor
      const busaddr_t& dst_base,
      const int16& dst_xstride, //normally 1, but can run backwards
      const int16& dst_ystride, //pixels to skip for next line (usually the framebuffer width)
      const busaddr_t& src_base,
      const int16& src_xstride,
      const int16& src_ystride
      )
```
See core's source [line32a.cc](./line32a.cc)
    
Paramenter _tint_ optionally colorizes the source, that means, multiply each color channel by a "tint" coefficient.
Parameter _rgba_ is added to the destination (assumed with pre-multiplied alpha). The combinations allows the following interesting modes:

1. Solid color fill
2. Solid color with alpha blend
3. Bitmap draw as-is, and
4. Colorized bitmap draw (tinted)

The code of the accelerator implementation reflects that conditions to optimize access to the buses (i.e. no source reads when color fill).  
Since the algoritm to select destination pixel coordinates is based on a line drawing algorithm, oblique or vertical lines can be drawn too.  
  
For usage and options, see [blit_app.cpp](./blit_app.cpp), a demo showing the different modes of this accelerator.  
It produces this image:  

![blit_app.png](./doc/blit_app.png)


## FPGA implementation

See [accel_glue.py](./accel_glue.py) a call to connect_accel_to_native in [wpu.py](./wpu.py), which is based in ConverterWriteCache, using WriteBackCache for cached access.  
Two _native_ ports to the DRAM are used, one for reading the other for writing.  
For usage from firmware, see accel_linea in [accel_cores.c](./accel_cores.c), where registers in the FPGA are set in correspondence with the FPGA core registers.  


## Running

1) Create the bitstream for the FPGA board:  
set APP_SRC=blit_app in Makefile
```
    make clean
    make
```
    
2) prepare to load firmware  
```
    make firmware
    make upload #see below
```
    
Optionally you can copy the main.bin file to the flash memory as boot.bin, and it will run automaticaly at boot (requires --write-flash argument in openFPGALoader command)

3) LOAD bitstream (will actually upload firmware when done)  
```
    openFPGALoader -c ft2232 ./build/gsd_orangecrab/gateware/gsd_orangecrab.bit
```

or its quite cool [web interface](https://ofl.trabucayre.com/).

## Software simuation

As always with this project, the graphic core can be run in software mode (using same C code), command for this is just:
```
    make run
```


## Relevant sources changes

* [accel.py](./accel.py): AccelImporterSoC class, it instances a 2nd port for simultaneous read-write access to main RAM
* [line32a.cc](./line32a.cc): actual accelerator core (as always in this project, capable of running as software or transpiled to verilog)
* [accel_line32a.inl](./accel_line32a.inl): line32a memory-mapped registers layout
* [wpy.py](./wpy.py): updated accelerator interface
* [gsd_orangecrab.py](./gsd_orangecrab.py): Bitstream genration for custom board, direct instancing of the accelerator
* [accel_cores.c](./accel_cores.c): accel_linea function, it calls the hardware acellerated version of line draw which simultaneously access two DRAM ports
* [sw_cores.cpp](./sw_cores.cpp): software implementation (based on same line32a.cc code)
* [bus.h](./bus.h): add macros to allow access to simultaneous ports in accelerators implementations
* [blit_app.cpp](./blit_app.cpp): main testing application

