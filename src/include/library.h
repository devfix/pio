#ifndef PIO_LIBRARY_HPP
#define PIO_LIBRARY_HPP

#include "concat.h"

template<typename ... PINS>
void set_ddr()
{
	concat_t<sort_t<build_t<PINS...>>>().ddr_set();
}

template<typename ... PINS>
struct set_ddr_t
{
	set_ddr_t()
	{
		set_ddr<PINS...>();
	}
};

template<typename ... PINS>
void clear_ddr()
{
	concat_t<sort_t<build_t<PINS...>>>().ddr_clear();
};

template<typename ... PINS>
struct clear_ddr_t
{
	clear_ddr_t()
	{
		clear_ddr<PINS...>();
	}
};

template<typename ... PINS>
void set_port()
{
	concat_t<sort_t<build_t<PINS...>>>().port_set();
};

template<typename ... PINS>
struct set_port_t
{
	set_port_t()
	{
		set_port<PINS...>();
	}
};

template<typename ... PINS>
void clear_port()
{
	concat_t<sort_t<build_t<PINS...>>>().port_clear();
};

template<typename ... PINS>
struct clear_port_t
{
	clear_port_t()
	{
		clear_port<PINS...>();
	}
};

template<typename PIN, typename ... PINS>
constexpr PIN_T get_pin()
{
    return concat_t<sort_t<build_t<PIN, PINS...>>>().pin_get();
};

#endif // PIO_LIBRARY_HPP
