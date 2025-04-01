#include "Weapon.hpp"
#include "Human.hpp"

Weapon::Weapon(std::string type)
{
}

Weapon::~Weapon()
{
}

Weapon::Weapon(std::string type)
{
	Weapon &name;
	name = type;
}
void Weapon::getType(std::string type) const
{
	this->type = type;
}

void Weapon::setType()
{
	Weapon &type;

	type = this->type
	std::coout << "Weapon type: " << &type << std::endl;
}
