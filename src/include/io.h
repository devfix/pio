#ifndef PIO_IO_HPP
#define PIO_IO_HPP

using DDR_T = unsigned char;
using PORT_T = unsigned char;
using PIN_T = unsigned char;

#ifdef AVR

#include <avr/io.h>

#else

#include <cstdint>

extern DDR_T DDRA;
extern DDR_T DDRB;
extern DDR_T DDRC;
extern DDR_T DDRD;
extern DDR_T DDRE;
extern DDR_T DDRF;

extern PORT_T PORTA;
extern PORT_T PORTB;
extern PORT_T PORTC;
extern PORT_T PORTD;
extern PORT_T PORTE;
extern PORT_T PORTF;

extern PIN_T PINA;
extern PIN_T PINB;
extern PIN_T PINC;
extern PIN_T PIND;
extern PIN_T PINE;
extern PIN_T PINF;

#define DDRA DDRA
#define DDRB DDRB
#define DDRC DDRC
#define DDRD DDRD
#define DDRE DDRE
#define DDRF DDRF

#define PORTA PORTA
#define PORTB PORTB
#define PORTC PORTC
#define PORTD PORTD
#define PORTE PORTE
#define PORTF PORTF

#define PINA PINA
#define PINB PINB
#define PINC PINC
#define PIND PIND
#define PINE PINE
#define PINF PINF

#endif

#endif // PIO_IO_HPP
