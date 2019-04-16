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

#define d(A) d_(A)
#define d_(A) DDR ## _ ## A

#endif // PIO_DDR_H
