#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>
#include <sstream>

class Weapon
{
    private:
        std::string type;
        Weapon();
        ~Weapon();

    public:
        void getType();
        void setType();

}