#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

class DiamondTrap : public ScavTrap , public FragTrap {
    private:
        std::string name;
    public:
        using ScavTrap::attack;

        DiamondTrap(std::string name);
        ~DiamondTrap();
        
        void whoAmI();
} ;

#endif 