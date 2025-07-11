#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {}

Ice::~Ice() {}

Ice::Ice(const Ice& other) : AMateria(other) {
    type = other.type;
}

Ice &Ice::operator=(const Ice& other) {
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

AMateria* Ice::clone() const {
    std::cout << "Cloning Ice materia" << std::endl;
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}



