#ifndef PINS_PIN_HPP
#define PINS_PIN_HPP

#include "io.h"


/**
 * pin
 */

template<char P, unsigned char L>
struct pio_pin;

#ifdef PORTA
template<unsigned char L>
struct pio_pin<'A', L> {
    FORCE_INLINE static void port_set() { PORTA |= L; }
    FORCE_INLINE static void port_clear() { PORTA &= ~L; }
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
    FORCE_INLINE static void port_set() { PORTB |= L; }
    FORCE_INLINE static void port_clear() { PORTB &= ~L; }
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
    FORCE_INLINE static void port_set() { PORTC |= L; }
    FORCE_INLINE static void port_clear() { PORTC &= ~L; }
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
    FORCE_INLINE static void port_set() { PORTD |= L; }
    FORCE_INLINE static void port_clear() { PORTD &= ~L; }
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
    FORCE_INLINE static void port_set() { PORTE |= L; }
    FORCE_INLINE static void port_clear() { PORTE &= ~L; }
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
    FORCE_INLINE static void port_set() { PORTF |= L; }
    FORCE_INLINE static void port_clear() { PORTF &= ~L; }
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


using A0 = pio_pin<'A', 0x01>;
using A1 = pio_pin<'A', 0x02>;
using A2 = pio_pin<'A', 0x04>;
using A3 = pio_pin<'A', 0x08>;
using A4 = pio_pin<'A', 0x10>;
using A5 = pio_pin<'A', 0x20>;
using A6 = pio_pin<'A', 0x40>;
using A7 = pio_pin<'A', 0x80>;

using B0 = pio_pin<'B', 0x01>;
using B1 = pio_pin<'B', 0x02>;
using B2 = pio_pin<'B', 0x04>;
using B3 = pio_pin<'B', 0x08>;
using B4 = pio_pin<'B', 0x10>;
using B5 = pio_pin<'B', 0x20>;
using B6 = pio_pin<'B', 0x40>;
using B7 = pio_pin<'B', 0x80>;

using C0 = pio_pin<'C', 0x01>;
using C1 = pio_pin<'C', 0x02>;
using C2 = pio_pin<'C', 0x04>;
using C3 = pio_pin<'C', 0x08>;
using C4 = pio_pin<'C', 0x10>;
using C5 = pio_pin<'C', 0x20>;
using C6 = pio_pin<'C', 0x40>;
using C7 = pio_pin<'C', 0x80>;

using D0 = pio_pin<'D', 0x01>;
using D1 = pio_pin<'D', 0x02>;
using D2 = pio_pin<'D', 0x04>;
using D3 = pio_pin<'D', 0x08>;
using D4 = pio_pin<'D', 0x10>;
using D5 = pio_pin<'D', 0x20>;
using D6 = pio_pin<'D', 0x40>;
using D7 = pio_pin<'D', 0x80>;

using E0 = pio_pin<'E', 0x01>;
using E1 = pio_pin<'E', 0x02>;
using E2 = pio_pin<'E', 0x04>;
using E3 = pio_pin<'E', 0x08>;
using E4 = pio_pin<'E', 0x10>;
using E5 = pio_pin<'E', 0x20>;
using E6 = pio_pin<'E', 0x40>;
using E7 = pio_pin<'E', 0x80>;

using F0 = pio_pin<'F', 0x01>;
using F1 = pio_pin<'F', 0x02>;
using F2 = pio_pin<'F', 0x04>;
using F3 = pio_pin<'F', 0x08>;
using F4 = pio_pin<'F', 0x10>;
using F5 = pio_pin<'F', 0x20>;
using F6 = pio_pin<'F', 0x40>;
using F7 = pio_pin<'F', 0x80>;

#endif //PINS_PIN_HPP
