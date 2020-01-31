#include <gtest/gtest.h>
#include "pio.hpp"
#include "map.hpp"

template<typename T, template<typename ...> typename F, typename R>
struct GenericRegisterTest
{
	explicit  GenericRegisterTest(R& reg, R init, R expected)
	{
		reg = init;
		F<T>();
		EXPECT_EQ(reg, expected);
	}
};

template<typename T>
void genericGroupTest(decltype(DDRA)& ddr, decltype(PORTA)& port, decltype(PINA)& pin)
{
	GenericRegisterTest<T, set_ddr_t, decltype(DDRA)>(ddr, 0, T::LEAD);
	GenericRegisterTest<T, set_ddr_t, decltype(DDRA)>(ddr, static_cast<decltype(DDRA)>(~T::LEAD), 0xFF);
	GenericRegisterTest<T, set_ddr_t, decltype(DDRA)>(ddr, static_cast<decltype(DDRA)>(T::LEAD>>1), static_cast<decltype(DDRA)>(T::LEAD | (T::LEAD>>1)));
	GenericRegisterTest<T, set_ddr_t, decltype(DDRA)>(ddr, static_cast<decltype(DDRA)>(T::LEAD<<1), static_cast<decltype(DDRA)>(T::LEAD | (T::LEAD<<1)));
	GenericRegisterTest<T, set_port_t, decltype(PORTA)>(port, 0, T::LEAD);
	GenericRegisterTest<T, set_port_t, decltype(PORTA)>(port, static_cast<decltype(PORTA)>(~T::LEAD), 0xFF);
	GenericRegisterTest<T, set_port_t, decltype(PORTA)>(port, static_cast<decltype(PORTA)>(T::LEAD>>1), static_cast<decltype(DDRA)>(T::LEAD | (T::LEAD>>1)));
	GenericRegisterTest<T, set_port_t, decltype(PORTA)>(port, static_cast<decltype(PORTA)>(T::LEAD<<1), static_cast<decltype(DDRA)>(T::LEAD | (T::LEAD<<1)));
};

template<typename T>
struct TestGroupA
{
	TestGroupA()
	{ genericGroupTest<T>(DDRA, PORTA, PINA); }
};

template<typename T>
struct TestGroupB
{
	TestGroupB()
	{ genericGroupTest<T>(DDRB, PORTB, PINB); }
};

template<typename T>
struct TestGroupC
{
	TestGroupC()
	{ genericGroupTest<T>(DDRC, PORTC, PINC); }
};

template<typename T>
struct TestGroupD
{
	TestGroupD()
	{ genericGroupTest<T>(DDRD, PORTD, PIND); }
};

template<typename T>
struct TestGroupE
{
	TestGroupE()
	{ genericGroupTest<T>(DDRE, PORTE, PINE); }
};

template<typename T>
struct TestGroupF
{
	TestGroupF()
	{ genericGroupTest<T>(DDRF, PORTF, PINF); }
};


TEST(SingleBit, GroupA)
{
	map<TestGroupA, A0, A1, A2, A3, A4, A5, A6, A7>();
}

TEST(SingleBit, GroupB)
{
	map<TestGroupB, B0, B1, B2, B3, B4, B5, B6, B7>();
}

TEST(SingleBit, GroupC)
{
	map<TestGroupB, B0, B1, B2, B3, B4, B5, B6, B7>();
}

TEST(SingleBit, GroupD)
{
	map<TestGroupD, D0, D1, D2, D3, D4, D5, D6, D7>();
}

TEST(SingleBit, GroupE)
{
	map<TestGroupE, E0, E1, E2, E3, E4, E5, E6, E7>();
}

TEST(SingleBit, GroupF)
{
	map<TestGroupF, F0, F1, F2, F3, F4, F5, F6, F7>();
}
