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
 *    ~ visit www.devfix.net
 * 
 *    You should have received a copy of the MIT License.
 *    If not, see <https://opensource.org/licenses/MIT>.
 * 
 *    How does it work?
 *    ----------------------------------------------
 *    Instead of the classical way
 *    (1a)   DDRA |= (1<<PA0);
 *    you can now write
 *    (1b)   dMode(A0, OUT);
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
 *    (2a)   #define LED A0
 *           dMode(LED, OUT);
 *           dWrite(LED, HIGH);
 *    If you now choose another pin, the rest
 *    of the code can stay the same and PIO
 *    will take care of the right PORT commands.
 *    (2b)   #define LED D6     // this changed
 *           dMode(LED, OUT);   // same command
 *           dWrite(LED, HIGH); // same command
 *                             
 */


#ifndef PIOLIB_H
#define PIOLIB_H
#include <avr/io.h>

#ifdef HIGH
  #undef HIGH
#endif
#define HIGH 1

#ifndef LOW
  #undef LOW
#endif
#define LOW  0

#ifndef OUT
  #undef OUT
#endif
#define OUT 1

#ifndef OUTPUT
  #undef OUTPUT
#endif
#define OUTPUT 1

#ifndef IN
  #undef IN
#endif
#define IN 0

#ifndef INPUT
  #undef INPUT
#endif
#define INPUT 0


// SECTION PINS
#define b(PIN) b_(PIN)
#define b_(PIN) B ## _ ## PIN

static const unsigned char A0 = 0x01;
#define B_A0 0
static const unsigned char A1 = 0x02;
#define B_A1 1
static const unsigned char A2 = 0x04;
#define B_A2 2
static const unsigned char A3 = 0x08;
#define B_A3 3
static const unsigned char A4 = 0x10;
#define B_A4 4
static const unsigned char A5 = 0x20;
#define B_A5 5
static const unsigned char A6 = 0x40;
#define B_A6 6
static const unsigned char A7 = 0x80;
#define B_A7 7

static const unsigned char B0 = 0x01;
#define B_B0 0
static const unsigned char B1 = 0x02;
#define B_B1 1
static const unsigned char B2 = 0x04;
#define B_B2 2
static const unsigned char B3 = 0x08;
#define B_B3 3
static const unsigned char B4 = 0x10;
#define B_B4 4
static const unsigned char B5 = 0x20;
#define B_B5 5
static const unsigned char B6 = 0x40;
#define B_B6 6
static const unsigned char B7 = 0x80;
#define B_B7 7

static const unsigned char C0 = 0x01;
#define B_C0 0
static const unsigned char C1 = 0x02;
#define B_C1 1
static const unsigned char C2 = 0x04;
#define B_C2 2
static const unsigned char C3 = 0x08;
#define B_C3 3
static const unsigned char C4 = 0x10;
#define B_C4 4
static const unsigned char C5 = 0x20;
#define B_C5 5
static const unsigned char C6 = 0x40;
#define B_C6 6
static const unsigned char C7 = 0x80;
#define B_C7 7

static const unsigned char D0 = 0x01;
#define B_D0 0
static const unsigned char D1 = 0x02;
#define B_D1 1
static const unsigned char D2 = 0x04;
#define B_D2 2
static const unsigned char D3 = 0x08;
#define B_D3 3
static const unsigned char D4 = 0x10;
#define B_D4 4
static const unsigned char D5 = 0x20;
#define B_D5 5
static const unsigned char D6 = 0x40;
#define B_D6 6
static const unsigned char D7 = 0x80;
#define B_D7 7

static const unsigned char E0 = 0x01;
#define B_E0 0
static const unsigned char E1 = 0x02;
#define B_E1 1
static const unsigned char E2 = 0x04;
#define B_E2 2
static const unsigned char E3 = 0x08;
#define B_E3 3
static const unsigned char E4 = 0x10;
#define B_E4 4
static const unsigned char E5 = 0x20;
#define B_E5 5
static const unsigned char E6 = 0x40;
#define B_E6 6
static const unsigned char E7 = 0x80;
#define B_E7 7

static const unsigned char F0 = 0x01;
#define B_F0 0
static const unsigned char F1 = 0x02;
#define B_F1 1
static const unsigned char F2 = 0x04;
#define B_F2 2
static const unsigned char F3 = 0x08;
#define B_F3 3
static const unsigned char F4 = 0x10;
#define B_F4 4
static const unsigned char F5 = 0x20;
#define B_F5 5
static const unsigned char F6 = 0x40;
#define B_F6 6
static const unsigned char F7 = 0x80;
#define B_F7 7



// SECTION DDR
#define d(PIN) d_(PIN)
#define d_(PIN) DDR ## _ ## PIN

#ifdef DDRA
  #define DDR_A0 DDRA
  #define DDR_A1 DDRA
  #define DDR_A2 DDRA
  #define DDR_A3 DDRA
  #define DDR_A4 DDRA
  #define DDR_A5 DDRA
  #define DDR_A6 DDRA
  #define DDR_A7 DDRA
#endif // DDRA

#ifdef DDRB
  #define DDR_B0 DDRB
  #define DDR_B1 DDRB
  #define DDR_B2 DDRB
  #define DDR_B3 DDRB
  #define DDR_B4 DDRB
  #define DDR_B5 DDRB
  #define DDR_B6 DDRB
  #define DDR_B7 DDRB
#endif // DDRB

#ifdef DDRC
  #define DDR_C0 DDRC
  #define DDR_C1 DDRC
  #define DDR_C2 DDRC
  #define DDR_C3 DDRC
  #define DDR_C4 DDRC
  #define DDR_C5 DDRC
  #define DDR_C6 DDRC
  #define DDR_C7 DDRC
#endif // DDRC

#ifdef DDRD
  #define DDR_D0 DDRD
  #define DDR_D1 DDRD
  #define DDR_D2 DDRD
  #define DDR_D3 DDRD
  #define DDR_D4 DDRD
  #define DDR_D5 DDRD
  #define DDR_D6 DDRD
  #define DDR_D7 DDRD
#endif // DDRD

#ifdef DDRE
  #define DDR_E0 DDRE
  #define DDR_E1 DDRE
  #define DDR_E2 DDRE
  #define DDR_E3 DDRE
  #define DDR_E4 DDRE
  #define DDR_E5 DDRE
  #define DDR_E6 DDRE
  #define DDR_E7 DDRE
#endif // DDRE

#ifdef DDRF
  #define DDR_F0 DDRF
  #define DDR_F1 DDRF
  #define DDR_F2 DDRF
  #define DDR_F3 DDRF
  #define DDR_F4 DDRF
  #define DDR_F5 DDRF
  #define DDR_F6 DDRF
  #define DDR_F7 DDRF
#endif // DDRF



#endif // PIOLIB_H
