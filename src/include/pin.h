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
    FORCE_INLINE static void ddr_set() { DDRA |= L; }
    FORCE_INLINE static void ddr_clear() { DDRA &= ~L; }
    FORCE_INLINE static void port_set() { PORTA |= L; }
    FORCE_INLINE static void port_clear() { PORTA &= ~L; }
    static constexpr PIN_T pin_get() { return PINA & L; }
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
    FORCE_INLINE static void ddr_set() { DDRB |= L; }
    FORCE_INLINE static void ddr_clear() { DDRB &= ~L; }
    FORCE_INLINE static void port_set() { PORTB |= L; }
    FORCE_INLINE static void port_clear() { PORTB &= ~L; }
    static constexpr PIN_T pin_get() { return PINB & L; }
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
    FORCE_INLINE static void ddr_set() { DDRC |= L; }
    FORCE_INLINE static void ddr_clear() { DDRC &= ~L; }
    FORCE_INLINE static void port_set() { PORTC |= L; }
    FORCE_INLINE static void port_clear() { PORTC &= ~L; }
    static constexpr PIN_T pin_get() { return PINC & L; }
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
    FORCE_INLINE static void ddr_set() { DDRD |= L; }
    FORCE_INLINE static void ddr_clear() { DDRD &= ~L; }
    FORCE_INLINE static void port_set() { PORTD |= L; }
    FORCE_INLINE static void port_clear() { PORTD &= ~L; }
    static constexpr PIN_T pin_get() { return PIND & L; }
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
    FORCE_INLINE static void ddr_set() { DDRE |= L; }
    FORCE_INLINE static void ddr_clear() { DDRE &= ~L; }
    FORCE_INLINE static void port_set() { PORTE |= L; }
    FORCE_INLINE static void port_clear() { PORTE &= ~L; }
    static constexpr PIN_T pin_get() { return PINE & L; }
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
    FORCE_INLINE static void ddr_set() { DDRF |= L; }
    FORCE_INLINE static void ddr_clear() { DDRF &= ~L; }
    FORCE_INLINE static void port_set() { PORTF |= L; }
    FORCE_INLINE static void port_clear() { PORTF &= ~L; }
    static constexpr PIN_T pin_get() { return PINF & L; }
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
