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
  #for i in range(len(r)):
  #  if (i <= 0x0E or i >= 0x32) and i != 0x35: print("0x{0:02X}: 0x{1:02X}".format(i,r[i]))
  print(hex(TFP410_VID_LO)+"-"+hex(TFP410_V_RES_HI), r)

  print(hex(TFP410_CTL_1), "CTL_1_MODE:", hex(r[TFP410_CTL_1]))
  print("\tTDIS:\t", "TDMS disabled" if r[TFP410_CTL_1] & TFP410_CTL_1_TDIS else "TDMS enable as PD")
  print("\tVEN:\t",  "VSYNC as original" if r[TFP410_CTL_1] & TFP410_CTL_1_VEN else "VSYNC always low")
  print("\tHEN:\t",  "HSYNC as original" if r[TFP410_CTL_1] & TFP410_CTL_1_HEN else "HSYNC always low")
  print("\tDSEL:\t", (r[TFP410_CTL_1] & TFP410_CTL_1_DSEL) != 0)
  print("\tBSEL:\t", "24-bit single-edge" if r[TFP410_CTL_1] & TFP410_CTL_1_BSEL else "12-bit dual-edge")
  print("\tEDGE:\t", "rising IDCK+" if r[TFP410_CTL_1] & TFP410_CTL_1_EDGE else "falling IDCK+")
  print("\tnPD:\t",  "not power down" if r[TFP410_CTL_1] & TFP410_CTL_1_PD else "power down")

  print(hex(TFP410_CTL_2), "CTL_2_MODE:", hex(r[TFP410_CTL_2]))
  print("\tVLOW:\t",  "low-swing inputs" if r[TFP410_CTL_2] & TFP410_CTL_2_VLOW else "high-swing inputs")
  print("\tMSEL:\t", "Outputs " + ({0:"always high",1:"MDI",2:"RSEN",3:"HTPLG"}[(r[TFP410_CTL_2] & TFP410_CTL_2_MSEL_MASK) >> 4]))
  print("\tTSEL:\t", "HTPLG as interrupt" if r[TFP410_CTL_2] & TFP410_CTL_2_TSEL else "RSEN as interrupt")
  print("\tRSEN:\t", "receiver detected" if r[TFP410_CTL_2] & TFP410_CTL_2_RSEN else "receiver not detected")
  print("\tHTPLG:\t", "pin 9 high" if r[TFP410_CTL_2] & TFP410_CTL_2_HTPLG else "pin 9 low")
  print("\tMDI:\t",  "change detected" if r[TFP410_CTL_2] & TFP410_CTL_2_MDI else "no change")

  print(hex(TFP410_CTL_3), "CTL_3_MODE:", hex(r[TFP410_CTL_3]))
  print("\tDK:\t", "Step", ((r[TFP410_CTL_3] & TFP410_CTL_3_DK_MASK) >> 5) + 1)
  print("\tDKEN:\t", "de-skew as DK[3:1]" if r[TFP410_CTL_3] & TFP410_CTL_3_DKEN else "de-skew is disabled")
  print("\tCTL[2:1]:\t", (r[TFP410_CTL_3] & TFP410_CTL_3_CTL_MASK) >> 1)
  
  print(hex(TFP410_USERCFG), "CFG:\t", hex(r[TFP410_USERCFG]))

  print(hex(TFP410_DE_CTL), "DE_CTL:")
  print("\tDEGEN:\t", (r[TFP410_DE_CTL] & TFP410_DE_CTL_DEGEN) != 0)
  print("\tVSPOL:\t", (r[TFP410_DE_CTL] & TFP410_DE_CTL_VSPOL) != 0)
  print("\tHSPOL:\t", (r[TFP410_DE_CTL] & TFP410_DE_CTL_HSPOL) != 0)

  print(hex(TFP410_DE_DLY), "     DE_DLY:\t", r[TFP410_DE_DLY] | ((r[TFP410_DE_CTL] & TFP410_DE_CTL_DEDLY8)<<8))
  print(hex(TFP410_DE_TOP), "     DE_TOP:\t", r[TFP410_DE_TOP])
  print(hex(TFP410_DE_CNT_LO)+"-"+hex(TFP410_DE_CNT_HI), "DE_CNT:\t", int.from_bytes(r[TFP410_DE_CNT_LO:TFP410_DE_CNT_LO+2], 'little'))
  print(hex(TFP410_DE_LIN_LO)+"-"+hex(TFP410_DE_LIN_HI), "DE_LIN:\t", int.from_bytes(r[TFP410_DE_LIN_LO:TFP410_DE_LIN_LO+2], 'little'))
  
  print(hex(TFP410_H_RES_LO)+"-"+hex(TFP410_H_RES_HI), "H_RES:\t", int.from_bytes(r[TFP410_H_RES_LO:TFP410_H_RES_LO+2], 'little'))
  print(hex(TFP410_V_RES_LO)+"-"+hex(TFP410_V_RES_HI), "V_RES:\t", int.from_bytes(r[TFP410_V_RES_LO:TFP410_V_RES_LO+2], 'little'))

regs = readregs()
assert(len(regs)==62 and regs[0:4] == b'\x4c\x01\x10\x04') #test correct VEN_ID and DEV_ID

print("original register values")
dumpregs(regs)

"""
0x8 CTL_1_MODE: 0xbe
	TDIS:	 TDMS enable as PD
	VEN:	 VSYNC as original
	HEN:	 HSYNC as original
	DSEL:	 True
	BSEL:	 24-bit single-edge
	EDGE:	 rising IDCK+
	nPD:	 power down
0x9 CTL_2_MODE: 0x2
	VLOW:	 high-swing inputs
	MSEL:	 Outputs always high
	TSEL:	 RSEN as interrupt
	RSEN:	 receiver not detected
	HTPLG:	 pin 9 high
	MDI:	 no change
0xa CTL_3_MODE: 0x80
	DK:	 Step 5
	DKEN:	 de-skew is disabled
	CTL[2:1]:	 0
0xb CFG:	 0x80
0x33 DE_CTL:
	DEGEN:	 False
	VSPOL:	 False
	HSPOL:	 False
0x32      DE_DLY:	 0
0x34      DE_TOP:	 0
0x36-0x37 DE_CNT:	 0
0x38-0x39 DE_LIN:	 0
0x3a-0x3b H_RES:	 0
0x3c-0x3d V_RES:	 0
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

#HActive HSyncStart HSyncEnd HTotal VActive VSyncStart VSyncEnd VTotal HSync_pol VSync_pol
modelines = {"640x480@60Hz": [25.175e6, 640, 656, 752, 800, 480, 490, 492, 525, HSync_pol, VSync_pol]}
timings = modelines["640x480@60Hz"]

#DE_DLY, DE_TOP, DE_CNT, DE_LIN are only used if the DE generator is enabled in DE_CTL register
DE_DLY = timings[4]-timings[2] # pixels after HSYNC (sync width + back porch = HTotal-HSyncStart = 144)
DE_TOP = timings[8]-timings[6] # pixels after VSYNC (sync width + back porch = VTotal-VSyncStart = 35)
DE_CNT = timings[1] #HActive (640)
DE_LIN = timings[5] #VActive (480)
DE_CTL = (
	0*TFP410_DE_CTL_DEGEN			| #0: DE generator is disabled (signal required on DE pin)
	timings[10]*TFP410_DE_CTL_VSPOL	| #0: VSYNC is considered active low
	timings[ 9]*TFP410_DE_CTL_HSPOL	| #0: HSYNC is considered active low
	(DE_DLY >> 8) & TFP410_DE_CTL_DEDLY8  # DE_DLY[8] (top bit of DE_DLY)
)

i2c.writeto_mem(I2C_ADDR, TFP410_CTL_1, bytes([CTL_1_MODE, CTL_2_MODE, CTL_3_MODE]))

DUMMY_0x35 = 0 #undefined register
i2c.writeto_mem(I2C_ADDR, TFP410_DE_DLY, bytes([
  DE_DLY & 0xFF,
  DE_CTL, DE_TOP & 0xFF,
  DUMMY_0x35,
  DE_CNT & 0xFF,
  (DE_CNT >> 8) & 0x07,
  DE_LIN & 0xFF,
  (DE_LIN >> 8) & 0x07])
)

print("new register values")
regs = readregs()
dumpregs(regs)

