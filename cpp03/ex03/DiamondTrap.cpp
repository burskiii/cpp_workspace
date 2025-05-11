#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
            : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
    this->name = name;
    this->hitPoints =100;
    this->energyPoints = 50;
    this->attackDamage = 30;
    
    std::cout << "\n------------\n" << std::endl;
    std::cout << "DiamondTrap " << name << " deployed!" << std::endl;
    std::cout << "HP: " << hitPoints << std::endl;
    std::cout << "Energy Points: " << energyPoints << std::endl;
    std::cout << "Attack Damage: " << attackDamage << std::endl;
    std::cout << "\n------------\n" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << name << " is destroyed!" << std::endl;
}

void DiamondTrap::whoAmI(void) {
    std::cout << "I am: " << this->name 
                << " , and my ClapTrap name is " << ClapTrap::name << std::endl;
}