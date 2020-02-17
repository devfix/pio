#include "include/library.h"

#ifndef __AVR__

DDR_T DDRA{};
DDR_T DDRB{};
DDR_T DDRC{};
DDR_T DDRD{};
DDR_T DDRE{};
DDR_T DDRF{};

PORT_T PORTA{};
PORT_T PORTB{};
PORT_T PORTC{};
PORT_T PORTD{};
PORT_T PORTE{};
PORT_T PORTF{};

PIN_T PINA{};
PIN_T PINB{};
PIN_T PINC{};
PIN_T PIND{};
PIN_T PINE{};
PIN_T PINF{};

#endif
