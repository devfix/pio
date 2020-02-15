#ifndef PIO_MEM_HPP
#define PIO_MEM_HPP

#ifdef AVR
#define FORCE_INLINE __attribute__((always_inline)) inline
#else
#define FORCE_INLINE inline
#endif

#endif // PIO_MEM_HPP
