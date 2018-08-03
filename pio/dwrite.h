#ifndef PIO_DWRITE_H
#define PIO_DWRITE_H

#define dWrite(A, B) dWrite_(A, B)
#define dWrite_(A, B) DWRITE ## _ ## A ## _ ## B

// DWRITE pin of PORTA to HIGH
#define DWRITE_PA0_1 PORTA |= _BV(PA0)
#define DWRITE_PA1_1 PORTA |= _BV(PA1)
#define DWRITE_PA2_1 PORTA |= _BV(PA2)
#define DWRITE_PA3_1 PORTA |= _BV(PA3)
#define DWRITE_PA4_1 PORTA |= _BV(PA4)
#define DWRITE_PA5_1 PORTA |= _BV(PA5)
#define DWRITE_PA6_1 PORTA |= _BV(PA6)
#define DWRITE_PA7_1 PORTA |= _BV(PA7)

// DWRITE pin of PORTB to HIGH
#define DWRITE_PB0_1 PORTB |= _BV(PB0)
#define DWRITE_PB1_1 PORTB |= _BV(PB1)
#define DWRITE_PB2_1 PORTB |= _BV(PB2)
#define DWRITE_PB3_1 PORTB |= _BV(PB3)
#define DWRITE_PB4_1 PORTB |= _BV(PB4)
#define DWRITE_PB5_1 PORTB |= _BV(PB5)
#define DWRITE_PB6_1 PORTB |= _BV(PB6)
#define DWRITE_PB7_1 PORTB |= _BV(PB7)

// DWRITE pin of PORTC to HIGH
#define DWRITE_PC0_1 PORTC |= _BV(PC0)
#define DWRITE_PC1_1 PORTC |= _BV(PC1)
#define DWRITE_PC2_1 PORTC |= _BV(PC2)
#define DWRITE_PC3_1 PORTC |= _BV(PC3)
#define DWRITE_PC4_1 PORTC |= _BV(PC4)
#define DWRITE_PC5_1 PORTC |= _BV(PC5)
#define DWRITE_PC6_1 PORTC |= _BV(PC6)
#define DWRITE_PC7_1 PORTC |= _BV(PC7)

// DWRITE pin of PORTD to HIGH
#define DWRITE_PD0_1 PORTD |= _BV(PD0)
#define DWRITE_PD1_1 PORTD |= _BV(PD1)
#define DWRITE_PD2_1 PORTD |= _BV(PD2)
#define DWRITE_PD3_1 PORTD |= _BV(PD3)
#define DWRITE_PD4_1 PORTD |= _BV(PD4)
#define DWRITE_PD5_1 PORTD |= _BV(PD5)
#define DWRITE_PD6_1 PORTD |= _BV(PD6)
#define DWRITE_PD7_1 PORTD |= _BV(PD7)

// DWRITE pin of PORTA to LOW
#define DWRITE_PA0_0 PORTA &= ~_BV(PA0)
#define DWRITE_PA1_0 PORTA &= ~_BV(PA1)
#define DWRITE_PA2_0 PORTA &= ~_BV(PA2)
#define DWRITE_PA3_0 PORTA &= ~_BV(PA3)
#define DWRITE_PA4_0 PORTA &= ~_BV(PA4)
#define DWRITE_PA5_0 PORTA &= ~_BV(PA5)
#define DWRITE_PA6_0 PORTA &= ~_BV(PA6)
#define DWRITE_PA7_0 PORTA &= ~_BV(PA7)

// DWRITE pin of PORTB to LOW
#define DWRITE_PB0_0 PORTB &= ~_BV(PB0)
#define DWRITE_PB1_0 PORTB &= ~_BV(PB1)
#define DWRITE_PB2_0 PORTB &= ~_BV(PB2)
#define DWRITE_PB3_0 PORTB &= ~_BV(PB3)
#define DWRITE_PB4_0 PORTB &= ~_BV(PB4)
#define DWRITE_PB5_0 PORTB &= ~_BV(PB5)
#define DWRITE_PB6_0 PORTB &= ~_BV(PB6)
#define DWRITE_PB7_0 PORTB &= ~_BV(PB7)

// DWRITE pin of PORTC to LOW
#define DWRITE_PC0_0 PORTC &= ~_BV(PC0)
#define DWRITE_PC1_0 PORTC &= ~_BV(PC1)
#define DWRITE_PC2_0 PORTC &= ~_BV(PC2)
#define DWRITE_PC3_0 PORTC &= ~_BV(PC3)
#define DWRITE_PC4_0 PORTC &= ~_BV(PC4)
#define DWRITE_PC5_0 PORTC &= ~_BV(PC5)
#define DWRITE_PC6_0 PORTC &= ~_BV(PC6)
#define DWRITE_PC7_0 PORTC &= ~_BV(PC7)

// DWRITE pin of PORTD to LOW
#define DWRITE_PD0_0 PORTD &= ~_BV(PD0)
#define DWRITE_PD1_0 PORTD &= ~_BV(PD1)
#define DWRITE_PD2_0 PORTD &= ~_BV(PD2)
#define DWRITE_PD3_0 PORTD &= ~_BV(PD3)
#define DWRITE_PD4_0 PORTD &= ~_BV(PD4)
#define DWRITE_PD5_0 PORTD &= ~_BV(PD5)
#define DWRITE_PD6_0 PORTD &= ~_BV(PD6)
#define DWRITE_PD7_0 PORTD &= ~_BV(PD7)

#endif // PIO_DWRITE_H
