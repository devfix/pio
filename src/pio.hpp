/***
*     _______  _____   ___
*    |_   __ \|_   _|.'   `.
*      | |__) | | | /  .-.  \
*      |  ___/  | | | |   | |
*     _| |_    _| |_\  `-'  /
*    |_____|  |_____|`.___.'
*
*      Avr Pin I/O Library
*
*    ~ version 2.0
*    ~ written by Jonas Höfer, Tristan Krause
*    ~ visit github.com/devfix/pio
*
*    You should have received a copy of the MIT License.
*    If not, see <https://opensource.org/licenses/MIT>.
*
*/
#ifndef CONDITIONAL_H
#define CONDITIONAL_H
template<bool B, class T, class F>
struct conditional {
    typedef T type;
};
template<class T, class F>
struct conditional<false, T, F> {
    typedef F type;
};
template<bool B, class T, class F>
using conditional_t = typename conditional<B, T, F>::type;
#endif //CONDITIONAL_H
#ifndef PIO_MEM_HPP
#define PIO_MEM_HPP
#ifdef AVR
#define FORCE_INLINE __attribute__((always_inline)) inline
#else
#define FORCE_INLINE inline
#endif
#endif //PIO_MEM_HPP
#ifndef IO_H
#define IO_H
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
#endif //IO_H
#ifndef PINS_LIST_HPP
#define PINS_LIST_HPP
#ifndef AVR
#include <ostream>
#endif
/**
 * constructors for a linkedlist
 */
struct nil {
    FORCE_INLINE static void ddr_set() {}
    FORCE_INLINE static void ddr_clear() {}
    FORCE_INLINE static void port_set() {}
    FORCE_INLINE static void port_clear() {}
#ifndef AVR
    friend std::ostream &operator<<(std::ostream &os, const nil &) {
        return os;
    }
#endif
};
template<typename X, typename XS>
struct cons {
    FORCE_INLINE static void ddr_set() {
        X().ddr_set();
        XS().ddr_set();
    }
    FORCE_INLINE static void ddr_clear() {
        X().ddr_clear();
        XS().ddr_clear();
    }
    FORCE_INLINE static void port_set() {
        X().port_set();
        XS().port_set();
    }
    FORCE_INLINE static void port_clear() {
        X().port_clear();
        XS().port_clear();
    }
#ifndef AVR
    friend std::ostream &operator<<(std::ostream &os, const cons<X, XS> &) {
        return os << X() << " " << XS();
    }
#endif
};
/**
 * build
 * creates a linkedlist from variadic template
 */
template<typename... Ts>
struct build {};
template<typename... Ts>
using build_t = typename build<Ts...>::type;
template<typename T>
struct build<T> {
    using type = cons<T, nil>;
};
template<typename T, typename ... Ts>
struct build<T, Ts...> {
    using type= cons<T, build_t<Ts...>>;
};
/**
 * min
 * returns the lowest element of the list
 */
template<typename XS>
struct min {
};
template<typename XS>
using min_t = typename min<XS>::type;
template<typename X>
struct min<cons<X, nil>> {
    using type = X;
};
template<typename X, typename XS>
struct min<cons<X, XS>> {
    using type = conditional_t<X() <= min_t<XS>(), X, min_t<XS>>;
};
/**
 * drop_min
 * returns the list without the lowest element
 */
template<typename XS>
struct drop_min {};
template<typename XS>
using drop_min_t = typename drop_min<XS>::type;
template<typename X>
struct drop_min<cons<X, nil>> {
    using type = nil;
};
template<typename X, typename XS>
struct drop_min<cons<X, XS>> {
    using type = conditional_t<
            X() <= min_t<XS>(),
            XS,
            cons<X, drop_min_t<XS>
            > >;
};
/**
 * sort
 * returns the list sorted
 */
template<typename XS>
struct sort;
template<typename T>
using sort_t = typename sort<T>::type;
template<typename XS>
struct sort {
    using type = cons<min_t<XS>, sort_t<drop_min_t<XS>>>;
};
template<>
struct sort<nil> {
    using type = nil;
};
#endif //PINS_LIST_HPP
#ifndef PINS_PIN_HPP
#define PINS_PIN_HPP
/**
 * pin
 */
template<char P, unsigned char L>
struct pio_pin;
#ifdef PORTA
template<unsigned char L>
struct pio_pin<'A', L> {
    FORCE_INLINE static void ddr_set() { DDRA |= L; }
    FORCE_INLINE static void ddr_clear() { DDRA &= ~L; }
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
    FORCE_INLINE static void ddr_set() { DDRB |= L; }
    FORCE_INLINE static void ddr_clear() { DDRB &= ~L; }
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
    FORCE_INLINE static void ddr_set() { DDRC |= L; }
    FORCE_INLINE static void ddr_clear() { DDRC &= ~L; }
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
    FORCE_INLINE static void ddr_set() { DDRD |= L; }
    FORCE_INLINE static void ddr_clear() { DDRD &= ~L; }
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
    FORCE_INLINE static void ddr_set() { DDRE |= L; }
    FORCE_INLINE static void ddr_clear() { DDRE &= ~L; }
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
    FORCE_INLINE static void ddr_set() { DDRF |= L; }
    FORCE_INLINE static void ddr_clear() { DDRF &= ~L; }
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
#ifndef PINS_PIN_LISTS_HPP
#define PINS_PIN_LISTS_HPP
/**
 * concat
 * pins of the same port (group) get combined (by logic or) resulting in a list with only one element for each used port
 */
template<typename T>
struct concat {};
template<typename T>
using concat_t = typename concat<T>::type;
template<>
struct concat<nil> {
    using type = nil;
};
template<typename T>
struct concat<cons<T, nil>> {
    using type = cons<T, nil>;
};
template<char P1, unsigned char L1, unsigned char L2, typename R>
struct concat<cons<pio_pin<P1, L1>, cons<pio_pin<P1, L2>, R>>> {
    using type = concat_t<cons<pio_pin<P1, L1 | L2>, R>>;
};
template<char P1, unsigned char L1, char P2, unsigned char L2, typename R>
struct concat<cons<pio_pin<P1, L1>, cons<pio_pin<P2, L2>, R>>> {
    using type = cons<pio_pin<P1, L1>, concat_t<cons<pio_pin<P2, L2>, R>>>;
};
#endif //PINS_PIN_LISTS_HPP
#ifndef PIO_LIBRARY_HPP
#define PIO_LIBRARY_HPP
template<typename ... PINS>
struct set_ddr {
    set_ddr() { concat_t<sort_t<build_t<PINS...>>>().ddr_set(); }
};
template<typename ... PINS>
struct clear_ddr {
    clear_ddr() { concat_t<sort_t<build_t<PINS...>>>().ddr_clear(); }
};
template<typename ... PINS>
struct set_port {
    set_port() { concat_t<sort_t<build_t<PINS...>>>().port_set(); }
};
template<typename ... PINS>
struct clear_port {
    clear_port() { concat_t<sort_t<build_t<PINS...>>>().port_clear(); }
};
#endif //PIO_LIBRARY_HPP
