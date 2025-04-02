#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name):name(name), weapon(NULL)
{
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void HumanB::attack()
{
    if (weapon)
        std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << this->name << " has no weapon to attack" << std::endl;
}
