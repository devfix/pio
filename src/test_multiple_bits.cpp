#include <gtest/gtest.h>
#include <functional>
#include <iostream>
#include "include/library.h"

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
    testRegOp<void>(DDRA, 0, []() { set_ddr<LA0, LA2, LA4, LA6>(); }, 0b01010101);
    testRegOp<void>(DDRA, 0, []() { set_ddr<LA0, LA2, LA4, LA6>(); }, 0b01010101);
    testRegOp<void>(DDRB, 0, []() { set_ddr<LB0, LB2, LB4, LB6>(); }, 0b01010101);
    testRegOp<void>(DDRC, 0, []() { set_ddr<LC0, LC2, LC4, LC6>(); }, 0b01010101);
    testRegOp<void>(DDRD, 0, []() { set_ddr<LD0, LD2, LD4, LD6>(); }, 0b01010101);
}

TEST(MultipleBitsDDR, SetSingleGroupDefaultIsPattern) {
    testRegOp<void>(DDRA, 0b10101010, []() { set_ddr<LA0, LA2, LA4, LA6>(); }, 0xFF);
    testRegOp<void>(DDRB, 0b10101010, []() { set_ddr<LB0, LB2, LB4, LB6>(); }, 0xFF);
    testRegOp<void>(DDRC, 0b10101010, []() { set_ddr<LC0, LC2, LC4, LC6>(); }, 0xFF);
    testRegOp<void>(DDRD, 0b10101010, []() { set_ddr<LD0, LD2, LD4, LD6>(); }, 0xFF);
}

TEST(MultipleBitsDDR, ClearSingleGroupDefaultIsPattern) {
    testRegOp<void>(DDRA, 0b10101010, []() { clear_ddr<LA1, LA3, LA5, LA7>(); }, 0);
    testRegOp<void>(DDRB, 0b10101010, []() { clear_ddr<LB1, LB3, LB5, LB7>(); }, 0);
    testRegOp<void>(DDRC, 0b10101010, []() { clear_ddr<LC1, LC3, LC5, LC7>(); }, 0);
    testRegOp<void>(DDRD, 0b10101010, []() { clear_ddr<LD1, LD3, LD5, LD7>(); }, 0);
}

TEST(MultipleBitsDDR, ClearSingleGroupDefaultIsFilled) {
    testRegOp<void>(DDRA, 0xFF, []() { clear_ddr<LA1, LA3, LA5, LA7>(); }, 0b01010101);
    testRegOp<void>(DDRB, 0xFF, []() { clear_ddr<LB1, LB3, LB5, LB7>(); }, 0b01010101);
    testRegOp<void>(DDRC, 0xFF, []() { clear_ddr<LC1, LC3, LC5, LC7>(); }, 0b01010101);
    testRegOp<void>(DDRD, 0xFF, []() { clear_ddr<LD1, LD3, LD5, LD7>(); }, 0b01010101);
}

TEST(MultipleBitsDDR, SetMultipleGroupsDefaultIsZero) {
    testMultiRegOp<void>(
            DDRA, DDRB, DDRC, DDRD,
            0, 0, 0, 0,
            []() { set_ddr<LA0, LB0, LC0, LD0, LA2, LB2, LC2, LD2, LA4, LB4, LC4, LD4, LA6, LB6, LC6, LD6>(); },
            0b01010101, 0b01010101, 0b01010101, 0b01010101
    );
}

TEST(MultipleBitsDDR, SetMultipleGroupsDefaultIsPattern) {
    testMultiRegOp<void>(
            DDRA, DDRB, DDRC, DDRD,
            0b10101010, 0b10101010, 0b10101010, 0b10101010,
            []() { set_ddr<LA0, LB0, LC0, LD0, LA2, LB2, LC2, LD2, LA4, LB4, LC4, LD4, LA6, LB6, LC6, LD6>(); },
            0xFF, 0xFF, 0xFF, 0xFF
    );
}

TEST(MultipleBitsDDR, ClearMultipleGroupsDefaultIsPattern) {
    testMultiRegOp<void>(
            DDRA, DDRB, DDRC, DDRD,
            0b10101010, 0b10101010, 0b10101010, 0b10101010,
            []() { clear_ddr<LA1, LB1, LC1, LD1, LA3, LB3, LC3, LD3, LA5, LB5, LC5, LD5, LA7, LB7, LC7, LD7>(); },
            0, 0, 0, 0
    );
}

TEST(MultipleBitsDDR, ClearMultipleGroupsDefaultIsFilled) {
    testMultiRegOp<void>(
            DDRA, DDRB, DDRC, DDRD,
            0xFF, 0xFF, 0xFF, 0xFF,
            []() { clear_ddr<LA1, LB1, LC1, LD1, LA3, LB3, LC3, LD3, LA5, LB5, LC5, LD5, LA7, LB7, LC7, LD7>(); },
            0b01010101, 0b01010101, 0b01010101, 0b01010101
    );
}

TEST(MultipleBitsPORT, SetSingleGroupDefaultIsZero) {
    testRegOp<void>(PORTA, 0, []() { set_port<LA0, LA2, LA4, LA6>(); }, 0b01010101);
    testRegOp<void>(PORTB, 0, []() { set_port<LB0, LB2, LB4, LB6>(); }, 0b01010101);
    testRegOp<void>(PORTC, 0, []() { set_port<LC0, LC2, LC4, LC6>(); }, 0b01010101);
    testRegOp<void>(PORTD, 0, []() { set_port<LD0, LD2, LD4, LD6>(); }, 0b01010101);
}

TEST(MultipleBitsPORT, SetSingleGroupDefaultIsPattern) {
    testRegOp<void>(PORTA, 0b10101010, []() { set_port<LA0, LA2, LA4, LA6>(); }, 0xFF);
    testRegOp<void>(PORTB, 0b10101010, []() { set_port<LB0, LB2, LB4, LB6>(); }, 0xFF);
    testRegOp<void>(PORTC, 0b10101010, []() { set_port<LC0, LC2, LC4, LC6>(); }, 0xFF);
    testRegOp<void>(PORTD, 0b10101010, []() { set_port<LD0, LD2, LD4, LD6>(); }, 0xFF);
}

TEST(MultipleBitsPORT, ClearSingleGroupDefaultIsPattern) {
    testRegOp<void>(PORTA, 0b10101010, []() { clear_port<LA1, LA3, LA5, LA7>(); }, 0);
    testRegOp<void>(PORTB, 0b10101010, []() { clear_port<LB1, LB3, LB5, LB7>(); }, 0);
    testRegOp<void>(PORTC, 0b10101010, []() { clear_port<LC1, LC3, LC5, LC7>(); }, 0);
    testRegOp<void>(PORTD, 0b10101010, []() { clear_port<LD1, LD3, LD5, LD7>(); }, 0);
}

TEST(MultipleBitsPORT, ClearSingleGroupDefaultIsFilled) {
    testRegOp<void>(PORTA, 0xFF, []() { clear_port<LA1, LA3, LA5, LA7>(); }, 0b01010101);
    testRegOp<void>(PORTB, 0xFF, []() { clear_port<LB1, LB3, LB5, LB7>(); }, 0b01010101);
    testRegOp<void>(PORTC, 0xFF, []() { clear_port<LC1, LC3, LC5, LC7>(); }, 0b01010101);
    testRegOp<void>(PORTD, 0xFF, []() { clear_port<LD1, LD3, LD5, LD7>(); }, 0b01010101);
}

TEST(MultipleBitsPORT, SetMultipleGroupsDefaultIsZero) {
    testMultiRegOp<void>(
            PORTA, PORTB, PORTC, PORTD,
            0, 0, 0, 0,
            []() { set_port<LA0, LB0, LC0, LD0, LA2, LB2, LC2, LD2, LA4, LB4, LC4, LD4, LA6, LB6, LC6, LD6>(); },
            0b01010101, 0b01010101, 0b01010101, 0b01010101
    );
}

TEST(MultipleBitsPORT, SetMultipleGroupsDefaultIsPattern) {
    testMultiRegOp<void>(
            PORTA, PORTB, PORTC, PORTD,
            0b10101010, 0b10101010, 0b10101010, 0b10101010,
            []() { set_port<LA0, LB0, LC0, LD0, LA2, LB2, LC2, LD2, LA4, LB4, LC4, LD4, LA6, LB6, LC6, LD6>(); },
            0xFF, 0xFF, 0xFF, 0xFF
    );
}

TEST(MultipleBitsPORT, ClearMultipleGroupsDefaultIsPattern) {
    testMultiRegOp<void>(
            PORTA, PORTB, PORTC, PORTD,
            0b10101010, 0b10101010, 0b10101010, 0b10101010,
            []() { clear_port<LA1, LB1, LC1, LD1, LA3, LB3, LC3, LD3, LA5, LB5, LC5, LD5, LA7, LB7, LC7, LD7>(); },
            0, 0, 0, 0
    );
}

TEST(MultipleBitsPORT, ClearMultipleGroupsDefaultIsFilled) {
    testMultiRegOp<void>(
            PORTA, PORTB, PORTC, PORTD,
            0xFF, 0xFF, 0xFF, 0xFF,
            []() { clear_port<LA1, LB1, LC1, LD1, LA3, LB3, LC3, LD3, LA5, LB5, LC5, LD5, LA7, LB7, LC7, LD7>(); },
            0b01010101, 0b01010101, 0b01010101, 0b01010101
    );
    using LED = LA0;
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
