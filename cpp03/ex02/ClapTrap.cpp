#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) 
        : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << name << " deployed!" << std::endl;  
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << " is destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (hitPoints == 0 || energyPoints == 0)
    {
        std::cout << "not enough points to attack!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->name << " attacks " << target <<
    " , causing " << attackDamage << " points of damage!" << std::endl;
    energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
   if (hitPoints == 0) {
        std::cout << name << " is already destroyed!" << std::endl;
        return ;
    }
    if (amount > hitPoints)
        hitPoints = 0;
    else 
        hitPoints -= amount;
    std::cout << name << " tooe " << amount << " damage, remaining HP: " << hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (energyPoints == 0) {
        std::cout << name << " has no more Energy Points!" << std::endl;
        return ;
    }
    hitPoints += amount;
    energyPoints--;
    std::cout << name << " repairs itself, recovering " << amount << " HP. Now has " 
              << hitPoints << " HP and " << energyPoints << " energy points." << std::endl;
}