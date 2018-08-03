#ifndef PIO_DWRITE_H
#define PIO_DWRITE_H

#define dWrite(A, B) dWrite_(A, B)
#define dWrite_(A, B) DWRITE ## _ ## A ## _ ## B

// DWRITE pin of PORTA to HIGH
#define DWRITE_A0_1 PORTA |= _BV(PA0)
#define DWRITE_A1_1 PORTA |= _BV(PA1)
#define DWRITE_A2_1 PORTA |= _BV(PA2)
#define DWRITE_A3_1 PORTA |= _BV(PA3)
#define DWRITE_A4_1 PORTA |= _BV(PA4)
#define DWRITE_A5_1 PORTA |= _BV(PA5)
#define DWRITE_A6_1 PORTA |= _BV(PA6)
#define DWRITE_A7_1 PORTA |= _BV(PA7)

// DWRITE pin of PORTB to HIGH
#define DWRITE_B0_1 PORTB |= _BV(PB0)
#define DWRITE_B1_1 PORTB |= _BV(PB1)
#define DWRITE_B2_1 PORTB |= _BV(PB2)
#define DWRITE_B3_1 PORTB |= _BV(PB3)
#define DWRITE_B4_1 PORTB |= _BV(PB4)
#define DWRITE_B5_1 PORTB |= _BV(PB5)
#define DWRITE_B6_1 PORTB |= _BV(PB6)
#define DWRITE_B7_1 PORTB |= _BV(PB7)

// DWRITE pin of PORTC to HIGH
#define DWRITE_C0_1 PORTC |= _BV(PC0)
#define DWRITE_C1_1 PORTC |= _BV(PC1)
#define DWRITE_C2_1 PORTC |= _BV(PC2)
#define DWRITE_C3_1 PORTC |= _BV(PC3)
#define DWRITE_C4_1 PORTC |= _BV(PC4)
#define DWRITE_C5_1 PORTC |= _BV(PC5)
#define DWRITE_C6_1 PORTC |= _BV(PC6)
#define DWRITE_C7_1 PORTC |= _BV(PC7)

// DWRITE pin of PORTD to HIGH
#define DWRITE_D0_1 PORTD |= _BV(PD0)
#define DWRITE_D1_1 PORTD |= _BV(PD1)
#define DWRITE_D2_1 PORTD |= _BV(PD2)
#define DWRITE_D3_1 PORTD |= _BV(PD3)
#define DWRITE_D4_1 PORTD |= _BV(PD4)
#define DWRITE_D5_1 PORTD |= _BV(PD5)
#define DWRITE_D6_1 PORTD |= _BV(PD6)
#define DWRITE_D7_1 PORTD |= _BV(PD7)

// DWRITE pin of PORTA to LOW
#define DWRITE_A0_0 PORTA &= ~_BV(PA0)
#define DWRITE_A1_0 PORTA &= ~_BV(PA1)
#define DWRITE_A2_0 PORTA &= ~_BV(PA2)
#define DWRITE_A3_0 PORTA &= ~_BV(PA3)
#define DWRITE_A4_0 PORTA &= ~_BV(PA4)
#define DWRITE_A5_0 PORTA &= ~_BV(PA5)
#define DWRITE_A6_0 PORTA &= ~_BV(PA6)
#define DWRITE_A7_0 PORTA &= ~_BV(PA7)

// DWRITE pin of PORTB to LOW
#define DWRITE_B0_0 PORTB &= ~_BV(PB0)
#define DWRITE_B1_0 PORTB &= ~_BV(PB1)
#define DWRITE_B2_0 PORTB &= ~_BV(PB2)
#define DWRITE_B3_0 PORTB &= ~_BV(PB3)
#define DWRITE_B4_0 PORTB &= ~_BV(PB4)
#define DWRITE_B5_0 PORTB &= ~_BV(PB5)
#define DWRITE_B6_0 PORTB &= ~_BV(PB6)
#define DWRITE_B7_0 PORTB &= ~_BV(PB7)

// DWRITE pin of PORTC to LOW
#define DWRITE_C0_0 PORTC &= ~_BV(PC0)
#define DWRITE_C1_0 PORTC &= ~_BV(PC1)
#define DWRITE_C2_0 PORTC &= ~_BV(PC2)
#define DWRITE_C3_0 PORTC &= ~_BV(PC3)
#define DWRITE_C4_0 PORTC &= ~_BV(PC4)
#define DWRITE_C5_0 PORTC &= ~_BV(PC5)
#define DWRITE_C6_0 PORTC &= ~_BV(PC6)
#define DWRITE_C7_0 PORTC &= ~_BV(PC7)

// DWRITE pin of PORTD to LOW
#define DWRITE_D0_0 PORTD &= ~_BV(PD0)
#define DWRITE_D1_0 PORTD &= ~_BV(PD1)
#define DWRITE_D2_0 PORTD &= ~_BV(PD2)
#define DWRITE_D3_0 PORTD &= ~_BV(PD3)
#define DWRITE_D4_0 PORTD &= ~_BV(PD4)
#define DWRITE_D5_0 PORTD &= ~_BV(PD5)
#define DWRITE_D6_0 PORTD &= ~_BV(PD6)
#define DWRITE_D7_0 PORTD &= ~_BV(PD7)

#endif // PIO_DWRITE_H
