# Table of Contents
1. [General Info](#general-info)
2. [Videos/Images](#videosimages)
3. [Technologies](#technologies)
4. [Installation](#installation)
5. [Run](#run)
6. [Collaboration](#collaboration)
7. [Repository overview](#repository-overview)
8. [License](#license)
### General Info
***
**Lab 5**

You will practise low-level programming of the nrf53833 MCU in this lab.
We'll develop C code to directly input and output to the GPIO pins of the micro:bit using the basic support headers included with the NRF52 SDK. 

***Setup***

Any computer that has the ARM embedded compiler binaries and make should be able to execute this lab.
The necessary arm tools are arm-none-eabi-objcopy, arm-none-eabi-size, and (arm-none-eabi-) gcc, g++, ld, and as.
These should already be set up because the micro:bit development libraries require them.
Generally, Linux and MacOS support Make.
The labs have them all set up.

You are given a rudimentary programme to use as a starting point.
There is a source file (blinky.c), a Makefile, and sufficient NRF52 SDK to enable compilation.
Microbit-bare.zip should be saved and unzipped into a directory.
Be aware that creating a directory will be done for you if you utilise the graphical file browser.
Run make after making a directory change.
Utilize the build/blinky.hex file to flash the Microbit. 
On the monitor, only one led should be blinking. 

***The Code***

You must comprehend the offered information in order to add to the code.
Read the Makefile and the source code src/blinky.c.
Why are certain pins driven high while others are driven low?
No external functions are being called.
Keep in mind the delay function.
Determine the use of headers and read those as well.

The registers that manage the GPIO pins are being written to directly by the source.
Check that the flashing led matches the pins being written to in blinky.c by reading the microbit pinmap.
Ahead file that defines NRF P0 and NRF GPIO Type must be located.
The elements of this structure are visible. 

Compare these to the datasheet's registers for the GPIO Pins.
Make sure you comprehend the functions of each register and how values are written to them. 

***Task One - Input Task***

Make the blinking led cross one row of the screen in a left-to-right motion.
When button A is pressed, have it move left, and when button B is pressed, have it go right.
You will need to read values from the pins attached to the buttons to accomplish this.
To accomplish this, you must configure pullup and sense low in the PIN CNF register that corresponds to the button pins.
The latch values associated with each button must then be read.
Don't forget to erase the latch value afterwards.
Also keep in mind that you must modify the row pin number rather than increasing it or decreasing it. 

***Task Two - Screen Display***

Make a row of diagonal LEDs appear on the screen.
Leds must be addressed by row and column on the screen.
For some pairings, this is problematic.
To make this work, you will need to display various Leds at various intervals in a brief loop that moves quickly enough for them to appear to be on simultaneously. 

***Marks***

* This lab is worth 2% of the final grade.

***Outcomes***

Once this lab is compleate you should have gain experience with the low-level programming of the nrf53833 MCU by directly using input and output to the GPIO pins of the micro:bit using the basic support headers included with the NRF52 SDK. I have learned alot inregard to the 
C programming language and how multi-threaded tasks are handled accross multi-paged programs. However, due to personal family matters and a change of circumstances, I was unable to 
fix the remaining memory issues which I believed to have caused the results below.

### Videos/Images
***
***Task One - Input Task***


* As you can see when you run the program, thge leds move left/right when you push the button.

***Task Two - Screen Display***

![Diagonal LED pic](/images/screenDisplay.jpg)

* As you can see when you run the program, a row of diagonal LEDs appear on the screen.


## Technologies
***
A list of technologies used within the project:
* [gcc](https://gcc.gnu.org/): Version 9.4.0
* [nano](https://nano-editor.org/): Version 4.8

## Installation
***
A little intro about the installation. 
```
$ git clone https://github.com/lancaster-university/microbit-dal.git
```
## Run
***
**How to run**

To edit the code:
```
$ cd microbit-bare/
$ cd src/
$ nano blinky.c
```
In a different termial, to compile the code:
```
$ cd microbit-bare/
$ make
```
From this it will make a .hex file that you just need to drag onto the micro:bit which is located in:
```
$ cd microbit-bare/
$ cd build/
~"blinky.hex"
```

## Collaboration
***
Just do what you want with this.
> Do what you want, whats done is done. 
## Repository overview
An overview of the directory structure and files:
```
.
├── images
│   └── screenDisplay.jpg
├── microbit-bare
│   ├── build
│   │   ├── blinky.elf
│   │   ├── blinky.hex
│   │   ├── blinky.o
│   │   └── vendor
│   │       └── mdk
│   │           ├── gcc_startup_nrf52833.o
│   │           └── system_nrf52833.o
│   ├── Makefile
│   └── src
│       ├── blinky.c
│       ├── blinky (copy).c
│       └── vendor
│           ├── cmsis
│           │   ├── dsp
│           │   │   ├── ARM
│           │   │   │   ├── arm_cortexM4lf_math.lib
│           │   │   │   └── arm_cortexM4l_math.lib
│           │   │   ├── GCC
│           │   │   │   ├── libarm_cortexM4lf_math.a
│           │   │   │   └── libarm_cortexM4l_math.a
│           │   │   ├── Include
│           │   │   │   ├── arm_common_tables.h
│           │   │   │   ├── arm_const_structs.h
│           │   │   │   └── arm_math.h
│           │   │   └── license.txt
│           │   └── include
│           │       ├── cmsis_armcc.h
│           │       ├── cmsis_armclang.h
│           └── mdk
│               ├── arm_startup_nrf51.s
│               ├── arm_startup_nrf52805.s
├── README.md
├── src
│   ├── inputTask.c
│   ├── inputTask.hex
│   ├── screenDisplay.c
│   └── screenDisplay.hex
└── vids
    └── inoutTask.mp4

16 directories, 212 files



```
## License
MIT License

Copyright (c) 2022 Cameron Cox

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

https://github-readme-stats.vercel.app/api?username=coxxy12
