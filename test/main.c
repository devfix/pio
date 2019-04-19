/***
 *    This is an example of the PIO library.
 * 
 *    You should have received a copy of the MIT License.
 *    If not, see <https://opensource.org/licenses/MIT>.
 * 
 */

#include "../pio/src/pio.h"

#define LED    A5 // define a fellow LED pin

extern void foo();

int main() {
	d(LED) = b( LED);
	d(LED) = LED;
	return 0;
}
