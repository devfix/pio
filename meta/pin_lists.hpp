#ifndef PINS_PIN_LISTS_HPP
#define PINS_PIN_LISTS_HPP

#include "list.hpp"
#include "pin.hpp"

/**
 * concat pins
 */

template<typename T>
struct pin_lists {};

template<typename T>
using concat_pins_t = typename pin_lists<T>::type;

template<>
struct pin_lists<nil> {
    using type = nil;
};

template<typename T>
struct pin_lists<cons<T, nil>> {
    using type = cons<T, nil>;
};

template<char P1, unsigned char L1, unsigned char L2, typename R>
struct pin_lists<cons<pin<P1, L1>, cons<pin<P1, L2>, R>>> {
    using type = concat_pins_t<cons<pin<P1, L1 | L2>, R>>;
};

template<char P1, unsigned char L1, char P2, unsigned char L2, typename R>
struct pin_lists<cons<pin<P1, L1>, cons<pin<P2, L2>, R>>> {
    using type = cons<pin<P1, L1>, concat_pins_t<cons<pin<P2, L2>, R>>>;
};

#endif //PINS_PIN_LISTS_HPP
