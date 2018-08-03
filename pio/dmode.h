#ifndef PIO_DMODE_H
#define PIO_DMODE_H

#define dMode(A, B) dMode_(A, B)
#define dMode_(A, B) DMODE ## _ ## A ## _ ## B

// set pin's mode of PORTA to OUT
#define DMODE_PA0_1 DDRA |= _BV(PA0)
#define DMODE_PA1_1 DDRA |= _BV(PA1)
#define DMODE_PA2_1 DDRA |= _BV(PA2)
#define DMODE_PA3_1 DDRA |= _BV(PA3)
#define DMODE_PA4_1 DDRA |= _BV(PA4)
#define DMODE_PA5_1 DDRA |= _BV(PA5)
#define DMODE_PA6_1 DDRA |= _BV(PA6)
#define DMODE_PA7_1 DDRA |= _BV(PA7)

// set pin's mode of PORTB to OUT
#define DMODE_PB0_1 DDRB |= _BV(PB0)
#define DMODE_PB1_1 DDRB |= _BV(PB1)
#define DMODE_PB2_1 DDRB |= _BV(PB2)
#define DMODE_PB3_1 DDRB |= _BV(PB3)
#define DMODE_PB4_1 DDRB |= _BV(PB4)
#define DMODE_PB5_1 DDRB |= _BV(PB5)
#define DMODE_PB6_1 DDRB |= _BV(PB6)
#define DMODE_PB7_1 DDRB |= _BV(PB7)

// set pin's mode of PORTC to OUT
#define DMODE_PC0_1 DDRC |= _BV(PC0)
#define DMODE_PC1_1 DDRC |= _BV(PC1)
#define DMODE_PC2_1 DDRC |= _BV(PC2)
#define DMODE_PC3_1 DDRC |= _BV(PC3)
#define DMODE_PC4_1 DDRC |= _BV(PC4)
#define DMODE_PC5_1 DDRC |= _BV(PC5)
#define DMODE_PC6_1 DDRC |= _BV(PC6)
#define DMODE_PC7_1 DDRC |= _BV(PC7)

// set pin's mode of PORTD to OUT
#define DMODE_PD0_1 DDRD |= _BV(PD0)
#define DMODE_PD1_1 DDRD |= _BV(PD1)
#define DMODE_PD2_1 DDRD |= _BV(PD2)
#define DMODE_PD3_1 DDRD |= _BV(PD3)
#define DMODE_PD4_1 DDRD |= _BV(PD4)
#define DMODE_PD5_1 DDRD |= _BV(PD5)
#define DMODE_PD6_1 DDRD |= _BV(PD6)
#define DMODE_PD7_1 DDRD |= _BV(PD7)

// set pin's mode of PORTA to IN
#define DMODE_PA0_0 DDRA &= ~_BV(PA0)
#define DMODE_PA1_0 DDRA &= ~_BV(PA1)
#define DMODE_PA2_0 DDRA &= ~_BV(PA2)
#define DMODE_PA3_0 DDRA &= ~_BV(PA3)
#define DMODE_PA4_0 DDRA &= ~_BV(PA4)
#define DMODE_PA5_0 DDRA &= ~_BV(PA5)
#define DMODE_PA6_0 DDRA &= ~_BV(PA6)
#define DMODE_PA7_0 DDRA &= ~_BV(PA7)

// set pin's mode of PORTB to IN
#define DMODE_PB0_0 DDRB &= ~_BV(PB0)
#define DMODE_PB1_0 DDRB &= ~_BV(PB1)
#define DMODE_PB2_0 DDRB &= ~_BV(PB2)
#define DMODE_PB3_0 DDRB &= ~_BV(PB3)
#define DMODE_PB4_0 DDRB &= ~_BV(PB4)
#define DMODE_PB5_0 DDRB &= ~_BV(PB5)
#define DMODE_PB6_0 DDRB &= ~_BV(PB6)
#define DMODE_PB7_0 DDRB &= ~_BV(PB7)

// set pin's mode of PORTC to IN
#define DMODE_PC0_0 DDRC &= ~_BV(PC0)
#define DMODE_PC1_0 DDRC &= ~_BV(PC1)
#define DMODE_PC2_0 DDRC &= ~_BV(PC2)
#define DMODE_PC3_0 DDRC &= ~_BV(PC3)
#define DMODE_PC4_0 DDRC &= ~_BV(PC4)
#define DMODE_PC5_0 DDRC &= ~_BV(PC5)
#define DMODE_PC6_0 DDRC &= ~_BV(PC6)
#define DMODE_PC7_0 DDRC &= ~_BV

// set pin's mode of PORTD to IN
#define DMODE_PD0_0 DDRD &= ~_BV(PD0)
#define DMODE_PD1_0 DDRD &= ~_BV(PD1)
#define DMODE_PD2_0 DDRD &= ~_BV(PD2)
#define DMODE_PD3_0 DDRD &= ~_BV(PD3)
#define DMODE_PD4_0 DDRD &= ~_BV(PD4)
#define DMODE_PD5_0 DDRD &= ~_BV(PD5)
#define DMODE_PD6_0 DDRD &= ~_BV(PD6)
#define DMODE_PD7_0 DDRD &= ~_BV(PD7)

#endif // PIO_DMODE_H
