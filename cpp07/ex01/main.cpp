#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void printConst(const T& x)
{
    std::cout << x << std::endl;
}

int main()
{
    std::string array1[] = {"hi", "this is 42 Berlin", "my code works" };
    int array2[] = {1, 2, 3, 4, 5};

	int lenght1 = sizeof(array1) / sizeof(array1[0]);
    int lenght2 = sizeof(array2) / sizeof(array2[0]);


    std::cout << "Printing array1:" << std::endl;
    ::iter(array1, lenght1, printConst<std::string>);
    std::cout << std::endl;

    std::cout << "Printing array2:" << std::endl;
    ::iter(array2, lenght2, printConst<int>);
    std::cout << std::endl;

    return 0;
}
