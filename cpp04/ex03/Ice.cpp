#include "Ice.hpp"
#include "color.hpp"
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
	std::cout << "Cloning " << MAGENTA << "Ice " << RESET << "materia... " << std::endl;
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << BLUE << "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
}



