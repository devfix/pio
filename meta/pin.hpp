#ifndef PINS_PIN_HPP
#define PINS_PIN_HPP

#include "io.h"

#ifndef AVR

#include <bitset>

#endif


/**
 * lookup table + hardware
 */

template<char P>
struct PortRegister {};

#ifdef PORTA
template<>
struct PortRegister<'A'> {
	static constexpr auto *value = &PORTA;
};
#endif

#ifdef PORTB
template<>
struct PortRegister<'B'> {
	static constexpr auto *value = &PORTB;
};
#endif


#ifdef PORTC
template<>
struct PortRegister<'C'> {
	static constexpr auto *value = &PORTC;
};
#endif


#ifdef PORTD
template<>
struct PortRegister<'D'> {
	static constexpr auto *value = &PORTD;
};
#endif

/**
 * pin
 */

template<char P, unsigned char L>
struct pin;

template<unsigned char L>
struct pin<'A', L> {
	static void high() { PORTA |= L; }
	static void low() { PORTA &= ~L; }
};

template<unsigned char L>
struct pin<'B', L> {
	static void high() { PORTB |= L; }
	static void low() { PORTB &= ~L; }
};

template<unsigned char L>
struct pin<'C', L> {
	static void high() { PORTC |= L; }
	static void low() { PORTC &= ~L; }
};

template<unsigned char L>
struct pin<'D', L> {
	static void high() { PORTD |= L; }
	static void low() { PORTD &= ~L; }
};


template<char P1, unsigned char L1, char P2, unsigned char L2>
constexpr bool operator<=(pin<P1, L1>, pin<P2, L2>) {
	return P1 == P2 ? L1 <= L2 : P1 <= P2;
}

using A0 = pin<'A', 0x01>;
using A1 = pin<'A', 0x02>;
using A2 = pin<'A', 0x04>;
using A3 = pin<'A', 0x08>;
using A4 = pin<'A', 0x10>;
using A5 = pin<'A', 0x20>;
using A6 = pin<'A', 0x40>;
using A7 = pin<'A', 0x80>;

using B0 = pin<'B', 0x01>;
using B1 = pin<'B', 0x02>;
using B2 = pin<'B', 0x04>;
using B3 = pin<'B', 0x08>;
using B4 = pin<'B', 0x10>;
using B5 = pin<'B', 0x20>;
using B6 = pin<'B', 0x40>;
using B7 = pin<'B', 0x80>;

using C0 = pin<'C', 0x01>;
using C1 = pin<'C', 0x02>;
using C2 = pin<'C', 0x04>;
using C3 = pin<'C', 0x08>;
using C4 = pin<'C', 0x10>;
using C5 = pin<'C', 0x20>;
using C6 = pin<'C', 0x40>;
using C7 = pin<'C', 0x80>;

using D0 = pin<'D', 0x01>;
using D1 = pin<'D', 0x02>;
using D2 = pin<'D', 0x04>;
using D3 = pin<'D', 0x08>;
using D4 = pin<'D', 0x10>;
using D5 = pin<'D', 0x20>;
using D6 = pin<'D', 0x40>;
using D7 = pin<'D', 0x80>;


#endif //PINS_PIN_HPP
