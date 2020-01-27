//
// Created by core on 1/27/20.
//

#ifndef CONDITIONAL_H
#define CONDITIONAL_H

template<bool B, class T, class F>
struct conditional
{
	typedef T type;
};

template<class T, class F>
struct conditional<false, T, F>
{
	typedef F type;
};

#endif //CONDITIONAL_H
