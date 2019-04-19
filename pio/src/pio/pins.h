/***
 * pins.h
 * This file is part of the PIO library.
 * For license information see "pio.h" in the parent directory.
 */

#if !defined(PIOLIB) || PIOLIB < 200
#error This file should not be included directly. Use "pio.h" instead.
#endif
#ifndef PIO_PINS_H
#define PIO_PINS_H
#define b(PIN) b_(PIN)
#define b_(PIN) LD ## _ ## PIN
static const unsigned char A0 = 1;
#define LD_A0 0
static const unsigned char A1 = 2;
#define LD_A1 1
static const unsigned char A2 = 4;
#define LD_A2 2
static const unsigned char A3 = 8;
#define LD_A3 3
static const unsigned char A4 = 16;
#define LD_A4 4
static const unsigned char A5 = 32;
#define LD_A5 5
static const unsigned char A6 = 64;
#define LD_A6 6
static const unsigned char A7 = 128;
#define LD_A7 7
static const unsigned char B0 = 1;
#define LD_B0 0
static const unsigned char B1 = 2;
#define LD_B1 1
static const unsigned char B2 = 4;
#define LD_B2 2
static const unsigned char B3 = 8;
#define LD_B3 3
static const unsigned char B4 = 16;
#define LD_B4 4
static const unsigned char B5 = 32;
#define LD_B5 5
static const unsigned char B6 = 64;
#define LD_B6 6
static const unsigned char B7 = 128;
#define LD_B7 7
static const unsigned char C0 = 1;
#define LD_C0 0
static const unsigned char C1 = 2;
#define LD_C1 1
static const unsigned char C2 = 4;
#define LD_C2 2
static const unsigned char C3 = 8;
#define LD_C3 3
static const unsigned char C4 = 16;
#define LD_C4 4
static const unsigned char C5 = 32;
#define LD_C5 5
static const unsigned char C6 = 64;
#define LD_C6 6
static const unsigned char C7 = 128;
#define LD_C7 7
static const unsigned char D0 = 1;
#define LD_D0 0
static const unsigned char D1 = 2;
#define LD_D1 1
static const unsigned char D2 = 4;
#define LD_D2 2
static const unsigned char D3 = 8;
#define LD_D3 3
static const unsigned char D4 = 16;
#define LD_D4 4
static const unsigned char D5 = 32;
#define LD_D5 5
static const unsigned char D6 = 64;
#define LD_D6 6
static const unsigned char D7 = 128;
#define LD_D7 7
static const unsigned char E0 = 1;
#define LD_E0 0
static const unsigned char E1 = 2;
#define LD_E1 1
static const unsigned char E2 = 4;
#define LD_E2 2
static const unsigned char E3 = 8;
#define LD_E3 3
static const unsigned char E4 = 16;
#define LD_E4 4
static const unsigned char E5 = 32;
#define LD_E5 5
static const unsigned char E6 = 64;
#define LD_E6 6
static const unsigned char E7 = 128;
#define LD_E7 7
static const unsigned char F0 = 1;
#define LD_F0 0
static const unsigned char F1 = 2;
#define LD_F1 1
static const unsigned char F2 = 4;
#define LD_F2 2
static const unsigned char F3 = 8;
#define LD_F3 3
static const unsigned char F4 = 16;
#define LD_F4 4
static const unsigned char F5 = 32;
#define LD_F5 5
static const unsigned char F6 = 64;
#define LD_F6 6
static const unsigned char F7 = 128;
#define LD_F7 7
#endif // PIO_PINS_H
