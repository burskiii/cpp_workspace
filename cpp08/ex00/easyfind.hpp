#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

template <typename T> void easyfind(T &container, int value);

template <typename T>
void easyfind(T &container, int value)
{
	    typename T::iterator iter = std::find(container.begin(), container.end(), value);
    if (iter == container.end())
        std::cout << "Value has not been found" << std::endl;
    else
        std::cout << "Value has beenfound: " << *iter << std::endl;
    return;
};

#endif
