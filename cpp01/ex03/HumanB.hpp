#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp" 

class HumanB
{
    private:
        std::string name;
        Weapon *weapon; // Pointer because HumanB might not always have a weapon

    public:
        HumanB(std::string name);
        void setWeapon(Weapon &weapon);
        void attack();
};

#endif
