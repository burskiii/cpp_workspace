#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << "ScavTrap " << name << " deployed!" << std::endl; 
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << name << " is destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (hitPoints == 0 || energyPoints == 0)
    {
        std::cout << "not enough points to attack!" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->name << " attacks " << target <<
    " , causing " << attackDamage << " points of damage!" << std::endl;
    energyPoints--;
    std::cout << "Remaining energy: " << energyPoints << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode!" << std::endl;
}