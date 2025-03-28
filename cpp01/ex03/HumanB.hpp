#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <sstream>
#include <string>

#include "Weapon.cpp"

class HumanB
{
    private:
        std::string name;
        std::string weapon;
    public:
        void attack();
}