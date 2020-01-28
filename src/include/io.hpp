#ifndef PIO_IO_HPP
#define PIO_IO_HPP

#ifdef AVR

#include <avr/io.h>

#else

#include <cstdint>

extern std::uint8_t PORTA;
extern std::uint8_t PORTB;
extern std::uint8_t PORTC;
extern std::uint8_t PORTD;
extern std::uint8_t PORTE;
extern std::uint8_t PORTF;

extern std::uint8_t DDRA;
extern std::uint8_t DDRB;
extern std::uint8_t DDRC;
extern std::uint8_t DDRD;
extern std::uint8_t DDRE;
extern std::uint8_t DDRF;

extern std::uint8_t PINA;
extern std::uint8_t PINB;
extern std::uint8_t PINC;
extern std::uint8_t PIND;
extern std::uint8_t PINE;
extern std::uint8_t PINF;

#define PORTA PORTA
#define PORTB PORTB
#define PORTC PORTC
#define PORTD PORTD
#define PORTE PORTE
#define PORTF PORTF

#define DDRA DDRA
#define DDRB DDRB
#define DDRC DDRC
#define DDRD DDRD
#define DDRE DDRE
#define DDRF DDRF

#define PINA PINA
#define PINB PINB
#define PINC PINC
#define PIND PIND
#define PINE PINE
#define PINF PINF

#endif

#endif // PIO_IO_HPP
