#ifndef PIO_LIBRARY_HPP
#define PIO_LIBRARY_HPP

#include "concat.hpp"

template<typename ... PINS>
void set_ddr()
{
	concat_t<sort_t<build_t<PINS...>>>().ddr_set();
}

template<typename ... PINS>
void clear_ddr()
{
	concat_t<sort_t<build_t<PINS...>>>().ddr_clear();
};

template<typename ... PINS>
void set_port()
{
	concat_t<sort_t<build_t<PINS...>>>().port_set();
};

template<typename ... PINS>
void clear_port()
{
	concat_t<sort_t<build_t<PINS...>>>().port_clear();
};

#endif // PIO_LIBRARY_HPP
