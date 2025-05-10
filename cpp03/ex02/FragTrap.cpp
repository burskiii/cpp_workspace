#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout << "FragTrap " << name << " deployed!" << std::endl; 
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << name << " is destroyed!" << std::endl; 
}

void FragTrap::attack(const std::string& target) {
    if (hitPoints == 0 || energyPoints == 0)
    {
        std::cout << "not enough points to attack!" << std::endl;
        return ;
    }
    std::cout << "FragTrap " << this->name << " attacks " << target <<
    " , causing " << attackDamage << " points of damage!" << std::endl;
    energyPoints--;
    std::cout << "Remaining energy: " << energyPoints << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "Give me high five y'all!" << std::endl;
}