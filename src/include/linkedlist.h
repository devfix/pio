#ifndef PIO_LINKEDLIST_HPP
#define PIO_LINKEDLIST_HPP

#include "mem.h"

#ifndef __AVR__

#include <ostream>

#endif

#include "io.h"
#include "conditional.h"

/**
 * constructors for a linkedlist
 */

struct nil {
    FORCE_INLINE static void ddr_set() {}
    FORCE_INLINE static void ddr_clear() {}
    FORCE_INLINE static void port_set() {}
    FORCE_INLINE static void port_clear() {}
    FORCE_INLINE static void port_toggle() {}
    static constexpr PIN_T pin_get() { return 0; }

#ifndef __AVR__
    friend std::ostream &operator<<(std::ostream &os, const nil &) {
        return os;
    }
#endif
};

template<typename X, typename XS>
struct cons {
    FORCE_INLINE static void ddr_set() {
        X::ddr_set();
        XS().ddr_set();
    }

    FORCE_INLINE static void ddr_clear() {
    	X::ddr_clear();
        XS().ddr_clear();
    }

    FORCE_INLINE static void port_set() {
    	X::port_set();
        XS().port_set();
    }

    FORCE_INLINE static void port_clear() {
    	X::port_clear();
        XS().port_clear();
    }

    FORCE_INLINE static void port_toggle() {
    	X::port_toggle();
        XS().port_toggle();
    }

    static constexpr PIN_T pin_get() {
        return static_cast<PIN_T>(X::pin_get() | XS().pin_get());
    }

#ifndef __AVR__
    friend std::ostream &operator<<(std::ostream &os, const cons<X, XS> &) {
        return os << X() << " " << XS();
    }
#endif
};

/**
 * build
 * creates a linkedlist from variadic template
 */

template<typename... Ts>
struct build {};

template<typename... Ts>
using build_t = typename build<Ts...>::type;

template<typename T>
struct build<T> {
    using type = cons<T, nil>;
};

template<typename T, typename ... Ts>
struct build<T, Ts...> {
    using type= cons<T, build_t<Ts...>>;
};

/**
 * min
 * returns the lowest element of the list
 */

template<typename XS>
struct min {
};

template<typename XS>
using min_t = typename min<XS>::type;

template<typename X>
struct min<cons<X, nil>> {
    using type = X;
};

template<typename X, typename XS>
struct min<cons<X, XS>> {
    using type = conditional_t<X() <= min_t<XS>(), X, min_t<XS>>;
};


/**
 * drop_min
 * returns the list without the lowest element
 */

template<typename XS>
struct drop_min {};

template<typename XS>
using drop_min_t = typename drop_min<XS>::type;

template<typename X>
struct drop_min<cons<X, nil>> {
    using type = nil;
};

template<typename X, typename XS>
struct drop_min<cons<X, XS>> {
    using type = conditional_t<
            X() <= min_t<XS>(),
            XS,
            cons<X, drop_min_t<XS>
            > >;
};

/**
 * sort
 * returns the list sorted
 */
template<typename XS>
struct sort;

template<typename T>
using sort_t = typename sort<T>::type;

template<typename XS>
struct sort {
    using type = cons<min_t<XS>, sort_t<drop_min_t<XS>>>;
};

template<>
struct sort<nil> {
    using type = nil;
};


#endif // PIO_LINKEDLIST_HPP
