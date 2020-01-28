#ifndef PIO_LIBRARY_HPP
#define PIO_LIBRARY_HPP

#include "concat.hpp"

template<typename ... PINS>
struct set_ddr {
    set_ddr() { concat_t<sort_t<build_t<PINS...>>>().ddr_set(); }
};

template<typename ... PINS>
struct clear_ddr {
    clear_ddr() { concat_t<sort_t<build_t<PINS...>>>().ddr_clear(); }
};

template<typename ... PINS>
struct set_port {
    set_port() { concat_t<sort_t<build_t<PINS...>>>().port_set(); }
};

template<typename ... PINS>
struct clear_port {
    clear_port() { concat_t<sort_t<build_t<PINS...>>>().port_clear(); }
};

#endif //PIO_LIBRARY_HPP
