#ifndef PIO_LIBRARY_H
#define PIO_LIBRARY_H

#include "concat.hpp"

template<typename ... PINS>
struct set_port {
    set_port() { concat_t<sort_t<build_t<PINS...>>>().port_set(); }
};

template<typename ... PINS>
struct clear_port {
    clear_port() { concat_t<sort_t<build_t<PINS...>>>().port_clear(); }
};

#endif //PIO_LIBRARY_H
