#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <sstream>
#include <string>

#include "Weapon.hpp"

class HumanA
{
    private:
        std::string name;
        Weapon &weapon;  // Reference to Weapon, must always have one
    
    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA();
        void attack();
};

#endif
