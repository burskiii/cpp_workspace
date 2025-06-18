#include "Cure.hpp"
#include "color.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {}

Cure::Cure(Cure const &other) : AMateria(other) {
    type = other.type;
}

Cure &Cure::operator=(const Cure& other) {
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

Cure::~Cure() {}

AMateria* Cure::clone() const {
	std::cout << "Cloning " << MAGENTA << "Cure " << RESET << "materia... " << std::endl;
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout << GREEN <<  "* heals " << target.getName() << "'s wounds *" <<  RESET << std::endl;
}
