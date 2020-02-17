#ifndef PIO_MEM_HPP
#define PIO_MEM_HPP

#ifdef __AVR__
#define FORCE_INLINE __attribute__((always_inline)) inline
#else
#define FORCE_INLINE inline
#endif

#endif // PIO_MEM_HPP
