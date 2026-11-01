# (C) 2026 Victor Suarez Rovere <suarezvictor@gmail.com>
# Apache License 2.0

#ILITEK ILI2511/ILI2510 Touch panel test
#see https://github.com/Infineon/touch-ctp-ili2511
import utime as time

I2C_ADDR = 0x41

from umachine import SoftI2C
#i2c = SoftI2C(scl=12, sda=13, freq=100000) #F133 board
i2c = SoftI2C(scl=3, sda=2, freq=100000) #FPGA board south connector

scan = i2c.scan() #ILITEK IC reports 0x41, VGA DDC returns 0x37, 0x49, 0x50, 0x59
assert(I2C_ADDR in scan)

#Print firmware info
"""
MTB_CTP_ILI2511_CHIP_ID_POS                       (0U)
MTB_CTP_ILI2511_MAJOR_FIRMWARE_VER_POS            (1U)
MTB_CTP_ILI2511_MINOR_FIRMWARE_VER_POS            (2U)
MTB_CTP_ILI2511_RELEASE_FIRMWARE_VER_POS          (3U)
MTB_CTP_ILI2511_CUSTOMER_FIRMWARE_VER_BYTE_4_POS  (4U)
MTB_CTP_ILI2511_CUSTOMER_FIRMWARE_VER_BYTE_5_POS  (5U)
MTB_CTP_ILI2511_CUSTOMER_FIRMWARE_VER_BYTE_6_POS  (6U)
MTB_CTP_ILI2511_CUSTOMER_FIRMWARE_VER_BYTE_7_POS  (7U)
MTB_CTP_ILI2511_FIRMWARE_NUM_BYTES                (8U)
"""

assert(i2c.writeto(I2C_ADDR, b'\x40') == 1)
data = i2c.readfrom(I2C_ADDR, 8) # returns 0600000000000001, or b'06\x00\x00\x00$\x88!\x01' for ILI2510
#print("0x40:", data)
assert(len(data) == 8 and data[0]==0x06) 


assert(i2c.writeto(I2C_ADDR, b'\x20') == 1)
data = i2c.readfrom(I2C_ADDR, 9) # returns 0040004017290a0000, or b'\x00@\x80%<$\n\x00\x00' for 2510
assert(len(data) == 9)
#print("0x20:", data)


from framebuf import FrameBuffer, RGB32
import litex
video = litex.Video(0)
W, H = video.width(), video.height()
fbuf = FrameBuffer(video, W, H, RGB32, video.stride())
bg = 0x40FF00

# Main loop
while True:
    assert(i2c.writeto(I2C_ADDR, b'\x10') == 1)
    #time.sleep_ms(10) #there are about 100 reports per second anyways
    data = i2c.readfrom(I2C_ADDR, 32) #6*5+2
    assert(len(data) == 32)
    #print("0x10:", data)
    
    touch = {}
    count = 0
    for i in range(6): #coordinates range is 0 to 0x3FFF
        x = int.from_bytes(data[i*5+1:i*5+3], 'big') & 0x3FFF
        y = int.from_bytes(data[i*5+3:i*5+5], 'big') & 0x3FFF
        if x > 15000: continue #filter spurious touches TODO: identify cause
        press = (data[i*5+1] & 0x80) != 0
        if press:
            #print("ID", i, "at (", x, ",", y, ")")
    	    scantime = 0
    	    touch[i] = (x*W//16384, y*H//9600, press, scantime) #limits according to panel geometry
    	    count += 1
        #else: print("ID", i, "release")

    if count == 0:
        fbuf.fill(bg) # clears buffer to restart
    
    if count >= 2: #draw a line between the two fingers
        it = iter(touch.values())
        x0, y0, _, _ = next(it)
        x1, y1, _, _ = next(it)
        red = abs(255 - x0 - x1) & 0xFF
        blue = abs(255 - y0 - y1) & 0xFF
        green = red ^ blue
        fbuf.line(x0, y0, x1, y1, red | (green << 8) | (blue << 16))
        #print("frame", frame, "line", x0, y0, x1, y1)


