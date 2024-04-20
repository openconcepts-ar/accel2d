CROSS_COMPILE	?= riscv64-unknown-linux-gnu-

INCLUDES		:= -I../../ -I../../micropython/ports -I../../core_jpeg/c_model

ASFLAGS			:= -g -ggdb -Wall -O3
CFLAGS			:= -g -ggdb -Wall -O3
CPPFLAGS		:= -g -ggdb -Wall -O3
LDFLAGS			:= -T linker.ld -nostdlib
MCFLAGS			:= -march=rv64gcv0p7_zfh_xtheadc -mabi=lp64d -mtune=c906 -mcmodel=medlow -fno-stack-protector -mstrict-align
MCPPFLAGS		= $(MCFLAGS)

DEFINES		+=	-D__RISCV64__

ASFLAGS		+=	-ffunction-sections -fdata-sections -ffreestanding -std=gnu99 $(DEFINES)
CFLAGS		+=	-ffunction-sections -fdata-sections -ffreestanding -std=gnu99 $(DEFINES)
CPPFLAGS	+=	-ffunction-sections -fdata-sections -ffreestanding $(DEFINES) -fno-threadsafe-statics
LDFLAGS		+=	-Wl,-gc-sections

AS			:=	$(CROSS_COMPILE)gcc -x assembler-with-cpp
CC			:=	$(CROSS_COMPILE)gcc
CXX			:=	$(CROSS_COMPILE)g++
LD			:=	$(CROSS_COMPILE)ld
AR			:=	$(CROSS_COMPILE)ar
SZ			:=	$(CROSS_COMPILE)size
OC			:=	$(CROSS_COMPILE)objcopy
OD			:=	$(CROSS_COMPILE)objdump
MKDIR		:=	mkdir -p
CP			:=	cp -af
RM			:=	rm -fr
CD			:=	cd
FIND		:=	find
CPIO		:=	cpio -o -H newc --quiet


all: output.bin
	xfel ddr f133
	xfel write 0x40000000 output.bin
	xfel exec 0x40000000


output.bin: start.o main.o sys.o driver_uart.o driver_framebuffer.o memcpy.o memset.o printf.o rawdata.o sw_accel_cores.o c_model_jpeg_test.o
	@echo [LD] Linking $@
	@$(CC) $(LDFLAGS) $^ -o $@.elf -Wl,--cref,-Map=$@.map
	@echo [OC] Objcopying $@
	@$(OC) -O binary $@.elf $@
	@echo [SZ] Listing $@
	@$(SZ) $@.elf	

main.o: main.c
	@echo [CC] $<
	$(CC) $(INCLUDES) $(CFLAGS) $(MCFLAGS) -c $< -o$@

sys.o: sys.c
	@echo [CC] $<
	@$(CC) $(INCLUDES) $(CFLAGS) $(MCFLAGS) -c $< -o$@

driver_uart.o: driver_uart.c
	@echo [CC] $<
	@$(CC) $(INCLUDES) $(CFLAGS) $(MCFLAGS) -c $< -o$@

driver_framebuffer.o: driver_framebuffer.c
	@echo [CC] $<
	@$(CC) $(INCLUDES) $(CFLAGS) $(MCFLAGS) -c $< -o$@

printf.o: printf.c
	@echo [CC] $<
	@$(CC) $(INCLUDES) $(CFLAGS) $(MCFLAGS) -c $< -o$@

sw_accel_cores.o: sw_accel_cores.cpp
	@echo [CXX] $<
	@$(CXX) $(INCLUDES) $(CPPFLAGS) $(MCPPFLAGS) -c $< -o$@

c_model_jpeg_test.o: c_model_jpeg_test.cpp
	@echo [CXX] $<
	@$(CXX) $(INCLUDES) $(CPPFLAGS) $(MCPPFLAGS) -c $< -o$@

start.o: start.S
	@echo [AS] $<
	@$(AS) $(ASFLAGS) -I. -c $< -o $@

memcpy.o: memcpy.S
	@echo [AS] $<
	@$(AS) $(ASFLAGS) -I. -c $< -o $@

memset.o: memset.S
	@echo [AS] $<
	@$(AS) $(ASFLAGS) -I. -c $< -o $@

rawdata.o: rawdata.S splash640x480.data splash640x480.jpeg
	@echo [AS] $<
	@$(AS) $(ASFLAGS) -I. -c $< -o $@

clean:
	@$(RM) *.o output.bin* *.map
