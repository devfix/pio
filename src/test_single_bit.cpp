#include <gtest/gtest.h>
#include <type_traits>
#include "include/library.h"
#include "map.h"

template<typename T, template<typename ...> typename F, typename R>
struct GenericRegisterTest
{
	explicit GenericRegisterTest(R& reg, R init, R expected)
	{
		reg = init;
		F<T>();
        EXPECT_EQ(reg, expected); // ASSERT_EQ doesn't work here
	}
};

template<typename T>
void genericGroupTest(DDR_T& ddr, PORT_T& port, PIN_T& pin)
{
	GenericRegisterTest<T, set_ddr_t, DDR_T>(ddr, 0, T::LEAD);
	GenericRegisterTest<T, set_ddr_t, DDR_T>(ddr, static_cast<DDR_T>(~T::LEAD), 0xFF);
	GenericRegisterTest<T, set_ddr_t, DDR_T>(ddr, static_cast<DDR_T>(T::LEAD>>1), static_cast<DDR_T>(T::LEAD | (T::LEAD>>1)));
	GenericRegisterTest<T, set_ddr_t, DDR_T>(ddr, static_cast<DDR_T>(T::LEAD<<1), static_cast<DDR_T>(T::LEAD | (T::LEAD<<1)));

	GenericRegisterTest<T, set_port_t, PORT_T>(port, 0, T::LEAD);
	GenericRegisterTest<T, set_port_t, PORT_T>(port, static_cast<PORT_T>(~T::LEAD), 0xFF);
	GenericRegisterTest<T, set_port_t, PORT_T>(port, static_cast<PORT_T>(T::LEAD>>1), static_cast<DDR_T>(T::LEAD | (T::LEAD>>1)));
	GenericRegisterTest<T, set_port_t, PORT_T>(port, static_cast<PORT_T>(T::LEAD<<1), static_cast<DDR_T>(T::LEAD | (T::LEAD<<1)));

	pin = 0;
    ASSERT_EQ(get_pin<T>(), 0);

    pin = static_cast<std::remove_reference<PIN_T>::type>(T::LEAD >> 1);
    ASSERT_EQ(get_pin<T>(), 0);

    pin = static_cast<std::remove_reference<PIN_T>::type>(T::LEAD << 1);
    ASSERT_EQ(get_pin<T>(), 0);

    pin = T::LEAD;
    ASSERT_EQ(get_pin<T>(), pin);

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
	map<TestGroupA, LA0, LA1, LA2, LA3, LA4, LA5, LA6, LA7>();
}

TEST(SingleBit, GroupB)
{
	map<TestGroupB, LB0, LB1, LB2, LB3, LB4, LB5, LB6, LB7>();
}

TEST(SingleBit, GroupC)
{
	map<TestGroupB, LB0, LB1, LB2, LB3, LB4, LB5, LB6, LB7>();
}

TEST(SingleBit, GroupD)
{
	map<TestGroupD, LD0, LD1, LD2, LD3, LD4, LD5, LD6, LD7>();
}

TEST(SingleBit, GroupE)
{
	map<TestGroupE, LE0, LE1, LE2, LE3, LE4, LE5, LE6, LE7>();
}

TEST(SingleBit, GroupF)
{
	map<TestGroupF, LF0, LF1, LF2, LF3, LF4, LF5, LF6, LF7>();
}
