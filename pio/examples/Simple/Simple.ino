/***
 *    This is an example of the PIO library.
 * 
 *    You should have received a copy of the MIT License.
 *    If not, see <https://opensource.org/licenses/MIT>.
 * 
 */

#include "pio.h"

// define a fellow LED pin
#define LED    LB5

// define a button pin
#define BUTTON LD2

void setup() {
    // set the pin directions
    set_ddr<LED>();
    clear_ddr<BUTTON>();
    
    // activate the internal pullup resistor for the button
    set_port<BUTTON>();
    
    // turn the LED on
    set_port<LED>();
    
    // wait, until button gets pressed (to ground)
    while(get_pin<BUTTON>())
        delay(1);
}


void loop() {
    // blink now LED
    clear_port<LED>();
    delay(250);
    set_port<LED>();
    delay(250);
}
