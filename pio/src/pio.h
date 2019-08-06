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
*    ~ version 2.0.0
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
#ifndef PIOLIB_H
#define PIOLIB_H
#include <avr/io.h>
#ifdef HIGH
#undef HIGH
#warning Redefining HIGH...
#endif
#define HIGH 1
#ifndef LOW
#undef LOW
#warning Redefining LOW...
#endif
#define LOW  0
#ifndef OUT
#undef OUT
#warning Redefining OUT...
#endif
#define OUT 1
#ifndef OUTPUT
#undef OUTPUT
#warning Redefining OUTPUT...
#endif
#define OUTPUT 1
#ifndef IN
#undef IN
#warning Redefining IN...
#endif
#define IN 0
#ifndef INPUT
#undef INPUT
#warning Redefining INPUT...
#endif
#define INPUT 0
#define b(PIN) b_(PIN)
#define b_(PIN) B ## _ ## PIN
static const unsigned char LEAD_A0 = 0x01;
#define B_LEAD_A0 0
static const unsigned char LEAD_A1 = 0x02;
#define B_LEAD_A1 1
static const unsigned char LEAD_A2 = 0x04;
#define B_LEAD_A2 2
static const unsigned char LEAD_A3 = 0x08;
#define B_LEAD_A3 3
static const unsigned char LEAD_A4 = 0x10;
#define B_LEAD_A4 4
static const unsigned char LEAD_A5 = 0x20;
#define B_LEAD_A5 5
static const unsigned char LEAD_A6 = 0x40;
#define B_LEAD_A6 6
static const unsigned char LEAD_A7 = 0x80;
#define B_LEAD_A7 7
static const unsigned char LEAD_B0 = 0x01;
#define B_LEAD_B0 0
static const unsigned char LEAD_B1 = 0x02;
#define B_LEAD_B1 1
static const unsigned char LEAD_B2 = 0x04;
#define B_LEAD_B2 2
static const unsigned char LEAD_B3 = 0x08;
#define B_LEAD_B3 3
static const unsigned char LEAD_B4 = 0x10;
#define B_LEAD_B4 4
static const unsigned char LEAD_B5 = 0x20;
#define B_LEAD_B5 5
static const unsigned char LEAD_B6 = 0x40;
#define B_LEAD_B6 6
static const unsigned char LEAD_B7 = 0x80;
#define B_LEAD_B7 7
static const unsigned char LEAD_C0 = 0x01;
#define B_LEAD_C0 0
static const unsigned char LEAD_C1 = 0x02;
#define B_LEAD_C1 1
static const unsigned char LEAD_C2 = 0x04;
#define B_LEAD_C2 2
static const unsigned char LEAD_C3 = 0x08;
#define B_LEAD_C3 3
static const unsigned char LEAD_C4 = 0x10;
#define B_LEAD_C4 4
static const unsigned char LEAD_C5 = 0x20;
#define B_LEAD_C5 5
static const unsigned char LEAD_C6 = 0x40;
#define B_LEAD_C6 6
static const unsigned char LEAD_C7 = 0x80;
#define B_LEAD_C7 7
static const unsigned char LEAD_D0 = 0x01;
#define B_LEAD_D0 0
static const unsigned char LEAD_D1 = 0x02;
#define B_LEAD_D1 1
static const unsigned char LEAD_D2 = 0x04;
#define B_LEAD_D2 2
static const unsigned char LEAD_D3 = 0x08;
#define B_LEAD_D3 3
static const unsigned char LEAD_D4 = 0x10;
#define B_LEAD_D4 4
static const unsigned char LEAD_D5 = 0x20;
#define B_LEAD_D5 5
static const unsigned char LEAD_D6 = 0x40;
#define B_LEAD_D6 6
static const unsigned char LEAD_D7 = 0x80;
#define B_LEAD_D7 7
static const unsigned char LEAD_E0 = 0x01;
#define B_LEAD_E0 0
static const unsigned char LEAD_E1 = 0x02;
#define B_LEAD_E1 1
static const unsigned char LEAD_E2 = 0x04;
#define B_LEAD_E2 2
static const unsigned char LEAD_E3 = 0x08;
#define B_LEAD_E3 3
static const unsigned char LEAD_E4 = 0x10;
#define B_LEAD_E4 4
static const unsigned char LEAD_E5 = 0x20;
#define B_LEAD_E5 5
static const unsigned char LEAD_E6 = 0x40;
#define B_LEAD_E6 6
static const unsigned char LEAD_E7 = 0x80;
#define B_LEAD_E7 7
static const unsigned char LEAD_F0 = 0x01;
#define B_LEAD_F0 0
static const unsigned char LEAD_F1 = 0x02;
#define B_LEAD_F1 1
static const unsigned char LEAD_F2 = 0x04;
#define B_LEAD_F2 2
static const unsigned char LEAD_F3 = 0x08;
#define B_LEAD_F3 3
static const unsigned char LEAD_F4 = 0x10;
#define B_LEAD_F4 4
static const unsigned char LEAD_F5 = 0x20;
#define B_LEAD_F5 5
static const unsigned char LEAD_F6 = 0x40;
#define B_LEAD_F6 6
static const unsigned char LEAD_F7 = 0x80;
#define B_LEAD_F7 7
#define d(PIN) d_(PIN)
#define d_(PIN) DDR ## _ ## PIN
#ifdef DDRA
#define DDR_LEAD_A0 DDRA
#define DDR_LEAD_A1 DDRA
#define DDR_LEAD_A2 DDRA
#define DDR_LEAD_A3 DDRA
#define DDR_LEAD_A4 DDRA
#define DDR_LEAD_A5 DDRA
#define DDR_LEAD_A6 DDRA
#define DDR_LEAD_A7 DDRA
#endif // DDRA
#ifdef DDRB
#define DDR_LEAD_B0 DDRB
#define DDR_LEAD_B1 DDRB
#define DDR_LEAD_B2 DDRB
#define DDR_LEAD_B3 DDRB
#define DDR_LEAD_B4 DDRB
#define DDR_LEAD_B5 DDRB
#define DDR_LEAD_B6 DDRB
#define DDR_LEAD_B7 DDRB
#endif // DDRB
#ifdef DDRC
#define DDR_LEAD_C0 DDRC
#define DDR_LEAD_C1 DDRC
#define DDR_LEAD_C2 DDRC
#define DDR_LEAD_C3 DDRC
#define DDR_LEAD_C4 DDRC
#define DDR_LEAD_C5 DDRC
#define DDR_LEAD_C6 DDRC
#define DDR_LEAD_C7 DDRC
#endif // DDRC
#ifdef DDRD
#define DDR_LEAD_D0 DDRD
#define DDR_LEAD_D1 DDRD
#define DDR_LEAD_D2 DDRD
#define DDR_LEAD_D3 DDRD
#define DDR_LEAD_D4 DDRD
#define DDR_LEAD_D5 DDRD
#define DDR_LEAD_D6 DDRD
#define DDR_LEAD_D7 DDRD
#endif // DDRD
#ifdef DDRE
#define DDR_LEAD_E0 DDRE
#define DDR_LEAD_E1 DDRE
#define DDR_LEAD_E2 DDRE
#define DDR_LEAD_E3 DDRE
#define DDR_LEAD_E4 DDRE
#define DDR_LEAD_E5 DDRE
#define DDR_LEAD_E6 DDRE
#define DDR_LEAD_E7 DDRE
#endif // DDRE
#ifdef DDRF
#define DDR_LEAD_F0 DDRF
#define DDR_LEAD_F1 DDRF
#define DDR_LEAD_F2 DDRF
#define DDR_LEAD_F3 DDRF
#define DDR_LEAD_F4 DDRF
#define DDR_LEAD_F5 DDRF
#define DDR_LEAD_F6 DDRF
#define DDR_LEAD_F7 DDRF
#endif // DDRF
#define o(PIN) o_(PIN)
#define o_(PIN) PORT ## _ ## PIN
#ifdef PORTA
#define PORT_LEAD_A0 PORTA
#define PORT_LEAD_A1 PORTA
#define PORT_LEAD_A2 PORTA
#define PORT_LEAD_A3 PORTA
#define PORT_LEAD_A4 PORTA
#define PORT_LEAD_A5 PORTA
#define PORT_LEAD_A6 PORTA
#define PORT_LEAD_A7 PORTA
#endif // PORTA
#ifdef PORTB
#define PORT_LEAD_B0 PORTB
#define PORT_LEAD_B1 PORTB
#define PORT_LEAD_B2 PORTB
#define PORT_LEAD_B3 PORTB
#define PORT_LEAD_B4 PORTB
#define PORT_LEAD_B5 PORTB
#define PORT_LEAD_B6 PORTB
#define PORT_LEAD_B7 PORTB
#endif // PORTB
#ifdef PORTC
#define PORT_LEAD_C0 PORTC
#define PORT_LEAD_C1 PORTC
#define PORT_LEAD_C2 PORTC
#define PORT_LEAD_C3 PORTC
#define PORT_LEAD_C4 PORTC
#define PORT_LEAD_C5 PORTC
#define PORT_LEAD_C6 PORTC
#define PORT_LEAD_C7 PORTC
#endif // PORTC
#ifdef PORTD
#define PORT_LEAD_D0 PORTD
#define PORT_LEAD_D1 PORTD
#define PORT_LEAD_D2 PORTD
#define PORT_LEAD_D3 PORTD
#define PORT_LEAD_D4 PORTD
#define PORT_LEAD_D5 PORTD
#define PORT_LEAD_D6 PORTD
#define PORT_LEAD_D7 PORTD
#endif // PORTD
#ifdef PORTE
#define PORT_LEAD_E0 PORTE
#define PORT_LEAD_E1 PORTE
#define PORT_LEAD_E2 PORTE
#define PORT_LEAD_E3 PORTE
#define PORT_LEAD_E4 PORTE
#define PORT_LEAD_E5 PORTE
#define PORT_LEAD_E6 PORTE
#define PORT_LEAD_E7 PORTE
#endif // PORTE
#ifdef PORTF
#define PORT_LEAD_F0 PORTF
#define PORT_LEAD_F1 PORTF
#define PORT_LEAD_F2 PORTF
#define PORT_LEAD_F3 PORTF
#define PORT_LEAD_F4 PORTF
#define PORT_LEAD_F5 PORTF
#define PORT_LEAD_F6 PORTF
#define PORT_LEAD_F7 PORTF
#endif // PORTF
#define i(PIN) i_(PIN)
#define i_(PIN) PIN ## _ ## PIN
#ifdef PINA
#define PIN_LEAD_A0 PINA
#define PIN_LEAD_A1 PINA
#define PIN_LEAD_A2 PINA
#define PIN_LEAD_A3 PINA
#define PIN_LEAD_A4 PINA
#define PIN_LEAD_A5 PINA
#define PIN_LEAD_A6 PINA
#define PIN_LEAD_A7 PINA
#endif // PINA
#ifdef PINB
#define PIN_LEAD_B0 PINB
#define PIN_LEAD_B1 PINB
#define PIN_LEAD_B2 PINB
#define PIN_LEAD_B3 PINB
#define PIN_LEAD_B4 PINB
#define PIN_LEAD_B5 PINB
#define PIN_LEAD_B6 PINB
#define PIN_LEAD_B7 PINB
#endif // PINB
#ifdef PINC
#define PIN_LEAD_C0 PINC
#define PIN_LEAD_C1 PINC
#define PIN_LEAD_C2 PINC
#define PIN_LEAD_C3 PINC
#define PIN_LEAD_C4 PINC
#define PIN_LEAD_C5 PINC
#define PIN_LEAD_C6 PINC
#define PIN_LEAD_C7 PINC
#endif // PINC
#ifdef PIND
#define PIN_LEAD_D0 PIND
#define PIN_LEAD_D1 PIND
#define PIN_LEAD_D2 PIND
#define PIN_LEAD_D3 PIND
#define PIN_LEAD_D4 PIND
#define PIN_LEAD_D5 PIND
#define PIN_LEAD_D6 PIND
#define PIN_LEAD_D7 PIND
#endif // PIND
#ifdef PINE
#define PIN_LEAD_E0 PINE
#define PIN_LEAD_E1 PINE
#define PIN_LEAD_E2 PINE
#define PIN_LEAD_E3 PINE
#define PIN_LEAD_E4 PINE
#define PIN_LEAD_E5 PINE
#define PIN_LEAD_E6 PINE
#define PIN_LEAD_E7 PINE
#endif // PINE
#ifdef PINF
#define PIN_LEAD_F0 PINF
#define PIN_LEAD_F1 PINF
#define PIN_LEAD_F2 PINF
#define PIN_LEAD_F3 PINF
#define PIN_LEAD_F4 PINF
#define PIN_LEAD_F5 PINF
#define PIN_LEAD_F6 PINF
#define PIN_LEAD_F7 PINF
#endif // PINF
#endif // PIOLIB_H
