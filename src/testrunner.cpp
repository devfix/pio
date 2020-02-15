#ifdef AVR

#include "include/library.h"

/**
 * Just a simple test that avr-gcc can handle the template stuff.
 */

int main()
{
	set_ddr<LA1, LA3, LA5, LA7>();
	clear_ddr<LA0, LA2, LA4, LA6>();
	set_port<LA1, LA3, LA5, LA7>();
	clear_port<LA0, LA3, LA4, LA6>();
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
