#ifndef PIO_MEM_H
#define PIO_MEM_H

#ifdef AVR
#define FORCE_INLINE __attribute__((always_inline)) inline
#else
#define FORCE_INLINE __attribute__((always_inline)) inline
#endif

#endif //PIO_MEM_H
