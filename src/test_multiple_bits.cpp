#include <gtest/gtest.h>
#include <functional>
#include <iostream>
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

TEST(MultipleBitsDDR, SetSingleGroupDefaultIsZero) {
    testRegOp<void>(DDRA, 0, []() { set_ddr<A0, A2, A4, A6>(); }, 0b01010101);
    testRegOp<void>(DDRA, 0, []() { set_ddr<A0, A2, A4, A6>(); }, 0b01010101);
    testRegOp<void>(DDRB, 0, []() { set_ddr<B0, B2, B4, B6>(); }, 0b01010101);
    testRegOp<void>(DDRC, 0, []() { set_ddr<C0, C2, C4, C6>(); }, 0b01010101);
    testRegOp<void>(DDRD, 0, []() { set_ddr<D0, D2, D4, D6>(); }, 0b01010101);
}

TEST(MultipleBitsDDR, SetSingleGroupDefaultIsPattern) {
    testRegOp<void>(DDRA, 0b10101010, []() { set_ddr<A0, A2, A4, A6>(); }, 0xFF);
    testRegOp<void>(DDRB, 0b10101010, []() { set_ddr<B0, B2, B4, B6>(); }, 0xFF);
    testRegOp<void>(DDRC, 0b10101010, []() { set_ddr<C0, C2, C4, C6>(); }, 0xFF);
    testRegOp<void>(DDRD, 0b10101010, []() { set_ddr<D0, D2, D4, D6>(); }, 0xFF);
}

TEST(MultipleBitsDDR, ClearSingleGroupDefaultIsPattern) {
    testRegOp<void>(DDRA, 0b10101010, []() { clear_ddr<A1, A3, A5, A7>(); }, 0);
    testRegOp<void>(DDRB, 0b10101010, []() { clear_ddr<B1, B3, B5, B7>(); }, 0);
    testRegOp<void>(DDRC, 0b10101010, []() { clear_ddr<C1, C3, C5, C7>(); }, 0);
    testRegOp<void>(DDRD, 0b10101010, []() { clear_ddr<D1, D3, D5, D7>(); }, 0);
}

TEST(MultipleBitsDDR, ClearSingleGroupDefaultIsFilled) {
    testRegOp<void>(DDRA, 0xFF, []() { clear_ddr<A1, A3, A5, A7>(); }, 0b01010101);
    testRegOp<void>(DDRB, 0xFF, []() { clear_ddr<B1, B3, B5, B7>(); }, 0b01010101);
    testRegOp<void>(DDRC, 0xFF, []() { clear_ddr<C1, C3, C5, C7>(); }, 0b01010101);
    testRegOp<void>(DDRD, 0xFF, []() { clear_ddr<D1, D3, D5, D7>(); }, 0b01010101);
}

TEST(MultipleBitsDDR, SetMultipleGroupsDefaultIsZero) {
    testMultiRegOp<void>(
            DDRA, DDRB, DDRC, DDRD,
            0, 0, 0, 0,
            []() { set_ddr<A0, B0, C0, D0, A2, B2, C2, D2, A4, B4, C4, D4, A6, B6, C6, D6>(); },
            0b01010101, 0b01010101, 0b01010101, 0b01010101
    );
}

TEST(MultipleBitsDDR, SetMultipleGroupsDefaultIsPattern) {
    testMultiRegOp<void>(
            DDRA, DDRB, DDRC, DDRD,
            0b10101010, 0b10101010, 0b10101010, 0b10101010,
            []() { set_ddr<A0, B0, C0, D0, A2, B2, C2, D2, A4, B4, C4, D4, A6, B6, C6, D6>(); },
            0xFF, 0xFF, 0xFF, 0xFF
    );
}

TEST(MultipleBitsDDR, ClearMultipleGroupsDefaultIsPattern) {
    testMultiRegOp<void>(
            DDRA, DDRB, DDRC, DDRD,
            0b10101010, 0b10101010, 0b10101010, 0b10101010,
            []() { clear_ddr<A1, B1, C1, D1, A3, B3, C3, D3, A5, B5, C5, D5, A7, B7, C7, D7>(); },
            0, 0, 0, 0
    );
}

TEST(MultipleBitsDDR, ClearMultipleGroupsDefaultIsFilled) {
    testMultiRegOp<void>(
            DDRA, DDRB, DDRC, DDRD,
            0xFF, 0xFF, 0xFF, 0xFF,
            []() { clear_ddr<A1, B1, C1, D1, A3, B3, C3, D3, A5, B5, C5, D5, A7, B7, C7, D7>(); },
            0b01010101, 0b01010101, 0b01010101, 0b01010101
    );
}

TEST(MultipleBitsPORT, SetSingleGroupDefaultIsZero) {
    testRegOp<void>(PORTA, 0, []() { set_port<A0, A2, A4, A6>(); }, 0b01010101);
    testRegOp<void>(PORTB, 0, []() { set_port<B0, B2, B4, B6>(); }, 0b01010101);
    testRegOp<void>(PORTC, 0, []() { set_port<C0, C2, C4, C6>(); }, 0b01010101);
    testRegOp<void>(PORTD, 0, []() { set_port<D0, D2, D4, D6>(); }, 0b01010101);
}

TEST(MultipleBitsPORT, SetSingleGroupDefaultIsPattern) {
    testRegOp<void>(PORTA, 0b10101010, []() { set_port<A0, A2, A4, A6>(); }, 0xFF);
    testRegOp<void>(PORTB, 0b10101010, []() { set_port<B0, B2, B4, B6>(); }, 0xFF);
    testRegOp<void>(PORTC, 0b10101010, []() { set_port<C0, C2, C4, C6>(); }, 0xFF);
    testRegOp<void>(PORTD, 0b10101010, []() { set_port<D0, D2, D4, D6>(); }, 0xFF);
}

TEST(MultipleBitsPORT, ClearSingleGroupDefaultIsPattern) {
    testRegOp<void>(PORTA, 0b10101010, []() { clear_port<A1, A3, A5, A7>(); }, 0);
    testRegOp<void>(PORTB, 0b10101010, []() { clear_port<B1, B3, B5, B7>(); }, 0);
    testRegOp<void>(PORTC, 0b10101010, []() { clear_port<C1, C3, C5, C7>(); }, 0);
    testRegOp<void>(PORTD, 0b10101010, []() { clear_port<D1, D3, D5, D7>(); }, 0);
}

TEST(MultipleBitsPORT, ClearSingleGroupDefaultIsFilled) {
    testRegOp<void>(PORTA, 0xFF, []() { clear_port<A1, A3, A5, A7>(); }, 0b01010101);
    testRegOp<void>(PORTB, 0xFF, []() { clear_port<B1, B3, B5, B7>(); }, 0b01010101);
    testRegOp<void>(PORTC, 0xFF, []() { clear_port<C1, C3, C5, C7>(); }, 0b01010101);
    testRegOp<void>(PORTD, 0xFF, []() { clear_port<D1, D3, D5, D7>(); }, 0b01010101);
}

TEST(MultipleBitsPORT, SetMultipleGroupsDefaultIsZero) {
    testMultiRegOp<void>(
            PORTA, PORTB, PORTC, PORTD,
            0, 0, 0, 0,
            []() { set_port<A0, B0, C0, D0, A2, B2, C2, D2, A4, B4, C4, D4, A6, B6, C6, D6>(); },
            0b01010101, 0b01010101, 0b01010101, 0b01010101
    );
}

TEST(MultipleBitsPORT, SetMultipleGroupsDefaultIsPattern) {
    testMultiRegOp<void>(
            PORTA, PORTB, PORTC, PORTD,
            0b10101010, 0b10101010, 0b10101010, 0b10101010,
            []() { set_port<A0, B0, C0, D0, A2, B2, C2, D2, A4, B4, C4, D4, A6, B6, C6, D6>(); },
            0xFF, 0xFF, 0xFF, 0xFF
    );
}

TEST(MultipleBitsPORT, ClearMultipleGroupsDefaultIsPattern) {
    testMultiRegOp<void>(
            PORTA, PORTB, PORTC, PORTD,
            0b10101010, 0b10101010, 0b10101010, 0b10101010,
            []() { clear_port<A1, B1, C1, D1, A3, B3, C3, D3, A5, B5, C5, D5, A7, B7, C7, D7>(); },
            0, 0, 0, 0
    );
}

TEST(MultipleBitsPORT, ClearMultipleGroupsDefaultIsFilled) {
    testMultiRegOp<void>(
            PORTA, PORTB, PORTC, PORTD,
            0xFF, 0xFF, 0xFF, 0xFF,
            []() { clear_port<A1, B1, C1, D1, A3, B3, C3, D3, A5, B5, C5, D5, A7, B7, C7, D7>(); },
            0b01010101, 0b01010101, 0b01010101, 0b01010101
    );
}

template<typename R, typename T, typename V>
void testRegOp(T &reg, V init_val, std::function<R()> operation, V expected_val) {
    reg = init_val;
    operation();
    ASSERT_EQ(reg, expected_val);
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
    ASSERT_EQ(reg0, expected_val0);
    ASSERT_EQ(reg1, expected_val1);
    ASSERT_EQ(reg2, expected_val2);
    ASSERT_EQ(reg3, expected_val3);
}
