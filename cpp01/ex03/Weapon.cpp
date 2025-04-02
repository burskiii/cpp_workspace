#include "Weapon.hpp"

// Constructor: initializes 'type'
Weapon::Weapon(std::string type) : type(type) 
{
}

// Destructor
Weapon::~Weapon() 
{
}

// Getter: returns a reference to 'type'
const std::string& Weapon::getType() const 
{
    return this->type;
}

// Setter: updates 'type' using newType
void Weapon::setType(const std::string& newType) 
{
    this->type = newType;
}
