#include <gtest/gtest.h>
#include "pio.hpp"

template<typename T, typename... N>
auto make_array(N&& ... args) -> std::array<T, sizeof...(args)>
{
	return { std::forward<N>(args)... };
}

auto DDR = make_array<decltype(DDRA)*>(&DDRA, &DDRB, &DDRC, &DDRD, &DDRE, &DDRF);

auto PORT = make_array<decltype(PORTA)*>(&PORTA, &PORTB, &PORTC, &PORTD, &PORTE, &PORTF);

auto PIN = make_array<decltype(PINA)*>(&PINA, &PINB, &PINC, &PIND, &PINE, &PINF);

auto REG = make_array<decltype(DDR)*>(&DDR, &PORT, &PIN);

template<typename F>
void mapRegister(F func)
{
	for (auto* group : REG)
	{
		for (auto* reg : *group)
		{
			func(reg);
		}
	}
}

template<typename T>
struct yo
{
	yo()
	{
		std::cout << "yo" << std::endl;
	}
};

template<typename ... Ts>
struct loop_pins
{
};

template<typename ... Ts>
using loop_pins_t = typename loop_pins<Ts...>::type;

template<typename T>
struct loop_pins<T>
{
	using type = yo<T>;
	loop_pins()
	{
		std::cout << "loop pins2" << std::endl;
	}
};

template<typename T, typename ... Ts>
struct loop_pins<T, Ts ...>
{
	using type = loop_pins_t<Ts...>;
	loop_pins()
	{
		std::cout << "loop pins" << std::endl;
		loop_pins<Ts...>();
	}
};

TEST(SingleBit, Port)
{
	loop_pins<A0, A1, A2, A3, A4, A5, A6, A7>();
}