#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name)
{
	this->name = name;
	Weapon *Weapon = this->Weapon;
}

\

HumanA::attack()
{
	std::cout << this->name << " attacks with their " << this->Weapon.getType() << std::endl;
}
