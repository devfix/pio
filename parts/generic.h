#include <avr/io.h>

#ifdef HIGH
  #undef HIGH
#endif
#define HIGH 1

#ifndef LOW
  #undef LOW
#endif
#define LOW  0

#ifndef OUT
  #undef OUT
#endif
#define OUT 1

#ifndef OUTPUT
  #undef OUTPUT
#endif
#define OUTPUT 1

#ifndef IN
  #undef IN
#endif
#define IN 0

#ifndef INPUT
  #undef INPUT
#endif
#define INPUT 0
