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

#if !defined(PIO_TYPE_TRAITS) && defined(DDRA)
#define PIO_TYPE_TRAITS
using DDR_T = decltype(DDRA);
using PORT_T = decltype(PORTA);
using PIN_T = decltype(PINA);
#endif

#if !defined(PIO_TYPE_TRAITS) && defined(DDRB)
#define PIO_TYPE_TRAITS
using DDR_T = decltype(DDRB);
using PORT_T = decltype(PORTB);
using PIN_T = decltype(PINB);
#endif

#if !defined(PIO_TYPE_TRAITS) && defined(DDRC)
#define PIO_TYPE_TRAITS
using DDR_T = decltype(DDRC);
using PORT_T = decltype(PORTC);
using PIN_T = decltype(PINC);
#endif

#if !defined(PIO_TYPE_TRAITS) && defined(DDRD)
#define PIO_TYPE_TRAITS
using DDR_T = decltype(DDRD);
using PORT_T = decltype(PORTD);
using PIN_T = decltype(PIND);
#endif

#if !defined(PIO_TYPE_TRAITS) && defined(DDRE)
#define PIO_TYPE_TRAITS
using DDR_T = decltype(DDRE);
using PORT_T = decltype(PORTE);
using PIN_T = decltype(PINE);
#endif

#if !defined(PIO_TYPE_TRAITS) && defined(DDRF)
#define PIO_TYPE_TRAITS
using DDR_T = decltype(DDRF);
using PORT_T = decltype(PORTF);
using PIN_T = decltype(PINF);
#endif

#endif // PIO_IO_HPP
