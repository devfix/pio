/***
 *    This is an example of the PIO library.
 * 
 *    You should have received a copy of the MIT License.
 *    If not, see <https://opensource.org/licenses/MIT>.
 * 
 */

#include <util/delay.h>
#include "../pio/src/pio.h"

#define LED    A5 // define a fellow LED pin

extern void foo();

int main() {
  d(LED) |= LED;
	while(1)
  {
    o(LED) |= LED;
		_delay_ms(200);
    o(LED) &= ~LED;
		_delay_ms(200);
  }
	return 0;
}
