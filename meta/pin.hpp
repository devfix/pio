#ifndef PINS_PIN_HPP
#define PINS_PIN_HPP

#ifndef AVR
#include <bitset>
#else
#include <avr/io.h>
#endif


/**
 * lookup table + hardware
 */

#ifndef AVR
unsigned char PORTA{};
unsigned char PORTB{};
unsigned char PORTC{};
unsigned char PORTD{};
#endif

template<char P>
struct PortRegister {};

#ifdef PORTA
template<>
struct PortRegister<'A'> {
    static constexpr auto* value = &PORTA;
};
#endif

#ifdef PORTB
template<>
struct PortRegister<'B'> {
    static constexpr auto* value = &PORTB;
};
#endif


#ifdef PORTC
template<>
struct PortRegister<'C'> {
    static constexpr auto* value = &PORTC;
};
#endif


#ifdef PORTD
template<>
struct PortRegister<'D'> {
    static constexpr auto* value = &PORTD;
};
#endif

/**
 * pin
 */

template<char P, unsigned char L>
struct pin {
#ifndef AVR
    friend std::ostream& operator<<(std::ostream& os, const pin<P, L>& p) {
        return os << P << std::bitset<8>(L);
    }
#endif

    void high() {
        *PortRegister<P>::value |= L;
    }

    void low() {
        *PortRegister<P>::value &= ~L;
    }
};

template<char P1, unsigned char L1, char P2, unsigned char L2>
constexpr bool operator<=(pin<P1, L1>, pin<P2, L2>) {
    return P1 == P2 ? L1 <= L2 : P1 <= P2;
}

using A0 = pin<'A', 0x1>;
using A1 = pin<'A', 0x2>;
using A2 = pin<'A', 0x4>;
using A3 = pin<'A', 0x8>;
using A4 = pin<'A', 0x10>;
using A5 = pin<'A', 0x20>;
using A6 = pin<'A', 0x40>;
using A7 = pin<'A', 0x80>;

using B0 = pin<'B', 0x1>;

using C0 = pin<'C', 0x1>;

using D0 = pin<'D', 0x1>;


#endif //PINS_PIN_HPP
