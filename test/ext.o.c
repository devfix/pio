# 1 "ext.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "ext.c"
# 1 "../pio/src/pio.h" 1
# 54 "../pio/src/pio.h"
# 1 "/usr/lib/avr/include/avr/io.h" 1 3
# 99 "/usr/lib/avr/include/avr/io.h" 3
# 1 "/usr/lib/avr/include/avr/sfr_defs.h" 1 3
# 126 "/usr/lib/avr/include/avr/sfr_defs.h" 3
# 1 "/usr/lib/avr/include/inttypes.h" 1 3
# 37 "/usr/lib/avr/include/inttypes.h" 3
# 1 "/usr/lib/gcc/avr/4.9.2/include/stdint.h" 1 3 4
# 9 "/usr/lib/gcc/avr/4.9.2/include/stdint.h" 3 4
# 1 "/usr/lib/avr/include/stdint.h" 1 3 4
# 121 "/usr/lib/avr/include/stdint.h" 3 4
typedef signed int int8_t __attribute__((__mode__(__QI__)));
typedef unsigned int uint8_t __attribute__((__mode__(__QI__)));
typedef signed int int16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int uint16_t __attribute__ ((__mode__ (__HI__)));
typedef signed int int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int uint32_t __attribute__ ((__mode__ (__SI__)));

typedef signed int int64_t __attribute__((__mode__(__DI__)));
typedef unsigned int uint64_t __attribute__((__mode__(__DI__)));
# 142 "/usr/lib/avr/include/stdint.h" 3 4
typedef int16_t intptr_t;




typedef uint16_t uintptr_t;
# 159 "/usr/lib/avr/include/stdint.h" 3 4
typedef int8_t int_least8_t;




typedef uint8_t uint_least8_t;




typedef int16_t int_least16_t;




typedef uint16_t uint_least16_t;




typedef int32_t int_least32_t;




typedef uint32_t uint_least32_t;







typedef int64_t int_least64_t;






typedef uint64_t uint_least64_t;
# 213 "/usr/lib/avr/include/stdint.h" 3 4
typedef int8_t int_fast8_t;




typedef uint8_t uint_fast8_t;




typedef int16_t int_fast16_t;




typedef uint16_t uint_fast16_t;




typedef int32_t int_fast32_t;




typedef uint32_t uint_fast32_t;







typedef int64_t int_fast64_t;






typedef uint64_t uint_fast64_t;
# 273 "/usr/lib/avr/include/stdint.h" 3 4
typedef int64_t intmax_t;




typedef uint64_t uintmax_t;
# 10 "/usr/lib/gcc/avr/4.9.2/include/stdint.h" 2 3 4
# 38 "/usr/lib/avr/include/inttypes.h" 2 3
# 77 "/usr/lib/avr/include/inttypes.h" 3
typedef int32_t int_farptr_t;



typedef uint32_t uint_farptr_t;
# 127 "/usr/lib/avr/include/avr/sfr_defs.h" 2 3
# 100 "/usr/lib/avr/include/avr/io.h" 2 3
# 298 "/usr/lib/avr/include/avr/io.h" 3
# 1 "/usr/lib/avr/include/avr/iom16.h" 1 3
# 639 "/usr/lib/avr/include/avr/iom16.h" 3
       
# 640 "/usr/lib/avr/include/avr/iom16.h" 3

       

       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
# 299 "/usr/lib/avr/include/avr/io.h" 2 3
# 627 "/usr/lib/avr/include/avr/io.h" 3
# 1 "/usr/lib/avr/include/avr/portpins.h" 1 3
# 628 "/usr/lib/avr/include/avr/io.h" 2 3

# 1 "/usr/lib/avr/include/avr/common.h" 1 3
# 630 "/usr/lib/avr/include/avr/io.h" 2 3

# 1 "/usr/lib/avr/include/avr/version.h" 1 3
# 632 "/usr/lib/avr/include/avr/io.h" 2 3






# 1 "/usr/lib/avr/include/avr/fuse.h" 1 3
# 248 "/usr/lib/avr/include/avr/fuse.h" 3
typedef struct
{
    unsigned char low;
    unsigned char high;
} __fuse_t;
# 639 "/usr/lib/avr/include/avr/io.h" 2 3


# 1 "/usr/lib/avr/include/avr/lock.h" 1 3
# 642 "/usr/lib/avr/include/avr/io.h" 2 3
# 55 "../pio/src/pio.h" 2
# 91 "../pio/src/pio.h"
static const unsigned char A0 = 1;

static const unsigned char A1 = 2;

static const unsigned char A2 = 4;

static const unsigned char A3 = 8;

static const unsigned char A4 = 16;

static const unsigned char A5 = 32;

static const unsigned char A6 = 64;

static const unsigned char A7 = 128;


static const unsigned char B0 = 1;

static const unsigned char B1 = 2;

static const unsigned char B2 = 4;

static const unsigned char B3 = 8;

static const unsigned char B4 = 16;

static const unsigned char B5 = 32;

static const unsigned char B6 = 64;

static const unsigned char B7 = 128;


static const unsigned char C0 = 1;

static const unsigned char C1 = 2;

static const unsigned char C2 = 4;

static const unsigned char C3 = 8;

static const unsigned char C4 = 16;

static const unsigned char C5 = 32;

static const unsigned char C6 = 64;

static const unsigned char C7 = 128;


static const unsigned char D0 = 1;

static const unsigned char D1 = 2;

static const unsigned char D2 = 4;

static const unsigned char D3 = 8;

static const unsigned char D4 = 16;

static const unsigned char D5 = 32;

static const unsigned char D6 = 64;

static const unsigned char D7 = 128;


static const unsigned char E0 = 1;

static const unsigned char E1 = 2;

static const unsigned char E2 = 4;

static const unsigned char E3 = 8;

static const unsigned char E4 = 16;

static const unsigned char E5 = 32;

static const unsigned char E6 = 64;

static const unsigned char E7 = 128;


static const unsigned char F0 = 1;

static const unsigned char F1 = 2;

static const unsigned char F2 = 4;

static const unsigned char F3 = 8;

static const unsigned char F4 = 16;

static const unsigned char F5 = 32;

static const unsigned char F6 = 64;

static const unsigned char F7 = 128;
# 2 "ext.c" 2


void foo(){

}
