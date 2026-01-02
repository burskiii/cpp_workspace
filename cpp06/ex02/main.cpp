#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    std::srand(std::time(NULL));

    for (int i = 0; i < 10; ++i)
    {
        Base* obj = generate();

        std::cout << "Identifying by pointer: ";
        identify(obj);

        std::cout << "Identifying by reference: ";
        identify(*obj);

        delete obj;
    }
}