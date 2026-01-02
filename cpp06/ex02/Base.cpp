#include "Base.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

Base::~Base(){}

Base * generate(void)
{
    int randNum = std::rand() % 3;
    switch (randNum)
    {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return NULL; // This should never happen
    }
}

void identify(Base* p)
{
    if (!p)
    {
        std::cout << "Unknown" << std::endl;
        return;
    }    
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}

void identify(Base& p)
{
    try {
        dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch (...) {}
    try {
        dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (...) {}
    try {
        dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch (...) {}
    std::cout << "Unknown" << std::endl;
}