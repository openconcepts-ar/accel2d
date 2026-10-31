# HARDWARE (boards)

Here are the design files for the current boards of this project:  

Processing boards:  
  * [CPU board](#cpu-board-design) [_viewer_](https://kicanvas.org/?repo=https%3A%2F%2Fgithub.com%2Fopenconcepts-ar%2Faccel2d%2Ftree%2Fpcbfixes1%2Fhardware%2FCPU_board)  
  * [ECP5 FPGA board](#ECP5-fpga-board-design) [_viewer_](https://kicanvas.org/?repo=https%3A%2F%2Fgithub.com%2Fopenconcepts-ar%2Faccel2d%2Ftree%2Fpcbfixes1%2Fhardware%2FFPGA_board)  
  * [Spartan-6 FPGA board](#spartan-6-fpga-board) [_viewer_](https://kicanvas.org/?repo=https%3A%2F%2Fgithub.com%2Fopenconcepts-ar%2Faccel2d%2Ftree%2Fpcbfixes1%2Fhardware%2FSpartan6_board)  

Adapter boards:  
  * [eDP adapter board](#edp-adapter-design) [_viewer_](https://kicanvas.org/?repo=https%3A%2F%2Fgithub.com%2Fopenconcepts-ar%2Faccel2d%2Ftree%2Fpcbfixes1%2Fhardware%2FeDP_adapter)  
  * [eDP adapter board, alternate IC version](#edp-adapter-design) [_viewer_](https://kicanvas.org/?repo=https%3A%2F%2Fgithub.com%2Fopenconcepts-ar%2Faccel2d%2Ftree%2Fpcbfixes1%2Fhardware%2FeDP_adapter%2Fedp_adapterITE)  
  * [VGA adapter](#vga-adapter-board-design) & connector [_viewer_](https://kicanvas.org/?repo=https%3A%2F%2Fgithub.com%2Fopenconcepts-ar%2Faccel2d%2Ftree%2Fpcbfixes1%2Fhardware%2FVGA_adapter)  
  * [LVDS adapters](#lvds-adapter-board-design) single and dual channel [_viewer_](https://kicanvas.org/?repo=https%3A%2F%2Fgithub.com%2Fopenconcepts-ar%2Faccel2d%2Ftree%2Fpcbfixes1%2Fhardware%2FLVDS_adapter)  
  * [DVI adapter](#dvi-adapter-board-design) & connector [_viewer_](https://kicanvas.org/?repo=https%3A%2F%2Fgithub.com%2Fopenconcepts-ar%2Faccel2d%2Ftree%2Fpcbfixes1%2Fhardware%2FDVI_adapter)  
  * [DVI passive adapter](#dvi-passive-adapter-board-design) [_viewer_](https://kicanvas.org/?repo=https%3A%2F%2Fgithub.com%2Fopenconcepts-ar%2Faccel2d%2Ftree%2Fpcbfixes1%2Fhardware%2FDVI_connector_board)  
  * [USB to I2C bridge](#usb-to-i2c-bridge) [_viewer_ NOTE: select USBHOST project](https://kicanvas.org/?repo=https%3A%2F%2Fgithub.com%2Fopenconcepts-ar%2Faccel2d%2Ftree%2Fpcbfixes1%2Fhardware%2FTouch_splitter)   

Debugging boards:  
  * [DVI receiver](#dvi-receiver-board) [_viewer_](https://kicanvas.org/?repo=https%3A%2F%2Fgithub.com%2Fopenconcepts-ar%2Faccel2d%2Ftree%2Fpcbfixes1%2Fhardware%2FDVI_receiver)  
  * [Touch splitter](#touch-splitter-board) [_viewer_](https://kicanvas.org/?repo=https%3A%2F%2Fgithub.com%2Fopenconcepts-ar%2Faccel2d%2Ftree%2Fpcbfixes1%2Fhardware%2FTouch_splitter)  
  * [I/O board](#io-board-design) [_viewer_](https://kicanvas.org/?repo=https%3A%2F%2Fgithub.com%2Fopenconcepts-ar%2Faccel2d%2Ftree%2Fpcbfixes1%2Fhardware%2FIO_board)  
  

## CPU board design
A second, smaller version of the CPU board was designed, based again on the Allwinner F133A CPU  
  
It features:  
  * C906 64-bit RISC-V CPU @1GHz (22nm manufacturing process)  
  * Integrated 64MB DDR2 RAM  
  * Small size, breadboard compatible  
  * SD card socket to store media assets  
  * 2 USB-C connectors with Host and OTG (Host/Device) functions, respectively  
  * Video output connector  
  * Headers for serial I/O and power  
  * Reset and boot buttons
  * JTAG debugging using "pogo-pins"  

The design is done with the open-source EDA tool [Kicad](https://kicad.org), the source files are [here](./CPU_board)  
The board is 4 layer, based on the [Yuzuki design](https://bbs.aw-ol.com/topic/922/%E5%BC%80%E6%BA%90-yuzukinezha-d1s-%E6%A0%B8%E5%BF%83%E6%9D%BF-mini-pice-%E6%A0%B8%E5%BF%83%E6%9D%BF/3), with **CERN open-source hardware** license.
  
PDF schematics are [here](./CPU_board/CPU_board_schematics.pdf).  

<img src="../doc/CPU_board3D.png" width=640>  
<img src="../doc/CPU_boardFRONT.png" width=640>  
<img src="../doc/CPU_boardBACK.png" width=640>  
<img src="../doc/CPU_board_layers.png" width=640>  
  
## ECP5 FPGA board design

The ECP5 FPGA board is capable of instancing a RISC-V CPU along with the hardware accelerators desiged in C and automatically translated to Verilog.
Not only the board has the same layout as the CPU board but the drawing primitives use the same C sources, as one of the main objectives of the project.

Features are:  
  * Lattice ECP5 FPGA device, supporting 12F, 25F, 45F and 85F sizes in 285 ball BGA package  
  * DDR3L RAM of up to 1Gbit with impedance controlled tracks  
  * Small size, breadboard compatible  
  * SD card socket to store media assets  
  * 2 USB-C connectors with Host and Device functions, respectively  
  * Video output connector  
  * Headers for serial I/O  
  * Reset button (also for bitstream loading)
  * JTAG debugging using "pogo-pins"  


The design is done with the open-source EDA tool [Kicad](https://kicad.org), the source files are [here](./FPGA_board)  
The board is 6 layer, based on the [OrangeCrab board r0.1](https://orangecrab-fpga.github.io/orangecrab-hardware/docs/r0.1/), with **CERN open-source hardware** license.
  
PDF schematics are [here](./FPGA_board/FPGA_board_schematics.pdf).  

<img src="../doc/FPGA_board3D.png" width=640>  
<img src="../doc/FPGA_boardFRONT.png" width=640>  
<img src="../doc/FPGA_boardBACK.png" width=640>  
<img src="../doc/FPGA_board_layers.png" width=640>  

*NOTE: FPGA chip is not shown on the 3D rendering for lack of a 3D model for the part*
  

## Spartan-6 FPGA board

The Spartan-6 FPGA board is a lower cost version FPGA board. It includes a DDR3 memory and a RP2040 MCU. I/O includes a flash memory connector, USB-C device port, a 20-pin FPC connector for DVI (TDMS) signals, and a SWD debug header.  

The design is done with the open-source EDA tool [Kicad](https://kicad.org), the source files are [here](./Spartan6_board)  
The board is 6 layer, based on the [Modos Glider Lite](https://github.com/Modos-Labs/Glider/tree/df32bba2b8f32c97958a599ba021d12184ffeada/pcb/mainboard_lite), with **CERN open-source hardware** license.
  
PDF schematics are [here](./Spartan6_board/pcb.pdf).  

<img src="../doc/Spartan6-FPGA_board3D.png" width=640>  
<img src="../doc/Spartan6-FPGA_boardFRONT.png" width=640>  
<img src="../doc/Spartan6-FPGA_boardBACK.png" width=640>  
<img src="../doc/Spartan6-FPGA_board_layers.png" width=640>  

## eDP adapter design

This adapter is capable of converting <s>digital RGB parallel signals NOTE: lack of docs prevents this, see eDP_adapter/EDP.md</s> LVDS signals to eDP protocol for direct driving of laptop replacement displays using a standard FPC cable. The converter IC is NCS8801S from [NewCoSemi](https://www.newcosemi.com/), or IT6251 from [ITE](https://www.ite.com.tw/en) as an alternative. Note they are 4-layer design for better signal integrity, as required by the high-speed differential LVDS inputs and eDP outputs.

The design source files are [here](./eDP_adapter).  
PDF schematics for the adapter are [here](./eDP_adapter/eDP_adapter.pdf).  
  

<img src="../doc/eDP_adapter3D.png" height=240>  
<img src="../doc/eDP_adapterFRONT.png" height=240>
<img src="../doc/eDP_adapterBACK.png" height=240>  
<img src="../doc/eDP_adapter_layers.png" height=240>  

**Alternate version**:  

<img src="../doc/eDP_adapterITE_3D.png" height=240>  
<img src="../doc/eDP_adapterITE_FRONT.png" height=240>
<img src="../doc/eDP_adapterITE_BACK.png" height=240>
<img src="../doc/eDP_adapterITE_layers.png" height=240>  

The design source files are [here](./eDP_adapter).  

Thiese designs are relased under a **CERN open-source hardware** license, using the the open-source EDA tool [Kicad](https://kicad.org)

  
## VGA adapter board design

This adapter is capable of converting digital RGB parallel signals to VGA-compatible analog values, using a simple R-2R DAC. The adapter board outputs the VGA signals to a 15-pin flat cable, to be connected 1:1 to a connector board that has the D-sub (15-pin) starndard VGA connector.

The design is done with the open-source EDA tool [Kicad](https://kicad.org), the source files are [here](./VGA_adapter) (adapter) and [here](./VGA_connector_board) (connector)  
PDF schematics for the adapter are [here](./VGA_adapter/VGA_adapter_schematics.pdf).  
  
This design is relased under a **CERN open-source hardware** license.

<img src="../doc/VGA_adapter3D.png" height=360>
<img src="../doc/VGA_connector_board3D.png" height=360>  
<img src="../doc/VGA_adapterFRONT.png" height=360>
<img src="../doc/VGA_adapterBACK.png" height=360>
<img src="../doc/VGA_adapter_layers.png" height=360>  

  
## LVDS adapter board design

This board connects 4 or 8 pairs of differential signals to a LCD using LVDS signalling (of the kind commonly used for older laptops displays), to directly drive them (single and dual channel). It also connect signals that can identify the display model and resolution using I2C.

Features:  
  * 40-pin FPC cable connector  
  * Protection diodes  
  * I2C connection for display [EDID](https://en.wikipedia.org/wiki/Extended_Display_Identification_Data) reading  
  * External header for powering the backlight  

The design is done with the open-source EDA tool [Kicad](https://kicad.org), the source files are [here](./LVDS_adapter), licensed under a **CERN open-source hardware** license.  
  
PDF schematics for the adapter are [here](./LVDS_adapter/LVDS_adapter_schematics.pdf) (single channel) and [here](./LVDS_adapter/LVDS_adapter_2ch.pdf) (dual channel).  

**Dual channel**
<img src="../doc/LVDS_adapter3D-2ch.png" width=480>  
<img src="../doc/LVDS_adapterFRONT-2ch.png" width=240>
<img src="../doc/LVDS_adapterBACK-2ch.png" width=240>  
<img src="../doc/LVDS_adapter_layers-2ch.png" width=240>  

**Single channel**
<img src="../doc/LVDS_adapter3D.png" width=480>  
<img src="../doc/LVDS_adapterFRONT.png" width=240>
<img src="../doc/LVDS_adapterBACK.png" width=240>  
<img src="../doc/LVDS_adapter_layers.png" width=240>  
  

**8-bit dual channel**

This boards outputs a standard 2x15 2mm pitch LVDS connector on the side, supporting 1 or 2 channel, 6- or 8-bit versions. It adds a 6-pin I2C connector on the back for touch signals.  
<img src="../doc/LVDS_adapter3D-2ch8bit.png" width=480>  
<img src="../doc/LVDS_adapterFRONT-2ch8bit.png" width=240>
<img src="../doc/LVDS_adapterBACK-2ch8bit.png" width=240>  
<img src="../doc/LVDS_adapter_layers-2ch8bit.png" width=240>  

## DVI adapter board design

This board converts parallel RGB signals to digital video signals in the DVI format, as accepted by the majority of current PC monitors and TVs.

Features:  
  * 20-pin FPC cable connector, compatible with standard [FPV Ribbon cables](https://duckduckgo.com/?hps=1&q=FPV+HDMI+Ribbon+Cable) for connection to displays  
  * Protection diodes  
  * I2C connection for display [EDID](https://en.wikipedia.org/wiki/Extended_Display_Identification_Data) reading  
  * Solder jumpers for the main IC configuration  

The design is done with the open-source EDA tool [Kicad](https://kicad.org), the source files are [here](./DVI_adapter) (adapter) and [here](./DVI_connector_board) (connector), licensed under a **CERN open-source hardware** license.  
  
PDF schematics for the adapter are [here](./DVI_adapter/DVI_adapter_schematics.pdf).  

<img src="../doc/DVI_adapter3D.png" width=320>
<img src="../doc/DVI_adapterFRONT.png" height=160>
<img src="../doc/DVI_adapterBACK.png" height=160>
<img src="../doc/DVI_adapter_layers.png" height=160>  

**Connector board**
  
This was fixed for better signal integrity using a G-S-S-G scheme for the differential signals, using a pinout that is common in off-the-shelf extension adapters.   

<img src="../doc/DVI_connector_board3D.png" width=320>  


## DVI passive adapter board design

This is for outputting LVDS signals from a FPGA using AC-coupling to drive a TDMS receiver, using a standard connector for carring DVI video signals.
It includes a level adapter to convert 5V I2C to 3.3V (VIO).

The design is done with the open-source EDA tool [Kicad](https://kicad.org), the source files are [here](./LVDS_DVI_adapter), licensed under a **CERN open-source hardware** license.  
  
PDF schematics for the adapter are [here](./LVDS_DVI_adapter/LVDS_DVI_adapter.pdf).  

<img src="../doc/LVDS_DVI_adapter3D.png" width=320>  
<img src="../doc/LVDS_DVI_adapterFRONT.png" height=160>
<img src="../doc/LVDS_DVI_adapterBACK.png" height=160>
<img src="../doc/LVDS_DVI_adapter_layers.png" height=160>  


## DVI receiver board

This board converts DVI (TDMS) signals to parallel RGB signals + H/V sync. It is based on the TFP401 chip from TI.

The design is done with the open-source EDA tool [Kicad](https://kicad.org), the source files are [here](./DVI_adapter) (adapter) and [here](./DVI_connector_board) (connector), licensed under a **CERN open-source hardware** license.  
  
PDF schematics for the adapter are [here](./DVI_adapter/DVI_adapter_schematics.pdf).  

<img src="../doc/DVI_receiver3D.png" height=200>  
<img src="../doc/DVI_receiverFRONT.png" height=200>
<img src="../doc/DVI_receiverBACK.png" height=200>
<img src="../doc/DVI_receiver_layers.png" height=200>  


  
## Touch splitter board

The touch splitter board allows to split the signals from a 40-pin eDP display woth on-cell touch, separating the 30-pin eDP signals and the USB touch signals. It supports powering the touch model with 5V or 3.3V.

The design is done with the open-source EDA tool [Kicad](https://kicad.org), the source files are [here](./Touch_splitter). 

<img src="../doc/Touch_splitter3D.png" height=200>  
<img src="../doc/Touch_splitterFRONT.png" height=200>
<img src="../doc/Touch_splitterBACK.png" height=200>
<img src="../doc/Touch_splitter_layers.png" height=200>  


## USB to I2C Bridge
This board is a 40-pin extended eDP with touch to 30-pin with bridged I2C. It is similar top the Touch splitter board, but "active": instead of passively exposing the USB signals to an external connector, it routes them to a MCU.
  
The board uses a RP2354 as the MCU wich supports USB full-speeed host (unsing the USB signals on the connector with the additional 10 pins) and outputs I2C data over a usual 30-pin eDP connector. It uses "OEM reserved" pins to route the I2C signals and the interrupt pin. This is received by the eDP adapter which supports touch-enabled display reusing it's 30-pin output FPC connector, being still compatible with non-touch enabled 30-pin displays.

The design is done with the open-source EDA tool [Kicad](https://kicad.org), the source files are [here](./Touch_splitter), see `eDP_touch_adapter_USBHOST.kicad_*` files. 

<img src="../doc/Touch_adapter_USBHOST_3D.png" height=200>  
<img src="../doc/Touch_adapter_USBHOST_FRONT.png" height=200>
<img src="../doc/Touch_adapter_USBHOST_BACK.png" height=200>  
<img src="../doc/Touch_adapter_USBHOST_layers.png" height=200>  


  
## I/O board design

The I/O board adapter allows to externally access the video signals (present on the 2x15 connectors) for other purposes like general purpose I/O pins and debug.

It uses a 40-pin FPC connector and cable that allows to break out the signals, in a more manageable way like using common wires as the ones usually for bread boards.

Also, it includes two 31-pin FPC connectors at 0.3mm pitch for replacing the Hirose connectors with FPC or FFCs.
All the wiring are directo connections to the video connectors. A header to acces the touchscreen signal is also provided.

The design is done with the open-source EDA tool [Kicad](https://kicad.org), the source files are [here](./IO_board), licensed under a **CERN open-source hardware** license.  


# Latest updates

See most relevant [commit](https://github.com/openconcepts-ar/accel2d/commit/21333764fecb12ceccd276d67593bb1683f1b8bd).  

  * Added [eDP adapter board](#edp-adapter-design), alternate version
  * Added [USB to I2C bridge](#usb-to-i2c-bridge)
  * Added [LVDS adapters, 8-bit version dual channel](#lvds-adapter-board-design)
  * Updated [eDP adapter board](#edp-adapter-design) to 4 layers
  * Added [Spartan-6 FPGA board](#spartan-6-fpga-board)
  * Added [DVI receiver board](#dvi-receiver-board)
  * Added [Touch splitter board](#touch-splitter-board)
  * [ECP5 FPGA board](#ECP5-fpga-board-design): Added support to larger 85F version, add Replacement of 2.5V source (DC-DC or LDO option), USB connectors swap (note location matches the CPU board), thermal fix (replaced flash of wrong voltage, now larger to accomodate 85F devices, and added both LDO and higher capacity DC-DC for the 2.5V rail, selectable via solder pad)
  * [DVI passive adapter](#dvi-passive-adapter-board-design): make PCB significantly shorter
  * [DVI connector](#dvi-adapter-board-design) board: fixed DVI connector (previously mini version of 0.4mm pitch, now 0.5mm like the standard version)
  * [LVDS adapters](#lvds-adapter-board-design)  (2ch): Fixed bug of bad GND plane fill, which produced massive shorts
  * [CPU board](#cpu-board-design): Add impedance control to differential tracks, corrected size of vias for , bootsel fix, dim led
  * DRC checks for all boards, with DFM checks for 4 and 6 layers boards
  
