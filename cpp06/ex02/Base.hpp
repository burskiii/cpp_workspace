#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>


class Base 
{
    public:
        Base();
        virtual ~Base(); // dynamic_cast only workds with polymorphic types, so we need at least one virtual function
        static Base * generate(void);
};

void identify(Base* p);
void identify(Base& p);

#endif 