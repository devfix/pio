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

#include <gtest/gtest.h>

/**
 * Run google test for x86 compiler.
 */

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

#endif
