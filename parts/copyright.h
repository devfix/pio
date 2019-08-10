/***
 *     _______  _____   ___
 *    |_   __ \|_   _|.'   `.
 *      | |__) | | | /  .-.  \
 *      |  ___/  | | | |   | |
 *     _| |_    _| |_\  `-'  /
 *    |_____|  |_____|`.___.'
 * 
 *    Preprocessor I/O Library
 *
 *    ~ version 2.0.1
 *    ~ written by Tristan Krause
 *    ~ visit github.com/devfix/pio
 * 
 *    You should have received a copy of the MIT License.
 *    If not, see <https://opensource.org/licenses/MIT>.
 * 
 *    How does it work?
 *    ----------------------------------------------
 *    Instead of the classical way
 *    (1a)   DDRA |= (1<<PA0);
 *    you can now write
 *    (1b)   d(LEAD_A0) |= LEAD_A0;
 * 
 *    It gets directly replaced by the fast
 *    PORT manipulation command (1a) using
 *    preprocessor macros. This way, PIO
 *    does not increase the overall memory
 *    consumption or slow down the execution
 *    like Arduino does.
 * 
 *    Why using PIO? The Port commands are enough...
 *    ----------------------------------------------
 *    First, the code gets a bit more readable,
 *    especially for beginners.
 *    Second, you can define pins regardless
 *    their corresponding port, resulting in
 *    a more flexible code. For instance:
 *    (2a)   #define LED LEAD_A0
 *           d(LED) |= LED;
 *           o(LED) |= LED;
 *    If you now choose another pin, the rest
 *    of the code can stay the same and PIO
 *    will take care of the right PORT commands.
 *    (2b)   #define LED LEAD_D6  // this changed
 *           d(LED) |= LED;       // same command
 *           o(LED) |= LED;       // same command
 *                             
 */
