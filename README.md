# PIO
Preprocessor I/O Library

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
