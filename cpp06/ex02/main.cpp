#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
    std::srand(std::time(NULL));

    for (int i = 0; i < 10; ++i)
    {
        Base* obj = Base::generate();

        std::cout << "Identifying by pointer: ";
        identify(obj);

        std::cout << "Identifying by reference: ";
        identify(*obj);

        delete obj;
    }
}