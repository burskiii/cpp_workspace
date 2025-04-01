#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <sstream>
#include <string>

#include "Weapon.hpp"

class HumanB
{
    private:
        std::string name;
        std::string Weapon;
		
    public:
        void attack();
};

#endif // HUMANB_HPP
