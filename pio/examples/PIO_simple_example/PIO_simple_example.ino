/***
 *    This is an example of the PIO library.
 * 
 *    You should have received a copy of the MIT License.
 *    If not, see <https://opensource.org/licenses/MIT>.
 * 
 */

#include "pio.h"

// define a fellow LED pin
#define LED    B5

// define a button pin
#define BUTTON D2

void setup() {
    // set the pin directions
    dMode(LED, OUT);
    dMode(BUTTON, IN);
    
    // activate the internal pullup resistor for the button
    dWrite(BUTTON, HIGH);
    
    // turn the LED on
    dWrite(LED, HIGH);
    
    // wait, until button gets pressed (to ground)
    while(dRead(BUTTON))
        delay(1);
}


void loop() {
    // blink now LED
    dWrite(LED, LOW);
    delay(250);
    dWrite(LED, HIGH);
    delay(250);
}
