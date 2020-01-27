/**
 * Simple testfile to ensure the magic still works.
 */

#include <functional>
#include <iostream>
#include <cassert>
#include "pin_lists.hpp"

using std::cout;
using std::endl;

template<typename R, typename T, typename V>
void testRegOp(T& reg, V init_val, std::function<R()> operation, V expected_val);

template<typename R, typename T, typename V>
void testMultiRegOp(
	T& reg0,
	T& reg1,
	T& reg2,
	T& reg3,
	V init_val0,
	V init_val1,
	V init_val2,
	V init_val3,
	std::function<R()> operation,
	V expected_val0,
	V expected_val1,
	V expected_val2,
	V expected_val3);

int main()
{
	cout << "Starting tests..." << endl;

	// PORT, set, single group, default zero
	testRegOp<void>(PORTA, 0, concat_pins_t<sort_t<build_t<A0, A2, A4, A6>>>().high, 0b01010101);
	testRegOp<void>(PORTB, 0, concat_pins_t<sort_t<build_t<B0, B2, B4, B6>>>().high, 0b01010101);
	testRegOp<void>(PORTC, 0, concat_pins_t<sort_t<build_t<C0, C2, C4, C6>>>().high, 0b01010101);
	testRegOp<void>(PORTD, 0, concat_pins_t<sort_t<build_t<D0, D2, D4, D6>>>().high, 0b01010101);

	// PORT, set, single group, default has pattern
	testRegOp<void>(PORTA, 0b10101010, concat_pins_t<sort_t<build_t<A0, A2, A4, A6>>>().high, 0xFF);
	testRegOp<void>(PORTB, 0b10101010, concat_pins_t<sort_t<build_t<B0, B2, B4, B6>>>().high, 0xFF);
	testRegOp<void>(PORTC, 0b10101010, concat_pins_t<sort_t<build_t<C0, C2, C4, C6>>>().high, 0xFF);
	testRegOp<void>(PORTD, 0b10101010, concat_pins_t<sort_t<build_t<D0, D2, D4, D6>>>().high, 0xFF);

	// PORT, clear, single group, default has pattern
	testRegOp<void>(PORTA, 0b10101010, concat_pins_t<sort_t<build_t<A1, A3, A5, A7>>>().low, 0);
	testRegOp<void>(PORTB, 0b10101010, concat_pins_t<sort_t<build_t<B1, B3, B5, B7>>>().low, 0);
	testRegOp<void>(PORTC, 0b10101010, concat_pins_t<sort_t<build_t<C1, C3, C5, C7>>>().low, 0);
	testRegOp<void>(PORTD, 0b10101010, concat_pins_t<sort_t<build_t<D1, D3, D5, D7>>>().low, 0);

	// PORT, clear, single group, default ist filled
	testRegOp<void>(PORTA, 0xFF, concat_pins_t<sort_t<build_t<A1, A3, A5, A7>>>().low, 0b01010101);
	testRegOp<void>(PORTB, 0xFF, concat_pins_t<sort_t<build_t<B1, B3, B5, B7>>>().low, 0b01010101);
	testRegOp<void>(PORTC, 0xFF, concat_pins_t<sort_t<build_t<C1, C3, C5, C7>>>().low, 0b01010101);
	testRegOp<void>(PORTD, 0xFF, concat_pins_t<sort_t<build_t<D1, D3, D5, D7>>>().low, 0b01010101);



	// PORT, set, multiple groups, default zero
	testMultiRegOp<void>(
		PORTA, PORTB, PORTC, PORTD,
		0, 0, 0, 0,
		concat_pins_t<sort_t<build_t<A0, B0, C0, D0, A2, B2, C2, D2, A4, B4, C4, D4, A6, B6, C6, D6>>>().high,
		0b01010101, 0b01010101, 0b01010101, 0b01010101);

	// PORT, set, multiple groups, default has pattern
	testMultiRegOp<void>(
		PORTA, PORTB, PORTC, PORTD,
		0b10101010, 0b10101010, 0b10101010, 0b10101010,
		concat_pins_t<sort_t<build_t<A0, B0, C0, D0, A2, B2, C2, D2, A4, B4, C4, D4, A6, B6, C6, D6>>>().high,
		0xFF, 0xFF, 0xFF, 0xFF);

	// PORT, clear, multiple groups, default has pattern
	testMultiRegOp<void>(
		PORTA, PORTB, PORTC, PORTD,
		0b10101010, 0b10101010, 0b10101010, 0b10101010,
		concat_pins_t<sort_t<build_t<A1, B1, C1, D1, A3, B3, C3, D3, A5, B5, C5, D5, A7, B7, C7, D7>>>().low,
		0, 0, 0, 0);

	// PORT, clear, multiple groups, default is filled
	testMultiRegOp<void>(
		PORTA, PORTB, PORTC, PORTD,
		0xFF, 0xFF, 0xFF, 0xFF,
		concat_pins_t<sort_t<build_t<A1, B1, C1, D1, A3, B3, C3, D3, A5, B5, C5, D5, A7, B7, C7, D7>>>().low,
		0b01010101, 0b01010101, 0b01010101, 0b01010101);

	cout << "All tests finished successful." << endl;
}

template<typename R, typename T, typename V>
void testRegOp(T& reg, V init_val, std::function<R()> operation, V expected_val)
{
	reg = init_val;
	operation();
	assert(reg == expected_val);
}

template<typename R, typename T, typename V>
void testMultiRegOp(
	T& reg0,
	T& reg1,
	T& reg2,
	T& reg3,
	V init_val0,
	V init_val1,
	V init_val2,
	V init_val3,
	std::function<R()> operation,
	V expected_val0,
	V expected_val1,
	V expected_val2,
	V expected_val3)
{
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