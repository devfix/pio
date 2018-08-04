# PIO
Preprocessor I/O Library

## How does it work?
Instead of the classical way
```C
 DDRA |= (1<<PA0); // (1a)
```
 you can now write
```C
 dMode(A0, OUT);   // (1b)
```
It gets directly replaced by the fast PORT manipulation command (1a) using preprocessor macros. This way, PIO does not increase the overall memory consumption or slow down the execution like Arduino does.

## Why using PIO? The Port commands are enough...
First, the code gets a bit more readable, especially for beginners. Second, you can define pins regardless their corresponding port, resulting in a more flexible code. For instance:
```C
/* (2a) */
#define LED A0
dMode(LED, OUT);
dWrite(LED, HIGH);
```
If you now choose another pin, the rest of the code can stay the same and PIO will take care of the right PORT commands.
```C
/* (2b) */
#define LED D6     // this changed
dMode(LED, OUT);   // same command
dWrite(LED, HIGH); // same command
```
## Installation

### Pure AVR C code
Copy the content of the "pio/src/" directory into your source folder.
Include PIO with
```C
#include "pio.h"
```

### Arduino
This library is compatible with the Arduino framework.
To install it, copy the whole "pio" directory into the "libraries" folder in your Arduino installation directory.
Restart Arduino, and checkout the example under "file -> examples -> PIO".

## Examples

### Arduino
Checkout the menu entry "file -> examples -> PIO" after installation.

### Pure AVR c code

```C
/***
 *    This is an example of the PIO library.
 * 
 *    You should have received a copy of the MIT License.
 *    If not, see <https://opensource.org/licenses/MIT>.
 * 
 */

#define F_CPU 1000000

#include <util/delay.h>

#include "pio.h"

#define LED    A0 // define a fellow LED pin
#define BUTTON D4 // define a button pin

int main() {
    // set the pin directions
    dMode(LED, OUT);
    dMode(BUTTON, IN);
    
    // activate the internal pullup resistor for the button
    dWrite(BUTTON, HIGH);
    
    // turn the LED on
    dWrite(LED, HIGH);
    
    // wait, until button gets pressed (to ground)
    while(dRead(BUTTON))
        _delay_ms(1);
    
    // blink now the LED
    while(1) {
        dWrite(LED, LOW);
        _delay_ms(250);
        dWrite(LED, HIGH);
        _delay_ms(250);
    }
}
```
