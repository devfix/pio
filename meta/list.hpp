#ifndef PINS_LIST_HPP
#define PINS_LIST_HPP

#ifndef AVR

#include <ostream>

#endif

#include "io.h"
#include "conditional.h"

/**
 * constructors
 */

struct nil {
	static void high() {}

	static void low() {}

#ifndef AVR

	friend std::ostream &operator<<(std::ostream &os, const nil &) {
		return os;
	}

#endif
};

template<typename A, typename AS>
struct cons {
	using X = A;
	using XS = AS;

	static void high() {
		A().high();
		XS().high();
	}

	static void low() {
		A().low();
		XS().low();
	}


#ifndef AVR

	friend std::ostream &operator<<(std::ostream &os, const cons<X, XS> &) {
		return os << X() << " " << XS();
	}

#endif
};

/**
 * build
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
 *
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
	using type = typename conditional<X() <= min_t<XS>(), X, min_t<XS>>::type;
};

template<typename XS>
struct drop_min {
};

template<typename XS>
using drop_min_t = typename drop_min<XS>::type;


template<typename X>
struct drop_min<cons<X, nil>> {
	using type = nil;
};

template<typename X, typename XS>
struct drop_min<cons<X, XS>> {
	using type = typename conditional<X() <= min_t<XS>(),
		cons<min_t<XS>, drop_min_t<XS>>,
		cons<X, drop_min_t<XS>>
	>::type;
};

/**
 * sort
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


#endif //PINS_LIST_HPP
