#ifndef PIO_DREAD_H
#define PIO_DREAD_H

#define dRead(A) dRead_(A)
#define dRead_(A) DREAD ## _ ## A

// DREAD pin of PORTA
#define DREAD_PA0 (PINA & _BV(PA0))
#define DREAD_PA1 (PINA & _BV(PA1))
#define DREAD_PA2 (PINA & _BV(PA2))
#define DREAD_PA3 (PINA & _BV(PA3))
#define DREAD_PA4 (PINA & _BV(PA4))
#define DREAD_PA5 (PINA & _BV(PA5))
#define DREAD_PA6 (PINA & _BV(PA6))
#define DREAD_PA7 (PINA & _BV(PA7))

// DREAD pin of PORTB
#define DREAD_PB0 (PINB & _BV(PB0))
#define DREAD_PB1 (PINB & _BV(PB1))
#define DREAD_PB2 (PINB & _BV(PB2))
#define DREAD_PB3 (PINB & _BV(PB3))
#define DREAD_PB4 (PINB & _BV(PB4))
#define DREAD_PB5 (PINB & _BV(PB5))
#define DREAD_PB6 (PINB & _BV(PB6))
#define DREAD_PB7 (PINB & _BV(PB7))

// DREAD pin of PORTC
#define DREAD_PC0 (PINC & _BV(PC0))
#define DREAD_PC1 (PINC & _BV(PC1))
#define DREAD_PC2 (PINC & _BV(PC2))
#define DREAD_PC3 (PINC & _BV(PC3))
#define DREAD_PC4 (PINC & _BV(PC4))
#define DREAD_PC5 (PINC & _BV(PC5))
#define DREAD_PC6 (PINC & _BV(PC6))
#define DREAD_PC7 (PINC & _BV(PC7))

// DREAD pin of PORTD
#define DREAD_PD0 (PIND & _BV(PD0))
#define DREAD_PD1 (PIND & _BV(PD1))
#define DREAD_PD2 (PIND & _BV(PD2))
#define DREAD_PD3 (PIND & _BV(PD3))
#define DREAD_PD4 (PIND & _BV(PD4))
#define DREAD_PD5 (PIND & _BV(PD5))
#define DREAD_PD6 (PIND & _BV(PD6))
#define DREAD_PD7 (PIND & _BV(PD7))

#endif // PIO_DREAD_H
