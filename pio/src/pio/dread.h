#ifndef PIO_DREAD_H
#define PIO_DREAD_H

#define dRead(A) dRead_(A)
#define dRead_(A) DREAD ## _ ## A

// DREAD pin of PORTA
#define DREAD_A0 (PINA & _BV(PA0))
#define DREAD_A1 (PINA & _BV(PA1))
#define DREAD_A2 (PINA & _BV(PA2))
#define DREAD_A3 (PINA & _BV(PA3))
#define DREAD_A4 (PINA & _BV(PA4))
#define DREAD_A5 (PINA & _BV(PA5))
#define DREAD_A6 (PINA & _BV(PA6))
#define DREAD_A7 (PINA & _BV(PA7))

// DREAD pin of PORTB
#define DREAD_B0 (PINB & _BV(PB0))
#define DREAD_B1 (PINB & _BV(PB1))
#define DREAD_B2 (PINB & _BV(PB2))
#define DREAD_B3 (PINB & _BV(PB3))
#define DREAD_B4 (PINB & _BV(PB4))
#define DREAD_B5 (PINB & _BV(PB5))
#define DREAD_B6 (PINB & _BV(PB6))
#define DREAD_B7 (PINB & _BV(PB7))

// DREAD pin of PORTC
#define DREAD_C0 (PINC & _BV(PC0))
#define DREAD_C1 (PINC & _BV(PC1))
#define DREAD_C2 (PINC & _BV(PC2))
#define DREAD_C3 (PINC & _BV(PC3))
#define DREAD_C4 (PINC & _BV(PC4))
#define DREAD_C5 (PINC & _BV(PC5))
#define DREAD_C6 (PINC & _BV(PC6))
#define DREAD_C7 (PINC & _BV(PC7))

// DREAD pin of PORTD
#define DREAD_D0 (PIND & _BV(PD0))
#define DREAD_D1 (PIND & _BV(PD1))
#define DREAD_D2 (PIND & _BV(PD2))
#define DREAD_D3 (PIND & _BV(PD3))
#define DREAD_D4 (PIND & _BV(PD4))
#define DREAD_D5 (PIND & _BV(PD5))
#define DREAD_D6 (PIND & _BV(PD6))
#define DREAD_D7 (PIND & _BV(PD7))

#endif // PIO_DREAD_H
