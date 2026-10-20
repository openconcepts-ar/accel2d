# Copyright (C) 2026 Victor Suarez Rovere <suarezvictor@gmail.com>

from umachine import Pin, SoftI2C

# Create Pins.
#scl = Pin(0, Pin.OUT) #FPGA SCL north
#sda = Pin(1, Pin.OUT) #FPGA SDA north
scl = Pin(2, Pin.OUT) #FPGA SCL2 south
sda = Pin(3, Pin.OUT) #FPGA SDA2 south

# Create I2C.
i2c = SoftI2C(scl, sda, freq=100000)

# Scan I2C.
scan = i2c.scan()
I2C_ADDR = 0x5c #IT6251 default address: 0x5D in custom board, 0x5C in vendor one
LVDS_ADDR = 0x5e #LVDS address (to be configured)

assert(I2C_ADDR in scan)

# Register definitions according to:
# https://github.com/xobs/novena-linux/blob/v4.4-novena/drivers/gpu/drm/bridge/it6251.c#L277

IT6251_VENDOR_ID_LOW				= 0x00
IT6251_VENDOR_ID_HIGH				= 0x01
IT6251_DEVICE_ID_LOW				= 0x02
IT6251_DEVICE_ID_HIGH				= 0x03
IT6251_SYSTEM_STATUS				= 0x0d
IT6251_SYSTEM_STATUS_RINTSTATUS			= (1 << 0)
IT6251_SYSTEM_STATUS_RHPDSTATUS			= (1 << 1)
IT6251_SYSTEM_STATUS_RVIDEOSTABLE		= (1 << 2)
IT6251_SYSTEM_STATUS_RPLL_IOLOCK		= (1 << 3)
IT6251_SYSTEM_STATUS_RPLL_XPLOCK		= (1 << 4)
IT6251_SYSTEM_STATUS_RPLL_SPLOCK		= (1 << 5)
IT6251_SYSTEM_STATUS_RAUXFREQ_LOCK		= (1 << 6)
IT6251_REF_STATE				= 0x0e
IT6251_REF_STATE_MAIN_LINK_DISABLED		= (1 << 0)
IT6251_REF_STATE_AUX_CHANNEL_READ		= (1 << 1)
IT6251_REF_STATE_CR_PATTERN			= (1 << 2)
IT6251_REF_STATE_EQ_PATTERN			= (1 << 3)
IT6251_REF_STATE_NORMAL_OPERATION		= (1 << 4)
IT6251_REF_STATE_MUTED				= (1 << 5)
IT6251_RPC_REQ					= 0x2b
IT6251_RPC_REQ_RPC_FIFOFULL			= (1 << 6)
IT6251_RPC_REQ_RPC_FIFOEMPTY			= (1 << 7)

IT6251_REG_PCLK_CNT_LOW				= 0x57
IT6251_REG_PCLK_CNT_HIGH			= 0x58

IT6251_REG_LVDS_PORT_ADDR			= 0xfd
IT6251_REG_LVDS_PORT_CTRL			= 0xfe
IT6251_REG_LVDS_PORT_CTRL_EN			= (1 << 0)

# Start configuration
i2c.writeto_mem(I2C_ADDR, 0x05, b'\xFF') #reset
i2c.writeto_mem(I2C_ADDR, 0x05, b'\x00')
scan = i2c.scan()
assert(LVDS_ADDR not in scan)

# Check device present
vendor_device = i2c.readfrom_mem(I2C_ADDR, IT6251_VENDOR_ID_LOW,  4)
assert(vendor_device == b'\x15\xcaQb')

# Enable I2C port for LVDS
i2c.writeto_mem(I2C_ADDR, 0xFD, b'\xBC')
i2c.writeto_mem(I2C_ADDR, 0xFE, b'\x01')
scan = i2c.scan()
assert(LVDS_ADDR in scan)

# Configuration for 1366x768 
i2c.writeto_mem(LVDS_ADDR, 0x05, b'\xFF') #reset
i2c.writeto_mem(LVDS_ADDR, 0x05, b'\x00')
i2c.writeto_mem(LVDS_ADDR, 0x3B, b'\x42')
i2c.writeto_mem(LVDS_ADDR, 0x3B, b'\x43')
i2c.writeto_mem(LVDS_ADDR, 0x3C, b'\x08')
i2c.writeto_mem(LVDS_ADDR, 0x0B, b'\x88')
i2c.writeto_mem(LVDS_ADDR, 0x2C, b'\x40')
i2c.writeto_mem(LVDS_ADDR, 0x32, b'\x04')
i2c.writeto_mem(LVDS_ADDR, 0x35, b'\xE0')
i2c.writeto_mem(LVDS_ADDR, 0x2B, b'\x24')
i2c.writeto_mem(LVDS_ADDR, 0x05, b'\x02')
i2c.writeto_mem(LVDS_ADDR, 0x05, b'\x00')

i2c.writeto_mem(I2C_ADDR, 0x16, b'\x00')
i2c.writeto_mem(I2C_ADDR, 0x23, b'\x40')
i2c.writeto_mem(I2C_ADDR, 0x5C, b'\xF3')
i2c.writeto_mem(I2C_ADDR, 0x5F, b'\x06')
i2c.writeto_mem(I2C_ADDR, 0x60, b'\x00')
i2c.writeto_mem(I2C_ADDR, 0x61, b'\x00')
i2c.writeto_mem(I2C_ADDR, 0x62, b'\x00')
i2c.writeto_mem(I2C_ADDR, 0xA0, b'\x00')
i2c.writeto_mem(I2C_ADDR, 0xC9, b'\xF5')
i2c.writeto_mem(I2C_ADDR, 0xCA, b'\x4D')
i2c.writeto_mem(I2C_ADDR, 0xCB, b'\x37')
i2c.writeto_mem(I2C_ADDR, 0xCE, b'\x60')
i2c.writeto_mem(I2C_ADDR, 0xD3, b'\x03')
i2c.writeto_mem(I2C_ADDR, 0xD4, b'\x45')
i2c.writeto_mem(I2C_ADDR, 0xE7, b'\xA0')
i2c.writeto_mem(I2C_ADDR, 0xE8, b'\x33')
i2c.writeto_mem(I2C_ADDR, 0xEC, b'\x10')
i2c.writeto_mem(I2C_ADDR, 0x23, b'\x42')
i2c.writeto_mem(I2C_ADDR, 0x24, b'\x00')
i2c.writeto_mem(I2C_ADDR, 0x25, b'\x00')
i2c.writeto_mem(I2C_ADDR, 0x26, b'\x00')
i2c.writeto_mem(I2C_ADDR, 0x2B, b'\x00')
i2c.writeto_mem(I2C_ADDR, 0x23, b'\x40')
i2c.writeto_mem(I2C_ADDR, 0x17, b'\x01') # starts link training

#TODO: if link traning fails restart


