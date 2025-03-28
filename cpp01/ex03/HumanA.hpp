#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <sstream>
#include <string>

#include "Weapon.cpp"

class HumanA
{
    private:
        std::string name;
        std::string weapon;
    public:
        void attack();
}