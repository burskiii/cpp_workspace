#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>


class Weapon
{
    private:
        std::string type;
    
    public:
        Weapon(std::string type);   // Constructor
        ~Weapon();                  // Destructor
        const std::string& getType() const; // Getter should return a reference
        void setType(const std::string& newType); // Setter takes a const reference
};

#endif
