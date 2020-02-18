/*
 *     _______  _____   ___
 *    |_   __ \|_   _|.'   `.
 *      | |__) | | | /  .-.  \
 *      |  ___/  | | | |   | |
 *     _| |_    _| |_\  `-'  /
 *    |_____|  |_____|`.___.'
 *
 *      Avr Pin I/O Library
 *
 *    ~ version 3.0.1
 *    ~ written by Jonas Höfer, Tristan Krause
 *    ~ visit github.com/devfix/pio
 *
 *    You should have received a copy of the MIT License.
 *    If not, see <https://opensource.org/licenses/MIT>.
 *
 */
#ifndef PIO_CONDITIONAL_HPP
#define PIO_CONDITIONAL_HPP
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
#endif // PIO_CONDITIONAL_HPP
#ifndef PIO_MEM_HPP
#define PIO_MEM_HPP
#ifdef __AVR__
#define FORCE_INLINE __attribute__((always_inline)) inline
#else
#define FORCE_INLINE inline
#endif
#endif // PIO_MEM_HPP
#ifndef PIO_IO_HPP
#define PIO_IO_HPP
using DDR_T = volatile unsigned char;
using PORT_T = volatile unsigned char;
using PIN_T = volatile unsigned char;
#ifdef __AVR__
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
#ifndef PIO_LINKEDLIST_HPP
#define PIO_LINKEDLIST_HPP
#ifndef __AVR__
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
    FORCE_INLINE static void port_toggle() {}
    static constexpr PIN_T pin_get() { return 0; }
#ifndef __AVR__
    friend std::ostream &operator<<(std::ostream &os, const nil &) {
        return os;
    }
#endif
};
template<typename X, typename XS>
struct cons {
    FORCE_INLINE static void ddr_set() {
        *X::DDR |= X::LEAD;
        XS().ddr_set();
    }
    FORCE_INLINE static void ddr_clear() {
        *X::DDR &= ~X::LEAD;
        XS().ddr_clear();
    }
    FORCE_INLINE static void port_set() {
        *X::PORT |= X::LEAD;
        XS().port_set();
    }
    FORCE_INLINE static void port_clear() {
        *X::PORT &= ~X::LEAD;
        XS().port_clear();
    }
    FORCE_INLINE static void port_toggle() {
        *X::PORT ^= X::LEAD;
        XS().port_toggle();
    }
    static constexpr PIN_T pin_get() {
        return static_cast<PIN_T>((*X::PIN & X::LEAD) | XS().pin_get());
    }
#ifndef __AVR__
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
#endif // PIO_LINKEDLIST_HPP
#ifndef PIO_PIN_HPP
#define PIO_PIN_HPP
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
#ifndef __AVR__
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
#ifndef __AVR__
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
#ifndef __AVR__
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
#ifndef __AVR__
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
#ifndef __AVR__
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
#ifndef __AVR__
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
#ifndef PIO_CONCAT_HPP
#define PIO_CONCAT_HPP
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
#endif // PIO_CONCAT_HPP
#ifndef PIO_LIBRARY_HPP
#define PIO_LIBRARY_HPP
template<typename ... PINS>
void set_ddr()
{
	concat_t<sort_t<build_t<PINS...>>>().ddr_set();
}
template<typename ... PINS>
struct set_ddr_t
{
	set_ddr_t()
	{
		set_ddr<PINS...>();
	}
};
template<typename ... PINS>
void clear_ddr()
{
	concat_t<sort_t<build_t<PINS...>>>().ddr_clear();
};
template<typename ... PINS>
struct clear_ddr_t
{
	clear_ddr_t()
	{
		clear_ddr<PINS...>();
	}
};
template<typename ... PINS>
void set_port()
{
	concat_t<sort_t<build_t<PINS...>>>().port_set();
};
template<typename ... PINS>
struct set_port_t
{
	set_port_t()
	{
		set_port<PINS...>();
	}
};
template<typename ... PINS>
void clear_port()
{
	concat_t<sort_t<build_t<PINS...>>>().port_clear();
};
template<typename ... PINS>
struct clear_port_t
{
	clear_port_t()
	{
		clear_port<PINS...>();
	}
};
template<typename ... PINS>
void toggle_port()
{
    concat_t<sort_t<build_t<PINS...>>>().port_toggle();
};
template<typename ... PINS>
struct toggle_port_t
{
    toggle_port_t()
    {
        toggle_port<PINS...>();
    }
};
template<typename PIN, typename ... PINS>
constexpr PIN_T get_pin()
{
    return concat_t<sort_t<build_t<PIN, PINS...>>>().pin_get();
};
#endif // PIO_LIBRARY_HPP
