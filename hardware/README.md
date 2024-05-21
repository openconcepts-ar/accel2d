# BOARDS

Here are design files for the various board of this project:  

Processing boards:  
  * [CPU board](#cpu-board-design)  
  * [FPGA board](#fpga-board-design)  

Adapter boards:  
  * [VGA adapter](#vga-adapter-board-design) & connector  
  * [LVDS adapter](#lvds-adapter-board-design)  
  * [DVI adapter](#dvi-adapter-board-design)  
  * [I/O board](#io-board-design)  

  
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
  
## FPGA board design

The FPGA board is capable of instancing a RISC-V CPU along with the hardware acellerators desiged in C and automatically translated to Verilog.
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
The board is 6 layer, based on the [OrgangeCrab board r0.1](https://orangecrab-fpga.github.io/orangecrab-hardware/docs/r0.1/), with **CERN open-source hardware** license.
  
PDF schematics are [here](./FPGA_board/FPGA_board_schematics.pdf).  

<img src="../doc/FPGA_board3D.png" width=640>  
<img src="../doc/FPGA_boardFRONT.png" width=640>  
<img src="../doc/FPGA_boardBACK.png" width=640>  
<img src="../doc/FPGA_board_layers.png" width=640>  

*NOTE: FPGA chip is not shown on the 3D rendering for lack of a 3D model for the part*
  
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

This board connects 4 pairs of differential signals to a LCD using LVDS signalling (of the kind commonly used for laptops), to directly drive the display (1-channel). It also connect signals that can identify the display model and resolution.

Features:  
  * 40-pin FPC cable connector  
  * Protection diodes  
  * I2C connection for display [EDID](https://en.wikipedia.org/wiki/Extended_Display_Identification_Data) reading  
  * External header for powering the backlight  

The design is done with the open-source EDA tool [Kicad](https://kicad.org), the source files are [here](./LVDS_adapter), licensed under a **CERN open-source hardware** license.  
  
PDF schematics for the adapter are [here](./LVDS_adapter/LVDS_adapter_schematics.pdf).  

<img src="../doc/LVDS_adapter3D.png" width=480>  
<img src="../doc/LVDS_adapterFRONT.png" width=240>
<img src="../doc/LVDS_adapterBACK.png" width=240>  
<img src="../doc/LVDS_adapter_layers.png" width=240>  

  
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
<img src="../doc/DVI_connector_board3D.png" width=320>  
<img src="../doc/DVI_adapterFRONT.png" height=160>
<img src="../doc/DVI_adapterBACK.png" height=160>
<img src="../doc/DVI_adapter_layers.png" height=160>  


  
## I/O board design

The I/O board adapter allows to externally access the video signals (present on the 2x15 connectors) for other purposes like general purpose I/O pins and debug.

It uses a 40-pin FPC connector and cable that allows to break out the signals, in a more manageable way like using common wires as the ones usually for bread boards.

Also, it includes two 31-pin FPC connectors at 0.3mm pitch for replacing the Hirose connectors with FPC or FFCs.
All the wiring are directo connections to the video connectors. A header to acces the touchscreen signal is also provided.

The design is done with the open-source EDA tool [Kicad](https://kicad.org), the source files are [here](./IO_board), licensed under a **CERN open-source hardware** license.  

  
<img src="../doc/IO_boardTOP.png" width=320>

