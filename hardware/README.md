# BOARDS
## CPU board design
A second, smaller version of the CPU board was designed, based again on the Alwinner F133A CPU  
  
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

The design is done with the open-source EDA tool [Kicad](kicad.org), the source files are [here](./CPU_board)  
The board is 4 layer, based on the [Yuzuki design](https://bbs.aw-ol.com/topic/922/%E5%BC%80%E6%BA%90-yuzukinezha-d1s-%E6%A0%B8%E5%BF%83%E6%9D%BF-mini-pice-%E6%A0%B8%E5%BF%83%E6%9D%BF/3), with **CERN open-source hardware** license.
  
PDF schematics are [here](./CPU_board/CPU_board_schematics.pdf).  

<img src="../doc/CPU_board3D.png" width=640/>  
<img src="../doc/CPU_boardFRONT.png" width=640/>  
<img src="../doc/CPU_boardBACK.png" width=640/>  
<img src="../doc/CPU_board_layers.png" width=640/>  

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


The design is done with the open-source EDA tool [Kicad](kicad.org), the source files are [here](./FPGA_board)  
The board is 6 layer, based on the [OrgangeCrab board r0.1](https://orangecrab-fpga.github.io/orangecrab-hardware/docs/r0.1/), with **CERN open-source hardware** license.
  
PDF schematics are [here](./FPGA_board/FPGA_board_schematics.pdf).  

<img src="../doc/FPGA_board3D.png" width=640/>  
<img src="../doc/FPGA_boardFRONT.png" width=640/>  
<img src="../doc/FPGA_boardBACK.png" width=640/>  
<img src="../doc/FPGA_board_layers.png" width=640/>  

*NOTE: FPGA chip is not shown on the 3D rendering for lack of a 3D model for the part*