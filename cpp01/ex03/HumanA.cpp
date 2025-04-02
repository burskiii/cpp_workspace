#include "HumanA.hpp"

// Constructor must use an initialization list for references!
HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
    std::cout << this->name << " is here" << std::endl;
}

// Destructor
HumanA::~HumanA()
{
    std::cout << this->name << " is dead" << std::endl;
}

void HumanA::attack()
{
    std::cout << this->name << " attacks with their " << weapon.getType() << std::endl;
}
