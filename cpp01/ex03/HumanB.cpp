#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
}

HumanB::HumanB(std::string &Weapon)
{
	&Weapon = Weapon;
}

void HumanB::attack()
{
	std::cout << this->name << " attacks with their " << this->Weapon.getType() << std::endl;
}
