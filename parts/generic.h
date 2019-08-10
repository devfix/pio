#include <avr/io.h>

#ifdef HIGH
  #undef HIGH
  #warning Redefining HIGH...
#endif
#define HIGH 1

#ifndef LOW
  #undef LOW
  #warning Redefining LOW...
#endif
#define LOW  0

#ifndef OUT
  #undef OUT
  #warning Redefining OUT...
#endif
#define OUT 1

#ifndef OUTPUT
  #undef OUTPUT
  #warning Redefining OUTPUT...
#endif
#define OUTPUT 1

#ifndef IN
  #undef IN
  #warning Redefining IN...
#endif
#define IN 0

#ifndef INPUT
  #undef INPUT
  #warning Redefining INPUT...
#endif
#define INPUT 0

#define BREAKPOINT asm("break\nnop")
