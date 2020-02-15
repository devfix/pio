#ifndef PIO_CONCAT_HPP
#define PIO_CONCAT_HPP

#include "linkedlist.h"
#include "pin.h"

/**
 * concat
 * pins of the same port (group) get combined (by logic or) resulting in a list with only one element for each used port
 */

template<typename T>
struct concat {};

template<typename T>
using concat_t = typename concat<T>::type;

template<>
struct concat<nil> {
    using type = nil;
};

template<typename T>
struct concat<cons<T, nil>> {
    using type = cons<T, nil>;
};

template<char P1, unsigned char L1, unsigned char L2, typename R>
struct concat<cons<pio_pin<P1, L1>, cons<pio_pin<P1, L2>, R>>> {
    using type = concat_t<cons<pio_pin<P1, L1 | L2>, R>>;
};

template<char P1, unsigned char L1, char P2, unsigned char L2, typename R>
struct concat<cons<pio_pin<P1, L1>, cons<pio_pin<P2, L2>, R>>> {
    using type = cons<pio_pin<P1, L1>, concat_t<cons<pio_pin<P2, L2>, R>>>;
};

#endif // PIO_CONCAT_HPP
