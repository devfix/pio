#include <avr/io.h>

#ifdef HIGH
  #undef HIGH
  #ifndef PIO_SUPPRESS_REDEFINITION
    #warning Redefining 'HIGH' to '1'
  #endif
#endif
#define HIGH 1

#ifndef LOW
  #undef LOW
  #ifndef PIO_SUPPRESS_REDEFINITION
    #warning Redefining 'LOW' to '0'
  #endif
#endif
#define LOW  0

#ifndef PIO_OUT
  #undef PIO_OUT
  #ifndef PIO_SUPPRESS_REDEFINITION
    #warning Redefining 'PIO_OUT' to '1'
  #endif
#endif
#define PIO_OUT 1

#ifndef OUTPUT
  #undef OUTPUT
  #ifndef PIO_SUPPRESS_REDEFINITION
    #warning Redefining 'OUTPUT' to '1'
  #endif
#endif
#define OUTPUT 1

#ifndef PIO_IN
  #undef PIO_IN
  #ifndef PIO_SUPPRESS_REDEFINITION
    #warning Redefining 'PIO_IN' to '0'
  #endif
#endif
#define PIO_IN 0

#ifndef INPUT
  #undef INPUT
  #ifndef PIO_SUPPRESS_REDEFINITION
    #warning Redefining 'INPUT' to '0'
  #endif
#endif
#define INPUT 0

#define BREAKPOINT asm("break\nnop")
