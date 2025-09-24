# This file is Copyright (c) 2023 Victor Suarez Rovere <suarezvictor@gmail.com>
# SPDX-License-Identifier: AGPL-3.0-only

APP_SRC?=blit_app#test_app#canvas_app

#BOARD?=digilent_arty
#BOARD?=lambdaconcept_ecpix5
BOARD?=gsd_orangecrab
#LATTICETOOLCHAIN=--toolchain diamond
LATTICETOOLCHAIN=--toolchain trellis --nextpnr-seed 0 --nextpnr-timingstrict 
SDRAM_BUS_BITS?=32
#SERIAL_PORT?=/dev/ttyUSB1 #for arty
SERIAL_PORT?=/dev/ttyUSB2 #for ecpix5/orangecrab
SERIAL_BAURDATE?=960000

#AMDTOOLCHAIN?=--toolchain=yosys+nextpnr #FIXME: some glitches
CPU_TYPE?=--cpu-type=vexriscv #only supports vexriscv
LATTICE_SYS_CLK?=--sys-clk-freq 75e6 --uart-baudrate $(SERIAL_BAURDATE) #ECP5 pass at 96 MHz if just rectangles, but glitches remains

include Makefile.common
include $(BUILD_DIR)/software/include/generated/variables.mak
include $(LITEX_ROOT)/litex/soc/software/common.mak

AGG_BASE_DIR=agg-2.4
INC=-I$(AGG_BASE_DIR)/include -I./freetype

CCDEFS=-DSDRAM_BUS_BITS=$(SDRAM_BUS_BITS)
CFLAGS+=$(CCDEFS) $(INC) -Wno-missing-prototypes
CXXFLAGS+=$(CCDEFS) $(INC) -fno-threadsafe-statics

SOCARGS=--pixel-bus-width=$(SDRAM_BUS_BITS) --timer-uptime $(CPU_TYPE)

#FIXME: try crt0 provided by LiteX
%.o: %.S
	$(assemble)

%.o: %.c
	$(compile)

%.o: %.cpp
	$(compilexx)

%.bin: %.elf
	$(OBJCOPY) -O binary $< $@
	chmod -x $@
	
prerequisites: LITEX-CONTRIBUTORS 

./build/digilent_arty/software/include/generated/variables.mak: ./digilent_arty.py
	$(PYTHON) ./digilent_arty.py $(SOCARGS) --no-compile-gateware

./build/digilent_arty/gateware/digilent_arty.bit: ./digilent_arty.py c2v
	$(PYTHON) ./digilent_arty.py $(SOCARGS) $(AMDTOOLCHAIN)

./build/lambdaconcept_ecpix5/software/include/generated/variables.mak: ./lambdaconcept_ecpix5.py
	$(PYTHON) ./lambdaconcept_ecpix5.py $(SOCARGS) $(LATTICE_SYS_CLK) --no-compile-gateware

./build/lambdaconcept_ecpix5/gateware/lambdaconcept_ecpix5.bit: ./lambdaconcept_ecpix5.py c2v
	$(PYTHON) ./lambdaconcept_ecpix5.py $(SOCARGS) $(LATTICE_SYS_CLK) $(LATTICETOOLCHAIN)

./build/gsd_orangecrab/software/include/generated/variables.mak: ./gsd_orangecrab.py
	$(PYTHON) ./gsd_orangecrab.py $(SOCARGS) $(LATTICE_SYS_CLK) --no-compile-gateware

./build/gsd_orangecrab/gateware/gsd_orangecrab.bit: ./gsd_orangecrab.py c2v
	$(PYTHON) ./gsd_orangecrab.py --build $(SOCARGS) $(LATTICE_SYS_CLK) # $(LATTICETOOLCHAIN)

everything: $(BOARD) #run

.PHONY: run
run: sim_linux
	./sim_linux

sim_linux: prerequisites sim_linux.c $(APP_SRC).cpp accel_cores.c sim_fb.c sw_cores.cpp $(APP_SRC).o sw_cores.o bmpimage.S
	g++ -O3 -m32 -ggdb -DDISABLE_HARDWARE_ACCEL $(CCDEFS) $(INC) -o sw_cores.o -c sw_cores.cpp
	g++ -O3 -m32 -ggdb -include stdint.h -DDISABLE_HARDWARE_ACCEL $(CCDEFS) $(INC) -o $(APP_SRC).o -c $(APP_SRC).cpp
	as --32 bmpimage.S -o bmpimage.o
	gcc -O3 -m32 -ggdb -DDISABLE_HARDWARE_ACCEL $(CCDEFS) $(INC) `sdl2-config --cflags` sim_linux.c $(APP_SRC).o sw_cores.o bmpimage.o -o $@ `sdl2-config --libs`
	rm sw_cores.o

.PHONY: firmware
firmware: main.bin


main.elf: prerequisites main.o $(APP_SRC).o accel_cores.o sw_cores.o fs.o bmpimage.o crt0.o linker.ld
	$(CX) crt0.o main.o $(APP_SRC).o accel_cores.o sw_cores.o fs.o bmpimage.o -march=rv32im -mabi=ilp32 -nostartfiles -L$(BUILDINC_DIRECTORY) -T linker.ld -Xlinker -Map=$@.map -N -o $@ \
		$(PACKAGES:%=-L$(BUILD_DIR)/software/%) $(LIBS:lib%=-l%)


.PHONY: digilent_arty
digilent_arty: $(BUILD_DIR)/gateware/digilent_arty.bit
	openFPGALoader -b arty $(BUILD_DIR)/gateware/digilent_arty.bit

.PHONY: lambdaconcept_ecpix5
lambdaconcept_ecpix5: $(BUILD_DIR)/gateware/lambdaconcept_ecpix5.bit
	openFPGALoader -b ecpix5 --cable ft4232 --freq 30e6 $(BUILD_DIR)/gateware/lambdaconcept_ecpix5.bit
	#this is only for diamond toolchain:
	#PYTHONPATH=/media/vsuarez/elocaldata/SCRATCH/prjtrellis/libtrellis $(PYTHON) ecp5_patch_idcode.py
	#openFPGALoader -b ecpix5 --cable ft4232 --freq 30e6 repack.bit #$(BUILD_DIR)/gateware/lambdaconcept_ecpix5.bit

gsd_orangecrab: $(BUILD_DIR)/gateware/gsd_orangecrab.bit
	@echo "LOAD bitstream:" openFPGALoader -c ft2232 $(BUILD_DIR)/gateware/gsd_orangecrab.bit

.PHONY: upload
upload: firmware #$(BOARD)
	$(LITEX_ROOT)/litex/tools/litex_term.py $(SERIAL_PORT) --kernel main.bin --speed $(SERIAL_BAURDATE)

.PHONY: clean
clean:
	$(RM) -R build restore
	$(RM) *.o *.d *.elf *.elf.map *.bin ellipse_fill32.v rectangle_fill32.v *.v.* sim_linux backup.tar.gz *.orig

LITEX-CONTRIBUTORS:
	wget -O $@ https://raw.githubusercontent.com/enjoy-digital/litex/master/CONTRIBUTORS

