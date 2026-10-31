# Large display interactive demo

The test is carried on a 23.8" 1920x1080 high brigthness touch display (dual channel LVDS).

## Touch panel control

It uses a ICL2510P.C3.P3.V1 board to control the optically bonded touch panel.  
It can be accessed y USB or by I2C, but the latter lacks a connector, whose pinout is:
```
1.VDD
2.GND
3.SDA
4.SCL
5.INT
6.RST
```

Since it does not match the pinout of the passive LVDS board 2ch-8bit board, direct wiring was used.  
The touch boards doesn't populate pullups required by  I2C, so it uses the ones on-board on the controlling devices or if not, you can use internal ones ("PULLMODE=UP" on ECP5 FPGA devices but they may be weak).

Exteral power at I2C VDD (pin 1) does not work, So external 5V was supplied at the USB pins. With that and the pullups, the device was detected at the I2C bus (expected address is 0x41, so 65 decimal):

```
>>> i2c.scan()
[65]
```
the, tou touches are reported (see [i2c_touch_test.py](micropython/i2c_touch_test.py)):  
```
ID 0 at ( 119 , 5046 )
ID 1 at ( 1 , 5402 )
ID 2 release
ID 3 release
ID 4 release
ID 5 release
```

