#ifndef PIO_PIN_HPP
#define PIO_PIN_HPP

#include "io.h"


/**
 * pin
 */

template<char P, unsigned char L>
struct pio_pin;

#ifdef PORTA
template<unsigned char L>
struct pio_pin<'A', L> {
	static constexpr decltype(L) LEAD = L;
    static constexpr DDR_T* DDR = &DDRA;
    static constexpr PORT_T* PORT = &PORTA;
    static constexpr PIN_T* PIN = &PINA;
#ifndef AVR
    friend std::ostream &operator<<(std::ostream &os, const pio_pin& pin) {
        return os << "A" << (int)L << " ";
    }
#endif
};
#endif


#ifdef PORTB
template<unsigned char L>
struct pio_pin<'B', L> {
	static constexpr decltype(L) LEAD = L;
    static constexpr DDR_T* DDR = &DDRB;
    static constexpr PORT_T* PORT = &PORTB;
    static constexpr PIN_T* PIN = &PINB;
#ifndef AVR
    friend std::ostream &operator<<(std::ostream &os, const pio_pin& pin) {
        return os << "B" << (int)L << " ";
    }
#endif
};
#endif


#ifdef PORTC
template<unsigned char L>
struct pio_pin<'C', L> {
	static constexpr decltype(L) LEAD = L;
    static constexpr DDR_T* DDR = &DDRC;
    static constexpr PORT_T* PORT = &PORTC;
    static constexpr PIN_T* PIN = &PINC;
#ifndef AVR
    friend std::ostream &operator<<(std::ostream &os, const pio_pin& pin) {
        return os << "C" << (int)L << " ";
    }
#endif
};
#endif


#ifdef PORTD
template<unsigned char L>
struct pio_pin<'D', L> {
	static constexpr decltype(L) LEAD = L;
    static constexpr DDR_T* DDR = &DDRD;
    static constexpr PORT_T* PORT = &PORTD;
    static constexpr PIN_T* PIN = &PIND;
#ifndef AVR
    friend std::ostream &operator<<(std::ostream &os, const pio_pin& pin) {
        return os << "D" << (int)L << " ";
    }
#endif
};
#endif


#ifdef PORTE
template<unsigned char L>
struct pio_pin<'E', L> {
	static constexpr decltype(L) LEAD = L;
    static constexpr DDR_T* DDR = &DDRE;
    static constexpr PORT_T* PORT = &PORTE;
    static constexpr PIN_T* PIN = &PINE;
#ifndef AVR
    friend std::ostream &operator<<(std::ostream &os, const pio_pin& pin) {
        return os << "E" << (int)L << " ";
    }
#endif
};
#endif


#ifdef PORTF
template<unsigned char L>
struct pio_pin<'F', L> {
	static constexpr decltype(L) LEAD = L;
    static constexpr DDR_T* DDR = &DDRF;
    static constexpr PORT_T* PORT = &PORTF;
    static constexpr PIN_T* PIN = &PINF;
#ifndef AVR
    friend std::ostream &operator<<(std::ostream &os, const pio_pin& pin) {
        return os << "F" << (int)L << " ";
    }
#endif
};
#endif


template<char P1, unsigned char L1, char P2, unsigned char L2>
constexpr bool operator<=(pio_pin<P1, L1>, pio_pin<P2, L2>) {
	return P1 == P2 ? L1 <= L2 : P1 <= P2;
}


using LA0 = pio_pin<'A', 0x01>;
using LA1 = pio_pin<'A', 0x02>;
using LA2 = pio_pin<'A', 0x04>;
using LA3 = pio_pin<'A', 0x08>;
using LA4 = pio_pin<'A', 0x10>;
using LA5 = pio_pin<'A', 0x20>;
using LA6 = pio_pin<'A', 0x40>;
using LA7 = pio_pin<'A', 0x80>;

using LB0 = pio_pin<'B', 0x01>;
using LB1 = pio_pin<'B', 0x02>;
using LB2 = pio_pin<'B', 0x04>;
using LB3 = pio_pin<'B', 0x08>;
using LB4 = pio_pin<'B', 0x10>;
using LB5 = pio_pin<'B', 0x20>;
using LB6 = pio_pin<'B', 0x40>;
using LB7 = pio_pin<'B', 0x80>;

using LC0 = pio_pin<'C', 0x01>;
using LC1 = pio_pin<'C', 0x02>;
using LC2 = pio_pin<'C', 0x04>;
using LC3 = pio_pin<'C', 0x08>;
using LC4 = pio_pin<'C', 0x10>;
using LC5 = pio_pin<'C', 0x20>;
using LC6 = pio_pin<'C', 0x40>;
using LC7 = pio_pin<'C', 0x80>;

using LD0 = pio_pin<'D', 0x01>;
using LD1 = pio_pin<'D', 0x02>;
using LD2 = pio_pin<'D', 0x04>;
using LD3 = pio_pin<'D', 0x08>;
using LD4 = pio_pin<'D', 0x10>;
using LD5 = pio_pin<'D', 0x20>;
using LD6 = pio_pin<'D', 0x40>;
using LD7 = pio_pin<'D', 0x80>;

using LE0 = pio_pin<'E', 0x01>;
using LE1 = pio_pin<'E', 0x02>;
using LE2 = pio_pin<'E', 0x04>;
using LE3 = pio_pin<'E', 0x08>;
using LE4 = pio_pin<'E', 0x10>;
using LE5 = pio_pin<'E', 0x20>;
using LE6 = pio_pin<'E', 0x40>;
using LE7 = pio_pin<'E', 0x80>;

using LF0 = pio_pin<'F', 0x01>;
using LF1 = pio_pin<'F', 0x02>;
using LF2 = pio_pin<'F', 0x04>;
using LF3 = pio_pin<'F', 0x08>;
using LF4 = pio_pin<'F', 0x10>;
using LF5 = pio_pin<'F', 0x20>;
using LF6 = pio_pin<'F', 0x40>;
using LF7 = pio_pin<'F', 0x80>;

#endif // PIO_PIN_HPP
