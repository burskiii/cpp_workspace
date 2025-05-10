#include "ClapTrap.hpp"

int main() {
    
    std::cout << "\n--- Initial State ---\n" << std::endl;
    ClapTrap name("Bob");

    std::cout << "\n--- Attacking ---\n" << std::endl;
    name.attack("Enemy 1");
    name.attack("Enemy 2");
    name.attack("Enemy 3");

    std::cout << "\n--- Taking Damage ---\n" << std::endl;
    name.takeDamage(5);

    std::cout << "\n--- Repairing ---\n" << std::endl;
    name.beRepaired(3);

    std::cout << "\n--- Exhausting Energy ---\n" << std::endl;
    for(int i = 0; i < 10; i++)
        name.attack("Dummy");
    
    std::cout << "\n--- critical Damage ---\n" << std::endl;
    name.takeDamage(100);
    name.attack("Final Boss");
    name.beRepaired(5);

    return 0;
}