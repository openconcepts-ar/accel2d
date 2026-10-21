# Copyright (C) 2026 Victor Suarez Rovere <suarezvictor@gmail.com>

from umachine import Pin, SoftI2C
import utime as time

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

# Check if device is present
vendor_device = i2c.readfrom_mem(I2C_ADDR, IT6251_VENDOR_ID_LOW, 4)
assert(vendor_device == b'\x15\xcaQb')

# Start configuration
i2c.writeto_mem(I2C_ADDR, 0x05, b'\xFF') #reset
i2c.writeto_mem(I2C_ADDR, 0x05, b'\x00')
scan = i2c.scan()
assert(LVDS_ADDR not in scan)

# Enable I2C port for LVDS
i2c.writeto_mem(I2C_ADDR, 0xFD, b'\xBC')
i2c.writeto_mem(I2C_ADDR, 0xFE, b'\x01')
scan = i2c.scan()
assert(LVDS_ADDR in scan)

# Configuration for 1366x768 TODO: use the above register definitions
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

time.sleep_ms(100) #wait link training TODO: poll status, if fails, retry

# EDID reading
# see https://github.com/xobs/it6251-dump-dptx/blob/master/it6251-dump-dptx.c

def dptx_auxwait():
  for i in range(200):
    c = i2c.readfrom_mem(I2C_ADDR, 0x2b, 1)[0]
    if (c & 0x20) != 0x20: return
    time.sleep_ms(1)

  print("ERROR: AUX Channel Hang => ")
  c = i2c.readfrom_mem(I2C_ADDR, 0x9f, 1)[0]
  c = c & 0x03
  if c == 0: print("No Error !!!\n")
  elif c == 1: print("Defer > 7 Times !!!\n")
  elif c == 2: print("Receive NAck Response !!!\n")
  else:
    print("TimeOut !!!\n")
  return c

EDID_SEG_WRITE = (0 << 6)
data = bytes([0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff])
for i in range(128-len(data)):
	# Enable PC Aux Access
	i2c.writeto_mem(I2C_ADDR, 0x23, bytes([EDID_SEG_WRITE | 0x02, i, 0, 0])) #24 bit address little-endian
	i2c.writeto_mem(I2C_ADDR, 0x2b, b'\x0b') # EDID Read Fire
	dptx_auxwait()
	i2c.writeto_mem(I2C_ADDR, 0x23, bytes([EDID_SEG_WRITE | 0]))
	data = data + i2c.readfrom_mem(I2C_ADDR, 0x2c, 1)

assert(len(data) == 128 and sum(data) % 256 == 0)

print('Screen size: %d x %dcm' % (data[21], data[22]))

# Dump resolutions
for n in range(1, 5):
  if n == 1: print("Native resolutions:")
  i = n * 18 + 36
  if data[i] != 0 or data[i+1] != 0:
    b = data[i:i+18]
    h = b[2] | ((b[4]&0xF0) << 4)
    v = b[5] | ((b[7]&0xF0) << 4)
    clk = (b[0] | (b[1]<<8)) / 100.0
    print('\t%4d x %4d\t%3.1f MHz pixel clock' % (h, v, clk))

def dptx_show_vid_info():
    sysstat = i2c.readfrom_mem(I2C_ADDR, 0x0d, 1)[0]
    linkstat = i2c.readfrom_mem(I2C_ADDR, 0x0e, 1)[0]

    if (linkstat & 0x1f) != 0x10:
        print("Link Training has something wrong, reg0E = %02x" % linkstat)
    else:
        print("reg0E = %02x, Link Rate = %s" %
              (linkstat, "HBR" if linkstat & 0x80 else "LBR"))

    print("reg0D = %02x, %s %s %s" % (
        sysstat,
        "Interrupt!" if sysstat & 0x01 else "",
        "HPD" if sysstat & 0x02 else "Unplug",
        "Video Stable" if sysstat & 0x04 else "Video Unstable"
    ))

    if not (sysstat & 0x04):
        return

    # Sync polarity / interlace
    reg = i2c.readfrom_mem(I2C_ADDR, 0xa0, 1)[0]
    hsync_pol = reg & 0x01
    vsync_pol = (reg & 0x04) >> 2
    interlaced = (reg & 0x10) >> 4

    # Horizontal timing
    htotal = int.from_bytes(i2c.readfrom_mem(I2C_ADDR, 0xa1, 2), 'little')
    hde = int.from_bytes(i2c.readfrom_mem(I2C_ADDR, 0xa3, 2), 'little')
    hactive = int.from_bytes(i2c.readfrom_mem(I2C_ADDR, 0xa5, 2), 'little')
    hfront_porch = int.from_bytes(i2c.readfrom_mem(I2C_ADDR, 0xa7, 2), 'little')
    hsync_len = int.from_bytes(i2c.readfrom_mem(I2C_ADDR, 0xa9, 2), 'little')

    # Vertical timing
    vtotal = int.from_bytes(i2c.readfrom_mem(I2C_ADDR, 0xab, 2), 'little')
    vde = int.from_bytes(i2c.readfrom_mem(I2C_ADDR, 0xad, 2), 'little')
    vactive = int.from_bytes(i2c.readfrom_mem(I2C_ADDR, 0xaf, 2), 'little')
    vfront_porch = int.from_bytes(i2c.readfrom_mem(I2C_ADDR, 0xb1, 2), 'little')
    vsync_len = int.from_bytes(i2c.readfrom_mem(I2C_ADDR, 0xb3, 2), 'little')

    # Determine frequency
    reg = i2c.readfrom_mem(I2C_ADDR, 0x12, 1)[0]
    i2c.writeto_mem(I2C_ADDR, 0x12, bytes([reg | 0x80]))
    time.sleep_ms(1)

    i2c.writeto_mem(I2C_ADDR, 0x12, bytes([reg & 0x7f]))
    counter = int.from_bytes(i2c.readfrom_mem(I2C_ADDR, 0x13, 2), 'little')

    assert(counter)
    crystal_freq = 27e6
    frequency_khz = (crystal_freq/2e3 * 2048) // counter

    print("frequency = %d, xCnt = %d" % (frequency_khz*1000, counter))
    print("Data Enable start: (%d, %d)" % (hde, vde))

    # Calculate back porch
    hback_porch = htotal - hactive - hfront_porch - hsync_len
    vback_porch = vtotal - vactive - vfront_porch - vsync_len

    refresh_hz = frequency_khz * 1000.0 / (htotal * vtotal)
    print("The following is the current Modeline, not from EDID:")
    print(
        'Modeline "%dx%d@%s" %.3f %d %d %d %d %d %d %d %d %cHSync %cVSync%s'
        % (
            hactive,
            vactive,
            ("%.1f" % refresh_hz).replace('.', '_'),
            frequency_khz / 1000.0,

            hactive,
            hactive + hback_porch,
            hactive + hback_porch + hfront_porch,
            htotal,

            vactive,
            vactive + vback_porch,
            vactive + vback_porch + vfront_porch,
            vtotal,

            '-' if hsync_pol else '+',
            '-' if vsync_pol else '+',
            ' Interlace' if interlaced else ''
        )
    )

dptx_show_vid_info()
