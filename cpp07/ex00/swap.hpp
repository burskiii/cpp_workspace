#ifndef SWAP_HPP
#define SWAP_HPP

#include <iostream>
#include <string>



template <typename T>
//T is a generic  type parameter
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
const T &min(const T &a, const T &b)
{
    return (a < b) ? a : b;
}

template <typename T>
const T &max(const T &a, const T &b)
{
    return (a > b) ? a : b;
}

#endif
