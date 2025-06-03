#include "Cure.hpp"
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
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
