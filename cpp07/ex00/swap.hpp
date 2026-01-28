#ifndef SWAP_HPP
#define SWAP_HPP

template <typename T>

void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

// If equal, return the second one.
// Using only operator< requirement: if a < b -> a else -> b (so equal returns b).
template <typename T>
const T &min(const T &a, const T &b)
{
    return (a < b) ? a : b;
}

// If equal, return the second one.
// Using only operator> requirement: if a > b -> a else -> b (so equal returns b).
template <typename T>
const T &max(const T &a, const T &b)
{
    return (a > b) ? a : b;
}

#endif