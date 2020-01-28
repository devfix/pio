/**
 * Simple testfile to ensure the magic still works.
 */


#ifdef AVR

#include "pio.hpp"

/**
 * Just a simple test that avr-gcc can handle the template stuff.
 */

int main()
{
    set_ddr<A1, A3, A5, A7>();
    clear_ddr<A0, A2, A4, A6>();
    set_port<A1, A3, A5, A7>();
    clear_port<A0, A3, A4, A6>();
}


#else

#include <functional>
#include <iostream>
#include <cassert>
#include "pio.hpp"

using std::cout;
using std::endl;

template<typename R, typename T, typename V>
void testRegOp(T &reg, V init_val, std::function<R()> operation, V expected_val);

template<typename R, typename T, typename V>
void testMultiRegOp(
        T &reg0,
        T &reg1,
        T &reg2,
        T &reg3,
        V init_val0,
        V init_val1,
        V init_val2,
        V init_val3,
        std::function<R()> operation,
        V expected_val0,
        V expected_val1,
        V expected_val2,
        V expected_val3);

int main() {
    cout << "Starting tests..." << endl;

    cout << "Test: DDR, set, single group, default zero" << endl;
    testRegOp<void>(DDRA, 0, []() { set_ddr<A0, A2, A4, A6>(); }, 0b01010101);
    testRegOp<void>(DDRA, 0, []() { set_ddr<A0, A2, A4, A6>(); }, 0b01010101);
    testRegOp<void>(DDRB, 0, []() { set_ddr<B0, B2, B4, B6>(); }, 0b01010101);
    testRegOp<void>(DDRC, 0, []() { set_ddr<C0, C2, C4, C6>(); }, 0b01010101);
    testRegOp<void>(DDRD, 0, []() { set_ddr<D0, D2, D4, D6>(); }, 0b01010101);

    cout << "Test: DDR, set, single group, default has pattern" << endl;
    testRegOp<void>(DDRA, 0b10101010, []() { set_ddr<A0, A2, A4, A6>(); }, 0xFF);
    testRegOp<void>(DDRB, 0b10101010, []() { set_ddr<B0, B2, B4, B6>(); }, 0xFF);
    testRegOp<void>(DDRC, 0b10101010, []() { set_ddr<C0, C2, C4, C6>(); }, 0xFF);
    testRegOp<void>(DDRD, 0b10101010, []() { set_ddr<D0, D2, D4, D6>(); }, 0xFF);

    cout << "Test: DDR, clear, single group, default has pattern" << endl;
    testRegOp<void>(DDRA, 0b10101010, []() { clear_ddr<A1, A3, A5, A7>(); }, 0);
    testRegOp<void>(DDRB, 0b10101010, []() { clear_ddr<B1, B3, B5, B7>(); }, 0);
    testRegOp<void>(DDRC, 0b10101010, []() { clear_ddr<C1, C3, C5, C7>(); }, 0);
    testRegOp<void>(DDRD, 0b10101010, []() { clear_ddr<D1, D3, D5, D7>(); }, 0);

    cout << "Test: DDR, clear, single group, default ist filled" << endl;
    testRegOp<void>(DDRA, 0xFF, []() { clear_ddr<A1, A3, A5, A7>(); }, 0b01010101);
    testRegOp<void>(DDRB, 0xFF, []() { clear_ddr<B1, B3, B5, B7>(); }, 0b01010101);
    testRegOp<void>(DDRC, 0xFF, []() { clear_ddr<C1, C3, C5, C7>(); }, 0b01010101);
    testRegOp<void>(DDRD, 0xFF, []() { clear_ddr<D1, D3, D5, D7>(); }, 0b01010101);


    cout << "Test: DDR, set, multiple groups, default zero" << endl;
    testMultiRegOp<void>(
            DDRA, DDRB, DDRC, DDRD,
            0, 0, 0, 0,
            []() { set_ddr<A0, B0, C0, D0, A2, B2, C2, D2, A4, B4, C4, D4, A6, B6, C6, D6>(); },
            0b01010101, 0b01010101, 0b01010101, 0b01010101);

    cout << "Test: DDR, set, multiple groups, default has pattern" << endl;
    testMultiRegOp<void>(
            DDRA, DDRB, DDRC, DDRD,
            0b10101010, 0b10101010, 0b10101010, 0b10101010,
            []() { set_ddr<A0, B0, C0, D0, A2, B2, C2, D2, A4, B4, C4, D4, A6, B6, C6, D6>(); },
            0xFF, 0xFF, 0xFF, 0xFF);

    cout << "Test: DDR, clear, multiple groups, default has pattern" << endl;
    testMultiRegOp<void>(
            DDRA, DDRB, DDRC, DDRD,
            0b10101010, 0b10101010, 0b10101010, 0b10101010,
            []() { clear_ddr<A1, B1, C1, D1, A3, B3, C3, D3, A5, B5, C5, D5, A7, B7, C7, D7>(); },
            0, 0, 0, 0);

    cout << "Test: DDR, clear, multiple groups, default is filled" << endl;
    testMultiRegOp<void>(
            DDRA, DDRB, DDRC, DDRD,
            0xFF, 0xFF, 0xFF, 0xFF,
            []() { clear_ddr<A1, B1, C1, D1, A3, B3, C3, D3, A5, B5, C5, D5, A7, B7, C7, D7>(); },
            0b01010101, 0b01010101, 0b01010101, 0b01010101);


    cout << "Test: PORT, set, single group, default zero" << endl;
    testRegOp<void>(PORTA, 0, []() { set_port<A0, A2, A4, A6>(); }, 0b01010101);
    testRegOp<void>(PORTB, 0, []() { set_port<B0, B2, B4, B6>(); }, 0b01010101);
    testRegOp<void>(PORTC, 0, []() { set_port<C0, C2, C4, C6>(); }, 0b01010101);
    testRegOp<void>(PORTD, 0, []() { set_port<D0, D2, D4, D6>(); }, 0b01010101);

    cout << "Test: PORT, set, single group, default has pattern" << endl;
    testRegOp<void>(PORTA, 0b10101010, []() { set_port<A0, A2, A4, A6>(); }, 0xFF);
    testRegOp<void>(PORTB, 0b10101010, []() { set_port<B0, B2, B4, B6>(); }, 0xFF);
    testRegOp<void>(PORTC, 0b10101010, []() { set_port<C0, C2, C4, C6>(); }, 0xFF);
    testRegOp<void>(PORTD, 0b10101010, []() { set_port<D0, D2, D4, D6>(); }, 0xFF);

    cout << "Test: PORT, clear, single group, default has pattern" << endl;
    testRegOp<void>(PORTA, 0b10101010, []() { clear_port<A1, A3, A5, A7>(); }, 0);
    testRegOp<void>(PORTB, 0b10101010, []() { clear_port<B1, B3, B5, B7>(); }, 0);
    testRegOp<void>(PORTC, 0b10101010, []() { clear_port<C1, C3, C5, C7>(); }, 0);
    testRegOp<void>(PORTD, 0b10101010, []() { clear_port<D1, D3, D5, D7>(); }, 0);

    cout << "Test: PORT, clear, single group, default ist filled" << endl;
    testRegOp<void>(PORTA, 0xFF, []() { clear_port<A1, A3, A5, A7>(); }, 0b01010101);
    testRegOp<void>(PORTB, 0xFF, []() { clear_port<B1, B3, B5, B7>(); }, 0b01010101);
    testRegOp<void>(PORTC, 0xFF, []() { clear_port<C1, C3, C5, C7>(); }, 0b01010101);
    testRegOp<void>(PORTD, 0xFF, []() { clear_port<D1, D3, D5, D7>(); }, 0b01010101);


    cout << "Test: PORT, set, multiple groups, default zero" << endl;
    testMultiRegOp<void>(
            PORTA, PORTB, PORTC, PORTD,
            0, 0, 0, 0,
            []() { set_port<A0, B0, C0, D0, A2, B2, C2, D2, A4, B4, C4, D4, A6, B6, C6, D6>(); },
            0b01010101, 0b01010101, 0b01010101, 0b01010101);

    cout << "Test: PORT, set, multiple groups, default has pattern" << endl;
    testMultiRegOp<void>(
            PORTA, PORTB, PORTC, PORTD,
            0b10101010, 0b10101010, 0b10101010, 0b10101010,
            []() { set_port<A0, B0, C0, D0, A2, B2, C2, D2, A4, B4, C4, D4, A6, B6, C6, D6>(); },
            0xFF, 0xFF, 0xFF, 0xFF);

    cout << "Test: PORT, clear, multiple groups, default has pattern" << endl;
    testMultiRegOp<void>(
            PORTA, PORTB, PORTC, PORTD,
            0b10101010, 0b10101010, 0b10101010, 0b10101010,
            []() { clear_port<A1, B1, C1, D1, A3, B3, C3, D3, A5, B5, C5, D5, A7, B7, C7, D7>(); },
            0, 0, 0, 0);

    cout << "Test: PORT, clear, multiple groups, default is filled" << endl;
    testMultiRegOp<void>(
            PORTA, PORTB, PORTC, PORTD,
            0xFF, 0xFF, 0xFF, 0xFF,
            []() { clear_port<A1, B1, C1, D1, A3, B3, C3, D3, A5, B5, C5, D5, A7, B7, C7, D7>(); },
            0b01010101, 0b01010101, 0b01010101, 0b01010101);

    cout << "All tests finished successful." << endl;
}

template<typename R, typename T, typename V>
void testRegOp(T &reg, V init_val, std::function<R()> operation, V expected_val) {
    reg = init_val;
    operation();
    assert(reg == expected_val);
}

template<typename R, typename T, typename V>
void testMultiRegOp(
        T &reg0,
        T &reg1,
        T &reg2,
        T &reg3,
        V init_val0,
        V init_val1,
        V init_val2,
        V init_val3,
        std::function<R()> operation,
        V expected_val0,
        V expected_val1,
        V expected_val2,
        V expected_val3) {
    reg0 = init_val0;
    reg1 = init_val1;
    reg2 = init_val2;
    reg3 = init_val3;
    operation();
    assert(reg0 == expected_val0);
    assert(reg1 == expected_val1);
    assert(reg2 == expected_val2);
    assert(reg3 == expected_val3);
}

#endif
