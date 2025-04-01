#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>
#include <sstream>

class Weapon
{
    private:
        std::string type;

    public:
		Weapon();
		Weapon(std::string type);
		~Weapon();
        void getType(std::string type);
        void setType();

};

#endif // WEAPON_HPP

