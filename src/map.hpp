//
// Created by core on 1/30/20.
//

#ifndef MAP_HPP
#define MAP_HPP

template<template<typename> typename F, typename ... Ts>
struct map
{
};

template<template<typename> typename F, typename T>
struct map<F, T>
{
	using type = void;
	map()
	{
		F<T>();
	}
};

template<template<typename> typename F, typename T, typename ... Ts>
struct map<F, T, Ts ...>
{
	using type = typename map<F, Ts...>::type;
	map()
	{
		F<T>();
		map<F, Ts...>();
	}
};

#endif // MAP_HPP
