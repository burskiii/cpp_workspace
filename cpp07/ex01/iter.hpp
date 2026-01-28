#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef> // for size_t

// For non-const arrays + functions taking T&
template <typename T>

void iter(T* array, const size_t length, void (*f)(T&))
{
    if (!array || !f)
        return;
    for (size_t i = 0; i < length; ++i)
        f(array[i]);
}

// For const arrays + functions taking const T&
template <typename T>

void iter(const T* array, const size_t length, void (*f)(const T&))
{
    if (!array || !f)
        return;
    for (size_t i = 0; i < length; ++i)
        f(array[i]);
}

#endif
