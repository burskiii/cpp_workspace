#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <sstream>
#include <string>

#include "Weapon.hpp"

class HumanA
{
    private:
        std::string name;
        std::string Weapon;
    public:
	HumanA();
	~HumanA();
	void attack();
};

#endif // HUMANA_HPP
