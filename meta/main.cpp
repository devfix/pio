#ifndef AVR

#include <iostream>

#include "pin_lists.hpp"

int main() {
    using xs = build_t<D0, A0, C0, A2, B0, A1, D0, A4>;
    std::cout << "Pins: " << xs() << std::endl;
    std::cout << "Groups: " << concat_pins_t<sort_t<xs>>() << std::endl;
    std::cout << std::bitset<8>(PORTA) << " " << std::bitset<8>(PORTB) << " " << std::bitset<8>(PORTC) << " "
              << std::bitset<8>(PORTD) << std::endl;
    concat_pins_t<sort_t<xs>>().high();
    std::cout << std::bitset<8>(PORTA) << " " << std::bitset<8>(PORTB) << " " << std::bitset<8>(PORTC) << " "
              << std::bitset<8>(PORTD) << std::endl;
    return 0;
}

#else

#include "pin_lists.hpp"

int main()
{
	using xs = build_t<D0, A0, C0, A2, B0, A1, D0, A4>;
	asm("nop\nnop\nnop");
	concat_pins_t<sort_t<xs>>().high();
	asm("nop\nnop\nnop");
}

#endif
