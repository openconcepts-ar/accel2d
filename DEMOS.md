# Font renderer
Scalable font rendering support:
Demo source: [freetype_app.cpp](freetype_app.cpp)  
It's based on a hardware accelerator for fast drawing of solid-color horizontal lines.

[<img src="doc/freetype.png" width=384 height=384>](doc/freetype.png "Freetype Demo")  

The demo shows how to change scale without reloading the glyph at a different size: just applying a matrix transform to scale the outline coordinates, that thus allows for skew and rotation.

# Movie player
  
This one of the most useful features and challenging tasks of this project: A hardware-accelerated video decoder.
The working principle to play movies is akin to the MJPEG format (Motion JPEG): it decodes individual JPEG files in sequence.

See it in action:  
[<img src="../../raw/master/doc/demo_video.png">](doc/demo_video.webm "Video demo")


The video file format is a very simple to manage one: just a TAR file of single JPEG-encoded frames, [accessed](untar.c) from a [SD](fs.c) card by using a provided [FAT filesystem layer](https://github.com/ultraembedded/fat_io_lib) (git submodule fat_io_lib). Each encoded frame is read from the filesystem, while at the same time a previous frame is decoded in hardware. This provides gains in reproduction speed from the simultaneity of software and hardware components.

The original Verilog core [jpeg_core.v](core_jpeg/src_v/jpeg_core.v) was [adapted](https://github.com/ultraembedded/core_jpeg/compare/main...suarezvictor:core_jpeg:main) to overcome some restrictions like requiring a image size being a multiple of 8x8 (and matching the screen size), so the core now supports arbitrary resolutions.

The core was also adapted to a Wishbone bus system by removing the external AXI layers and, instead, directly connecting the inner layers to the Wishbone based [SoC](digilent_arty.py) (using the LiteX open source SoC builder). Raw connection to available DRAM ports were used too, including FIFOs, to achieve fast access to the framebuffer memory. See [videcodecs.py](videocodecs.py) for the LiteX adapter implementation.

A [C API](accel_cores.c) is also provided (see function `accel_jpeg_decode`) with an example [movie player](main.c) (see function `show_movie_frame`). For a smooth reproduction, syncrhonizes frames to the vertical sync of the display hardware.

## Build instructions:
Same as in the section below

This generates a bitstream for the Digilent Arty A7 board.
It is expected a tar file with the movie (just a collection of JPEG frames encoded according to the decoder capabilties) in a FAT formmated SD card, with a PMOD adapter on connector JA, and a DVI compatible display like a PC monitor connected to JC, using raw wires.


# Complete example: Queue Management System
This is an example aplication for a real-world product: a queue management system.  
It's capable of showing not only the current token and counter in a big display, but also additional media for purposes of advertising and/or entertaining, in form of short videos that are played from time to time.
  
See it in action:  
[<img src="../../raw/master/doc/queue_demo.png">](doc/queue.webm "Queue Management System")


The graphics board works as a graphic server, running firmware that receive and process commands from various remote clients (desks) indicating which one isn't busy anymore. It also automatically displays short movies retrieved from an SD card after configured delays to entertain the clients while they're waiting.

The protocol is really simple: single character commands
  * Send a digit ('0' to '9') to indicate the newly available desk
  * Send '+' or '-' to accordingly adjust the token
  * Any other character will reset the system

Upon a new desk notification, the system will make the desk number blink and automatically advance the counter. It will remain without blinking for about 30 seconds to allows the client to attend the indicated desk. After that period, the desk number will blink again and a new video will be displayed, tipically an ad or a "short" (entertaining video).

All the videos should be put in the `videos` folder on the SD card, with the same format as explained in the above section (a TAR of JPEG frames). The video selected will be always the next one appearing on the SD card, cycling after the last one was played. The videos will be decoded in hardware by the provided codec while the software continues running accepting commands.

The background image is a custom JPEG file also stored on the SD card, with name `background.jpeg`. It allows to internationalize the system, and show custom logos of the store where it's used. The digits should be like a bitmapped font atlas: each character needs to be named with the ASCII character number (i.e. 48.bmp for the '0' digit) and all of them should be put in a TAR file called `font_atlas120x240.bmp.tar` (note that the resolution is fixed for each font atlas). BMP format was used to avoid any loss of quality, unlike the movies that would otherwise use too much space.

All the logic for the complete queue management systems is on a single file: [main.c](main.c). See in particular the `turn_machine()` function, that's called periodically to make the system change its state.  
The firmware for the MCU client is [here](demos/queue-client/main.c).

## Build instructions
For the server, execute:
```
make digilent_arty upload
```
The hardware sould be setup as explaiend on the above section.
The SD card should hold files according to the referenced media files (images and videos).
  
For the client:
```
cd demos/queue-client
make flash
```
