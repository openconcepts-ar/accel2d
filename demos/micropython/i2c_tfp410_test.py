# Copyright (C) 2024 Victor Suarez Rovere <suarezvictor@gmail.com>
# SPDX-License-Identifier: AGPL-3.0-only

from umachine import SoftI2C

#in the CPU board, SCL is PE12, SDA is PE13 (maps respectively to TFP410 pins 15 and 14)
i2c = SoftI2C(scl=12, sda=13, freq=100000)
scan = i2c.scan()
I2C_ADDR = 0x38
assert(I2C_ADDR in scan)


#see https://github.com/torvalds/linux/blob/master/drivers/gpu/drm/i915/display/dvo_tfp410.c
TFP410_VID=		0x014C
TFP410_DID=		0x0410

TFP410_VID_LO=	0x00
TFP410_VID_HI=	0x01
TFP410_DID_LO=	0x02
TFP410_DID_HI=	0x03
TFP410_REV=		0x04

TFP410_CTL_1=		0x08
TFP410_CTL_1_TDIS=	(1<<6)
TFP410_CTL_1_VEN=	(1<<5)
TFP410_CTL_1_HEN=	(1<<4)
TFP410_CTL_1_DSEL=	(1<<3)
TFP410_CTL_1_BSEL=	(1<<2)
TFP410_CTL_1_EDGE=	(1<<1)
TFP410_CTL_1_PD=	(1<<0)

TFP410_CTL_2=		0x09
TFP410_CTL_2_VLOW=	(1<<7)
TFP410_CTL_2_MSEL_MASK=	(0x7<<4)
TFP410_CTL_2_MSEL=	(1<<4)
TFP410_CTL_2_TSEL=	(1<<3)
TFP410_CTL_2_RSEN=	(1<<2)
TFP410_CTL_2_HTPLG=	(1<<1)
TFP410_CTL_2_MDI=	(1<<0)

TFP410_CTL_3=		0x0A
TFP410_CTL_3_DK_MASK=	(0x7<<5)
TFP410_CTL_3_DK=	(1<<5)
TFP410_CTL_3_DKEN=	(1<<4)
TFP410_CTL_3_CTL_MASK=	(0x7<<1)
TFP410_CTL_3_CTL=	(1<<1)

TFP410_USERCFG=		0x0B

TFP410_DE_DLY=		0x32

TFP410_DE_CTL=		0x33
TFP410_DE_CTL_DEGEN=(1<<6)
TFP410_DE_CTL_VSPOL=(1<<5)
TFP410_DE_CTL_HSPOL=(1<<4)
TFP410_DE_CTL_DEDLY8=(1<<0)

TFP410_DE_TOP=		0x34

TFP410_DE_CNT_LO=	0x36
TFP410_DE_CNT_HI=	0x37

TFP410_DE_LIN_LO=	0x38
TFP410_DE_LIN_HI=	0x39

TFP410_H_RES_LO=	0x3A
TFP410_H_RES_HI=	0x3B

TFP410_V_RES_LO=	0x3C
TFP410_V_RES_HI=	0x3D


def readregs():
  return i2c.readfrom_mem(I2C_ADDR, 0,  0x3D+1) #read 62 bytes

def dumpregs(r):
  for i in range(len(r)):
    if (i <= 0x0E or i >= 0x32) and i != 0x35: print("0x{0:02X}: 0x{1:02X}".format(i,r[i]))

  print("CTL_1_MODE:")
  print("\tTDIS:\t", (r[TFP410_CTL_1] & TFP410_CTL_1_TDIS) != 0)
  print("\tVEN:\t",  (r[TFP410_CTL_1] & TFP410_CTL_1_VEN) != 0)
  print("\tHEN:\t",  (r[TFP410_CTL_1] & TFP410_CTL_1_HEN) != 0)
  print("\tDSEL:\t", (r[TFP410_CTL_1] & TFP410_CTL_1_DSEL) != 0)
  print("\tBSEL:\t", (r[TFP410_CTL_1] & TFP410_CTL_1_BSEL) != 0)
  print("\tEDGE:\t", (r[TFP410_CTL_1] & TFP410_CTL_1_EDGE) != 0)
  print("\tnPD:\t",  (r[TFP410_CTL_1] & TFP410_CTL_1_PD) != 0)

  print("CTL_2_MODE:")
  print("\tVLOW:\t", (r[TFP410_CTL_2] & TFP410_CTL_2_VLOW) != 0)
  print("\tMSEL:\t", (r[TFP410_CTL_2] & TFP410_CTL_2_MSEL_MASK) >> 4)
  print("\tTSEL:\t", (r[TFP410_CTL_2] & TFP410_CTL_2_TSEL) != 0)
  print("\tRSEN:\t", (r[TFP410_CTL_2] & TFP410_CTL_2_RSEN) != 0)
  print("\tHTPLG:\t", (r[TFP410_CTL_2] & TFP410_CTL_2_HTPLG) != 0)
  print("\tMDI:\t",  (r[TFP410_CTL_2] & TFP410_CTL_2_MDI) != 0)

  print("CTL_3_MODE:")
  print("\tDK:\t", (r[TFP410_CTL_3] & TFP410_CTL_3_DK_MASK) >> 5)
  print("\tDKEN:\t", (r[TFP410_CTL_3] & TFP410_CTL_3_DKEN) != 0)
  print("\tCTL:\t", (r[TFP410_CTL_3] & TFP410_CTL_3_CTL_MASK) >> 1)
  
  print("CFG:\t", hex(r[TFP410_USERCFG]))

  print("DE_DLY w/bit 8:\t", r[TFP410_DE_DLY] | ((r[TFP410_DE_CTL] & TFP410_DE_CTL_DEDLY8)<<8))

  print("DE_CTL:")
  print("\tDEGEN:\t", (r[TFP410_DE_CTL] & TFP410_DE_CTL_DEGEN) != 0)
  print("\tVSPOL:\t", (r[TFP410_DE_CTL] & TFP410_DE_CTL_VSPOL) != 0)
  print("\tHSPOL:\t", (r[TFP410_DE_CTL] & TFP410_DE_CTL_HSPOL) != 0)

  print("DE_TOP:\t", r[TFP410_DE_TOP])
  
  print("DE_CNT:\t", int.from_bytes(r[TFP410_DE_CNT_LO:TFP410_DE_CNT_LO+2], 'little'))
  print("DE_LIN:\t", int.from_bytes(r[TFP410_DE_LIN_LO:TFP410_DE_LIN_LO+2], 'little'))
  
  print("H_RES:\t", int.from_bytes(r[TFP410_H_RES_LO:TFP410_H_RES_LO+2], 'little'))
  print("V_RES:\t", int.from_bytes(r[TFP410_V_RES_LO:TFP410_V_RES_LO+2], 'little'))

regs = readregs()
assert(len(regs)==62 and regs[0:4] == b'\x4c\x01\x10\x04') #test correct VEN_ID and DEV_ID

print("original register values")
dumpregs(regs)

"""
values of register without a hardware reset
0x00: 0x4C VEN_ID_LO
0x01: 0x01 VEN_ID_HI
0x02: 0x10 DEV_ID_LO
0x03: 0x04 DEV_ID_HI
0x04: 0x00 REV_ID
0x05: 0x00 RESERVED
0x06: 0x14 RESERVED
0x07: 0x64 RESERVED
0x08: 0xBA CTL_1_MODE
0x09: 0x02 CTL_2_MODE
0x0A: 0x90 CTL_3_MODE
0x0B: 0x80 CFG
0x0C: 0xA1 RESERVED
0x0D: 0x0B RESERVED
0x0E: 0x85 RESERVED
0x32: 0x08 DE_DLY
0x33: 0x00 DE_CTL
0x34: 0x00 DE_TOP
0x36: 0x10 DE_CNT_LO
0x37: 0x00 DE_CNT_HI
0x38: 0x00 DE_LIN_LO
0x39: 0xA8 DE_LIN_HI
0x3A: 0x00 H_RES_LO
0x3B: 0x00 H_RES_HI
0x3C: 0x00 V_RES_LO
0x3D: 0x00 V_RES_HI
"""

#this is according to datasheet and board
CTL_1_MODE = (
  0*TFP410_CTL_1_TDIS	| #0: TMDS circuitry enable state is determined by PD
  1*TFP410_CTL_1_VEN	| #1: VSYNC input is transmitted in its original state
  1*TFP410_CTL_1_HEN	| #1: HSYNC input is transmitted in its original state
  0*TFP410_CTL_1_DSEL	| #0: In the high-swing mode it is a don’t care (IDCK is single-ended)
  1*TFP410_CTL_1_BSEL	| #1: 24-bit operation with single-edge clock
  1*TFP410_CTL_1_EDGE	| #1: Input data latches to the rising edge of IDCK+
  1*TFP410_CTL_1_PD		  #1: Normal operation (power up)
)

CTL_2_MODE = (  #VLOW, RSEN and HTPLG are read only
  2*TFP410_CTL_2_MSEL	| #2: Outputs the RSEN bit (receiver detect)
  0*TFP410_CTL_2_TSEL	| #0: Interrupt bit (MDI) is generated by monitoring RSEN
  0*TFP410_CTL_2_MDI	  #0: Do not clear change in detection signal
)

CTL_3_MODE = (  #VLOW, RSEN and HTPLG are read only
  4*TFP410_CTL_3_DK		| #4: De-skew setting step 5 (default)
  0*TFP410_CTL_3_DKEN	| #0: Data de-skew is disabled, the values in DK[3:1] are not used
  0*TFP410_CTL_3_CTL	  # output on the DVI port during the blanking interval (3 bits)
)

#VESA and Industry Standards and Guidelines for Computer Display Monitor Timing (DMT)
#https://glenwing.github.io/docs/VESA-DMT-1.13.pdf
#note that cvt and gtf linux commands report different values than the VESA standard
"""
Timing Name = 640 x 480 @ 60Hz;
Pixel Clock = 25.175; // MHz = 39.7 nsec ± 0.5%
HSyncStart = Hor Sync Start (656)
HSyncEnd = Hor Sync Start (656) + Hor Sync Time (96) = 752
HTotal = Hor Total Time (800)
VSyncStart = Ver Sync Start (490)
VSyncEnd = Ver Sync Start (490) + Ver Sync Time (2) = 492
VTotal = Ver Total Time (525)
"""

HSync_pol = 0 #0: negative 1: positive
VSync_pol = 0 #0: negative 1: positive

#HDisplay HSyncStart HSyncEnd HTotal VDisplay VSyncStart VSyncEnd VTotal HSync_pol VSync_pol
modelines = {"640x480@60Hz": [25.175e6, 640, 656, 752, 800, 480, 490, 492, 525, HSync_pol, VSync_pol]}
timings = modelines["640x480@60Hz"]

#DE_DLY, DE_TOP, DE_CNT, DE_LIN are only used if the DE generator is enabled in DE_CTL register
DE_DLY = timings[4]-timings[2] # pixels after HSYNC (sync width + back porch = HTotal-HSyncStart = 144)
DE_TOP = timings[8]-timings[6] # pixels after VSYNC (sync width + back porch = VTotal-VSyncStart = 35)
DE_CNT = timings[1] #HDisplay (640)
DE_LIN = timings[5] #VDisplay (480)
DE_CTL = (
	0*TFP410_DE_CTL_DEGEN			| #0: DE generator is disabled (signal required on DE pin)
	timings[10]*TFP410_DE_CTL_VSPOL	| #0: VSYNC is considered active low
	timings[ 9]*TFP410_DE_CTL_HSPOL	| #0: HSYNC is considered active low
	(DE_DLY >> 8) & TFP410_DE_CTL_DEDLY8  # DE_DLY[8] (top bit of DE_DLY)
)

i2c.writeto_mem(I2C_ADDR, TFP410_CTL_1, bytes([CTL_1_MODE, CTL_2_MODE, CTL_3_MODE]))

DUMMY_0x35 = 0 #undefined register
i2c.writeto_mem(I2C_ADDR, TFP410_DE_DLY,
  bytes([DE_DLY & 0xFF, DE_CTL, DE_TOP & 0xFF, DUMMY_0x35, DE_CNT & 0xFF, (DE_CNT >> 8) & 0x07, DE_LIN & 0xFF, (DE_LIN >> 8) & 0x07]))


print("new register values")
regs = readregs()
dumpregs(regs)

