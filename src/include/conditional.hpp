#ifndef PIO_CONDITIONAL_HPP
#define PIO_CONDITIONAL_HPP

template<bool B, class T, class F>
struct conditional {
    typedef T type;
};

template<class T, class F>
struct conditional<false, T, F> {
    typedef F type;
};

template<bool B, class T, class F>
using conditional_t = typename conditional<B, T, F>::type;

#endif // PIO_CONDITIONAL_HPP
