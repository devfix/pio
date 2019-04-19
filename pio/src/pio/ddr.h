/***
 * ddr.h
 * This file is part of the PIO library.
 * For license information see "pio.h" in the parent directory.
 */

#if !defined(PIOLIB) || PIOLIB < 200
#error This file should not be included directly. Use "pio.h" instead.
#endif
#ifndef PIO_DDR_H
#define PIO_DDR_H
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
#endif
#ifdef DDRB
#define DDR_B0 DDRB
#define DDR_B1 DDRB
#define DDR_B2 DDRB
#define DDR_B3 DDRB
#define DDR_B4 DDRB
#define DDR_B5 DDRB
#define DDR_B6 DDRB
#define DDR_B7 DDRB
#endif
#ifdef DDRC
#define DDR_C0 DDRC
#define DDR_C1 DDRC
#define DDR_C2 DDRC
#define DDR_C3 DDRC
#define DDR_C4 DDRC
#define DDR_C5 DDRC
#define DDR_C6 DDRC
#define DDR_C7 DDRC
#endif
#ifdef DDRD
#define DDR_D0 DDRD
#define DDR_D1 DDRD
#define DDR_D2 DDRD
#define DDR_D3 DDRD
#define DDR_D4 DDRD
#define DDR_D5 DDRD
#define DDR_D6 DDRD
#define DDR_D7 DDRD
#endif
#ifdef DDRE
#define DDR_E0 DDRE
#define DDR_E1 DDRE
#define DDR_E2 DDRE
#define DDR_E3 DDRE
#define DDR_E4 DDRE
#define DDR_E5 DDRE
#define DDR_E6 DDRE
#define DDR_E7 DDRE
#endif
#ifdef DDRF
#define DDR_F0 DDRF
#define DDR_F1 DDRF
#define DDR_F2 DDRF
#define DDR_F3 DDRF
#define DDR_F4 DDRF
#define DDR_F5 DDRF
#define DDR_F6 DDRF
#define DDR_F7 DDRF
#endif
#endif // PIO_DDR_H
