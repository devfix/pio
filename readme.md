[pio.h]: https://raw.githubusercontent.com/devfix/pio/master/pio/src/pio.h
[pio.zip]: https://raw.githubusercontent.com/devfix/pio/master/pio.zip
[documentation]: documentation.md

# PIO
**P**in **I**/**O** Library - Compile time hardware abstraction for avr microcontrollers
<hr>

## How does it work?
Instead of the classical way
```c++
/* (1a) */
#define LED PA0
DDRA |= (1 << LED);
```
 you can now write
```c++
/* (1b) */
using LED = LA0;
set_ddr<LED>();
```
It gets directly replaced by the fast PORT manipulation command like (1a) using compile time processing. This way, PIO does not increase the memory consumption of the mcu or slow down the execution like Arduino does.

## Why using PIO? The Port commands are enough...
The benefits are:
* **readable code**  
PIO provides a template function style to control pins instead of bit manipulation.
* **abstraction**  
Pins can be changed, even to different ports. PIO takes care of right register access.  
Example:
```c++
/* (2a) */
using LED = LA0;
set_ddr<LED>();   // set pin of LED as output
set_port<LED>();  // turn LED on
```
If you now choose another pin, the rest of the code can stay the same and PIO will take care of the right PORT commands.
```c++
/* (2b) */
using LED = LD6;  // this changed
set_ddr<LED>();
set_port<LED>();
```

## Digging Deeper
Consider the following more detailed example, it configures the pins PA0, PB2, PD6, PA7, PB0 of an  **atmega32** as an output:
```c++
/* (3a) */
set_ddr<LA0, LB2, LD6, LA7, LB0>();
```
With **-O3** the avr-g++ generates this assembly:
```asm
; set PA0 and PA7 as output
in  r24,  0x1A
ori r24,  lo8(-127)
out 0x1A, r24

; set PB0 and PB2 as output
in  r24,  0x17
ori r24,  lo8(5)
out 0x17, r24

; set PD6 as output
sbi 0x11, 6
```
The register addresses are:

| register | address |
|----------|---------|
| DDRA     | 0x1A    |
| DDRB     | 0x17    |
| DDRD     | 0x11    |

Pio *sorted* the pins, *grouped* them by DDR register and *combined* the bits.  
The generated assembly is in fact the most efficient way to configure the desired output pins, without influencing other pins in the same register.  
 Writing the assembler-code direcly by hand does not speed up the execution, the c++ code compiles without any overhead.

## Installation

### Pure AVR project
Copy the latest [pio.h][pio.h] into your project source folder and include it.  
Make sure to compile with c++ 11 (*-std=c++11*)  
That's it.

### Arduino project
Download the library archive [pio.zip][pio.zip].  
In Arduino, go to *Sketch &rarr; Include Library &rarr; Add .ZIP Library...* and select the pio.zip archive.  
You can find examples under *File &rarr; Examples &rarr; PIO*.

## Documentation
... can be found [here][documentation].
