#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++) {
        prototype[i] = nullptr;
    }
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        delete prototype[i];
        prototype[i] = nullptr;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    for (int i = 0; i < 4; i++) {
        if (other.prototype[i])
            prototype[i] = other.prototype[i]->clone();
        else
            prototype[i] = nullptr;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            delete prototype[i];
            if (other.prototype[i])
                prototype[i] = other.prototype[i]->clone();
            else
                prototype[i] = nullptr;
            }
        }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < 4; i++) {
        if (!prototype[i]) {
            prototype[i] = m;
            return;
        }
    }
    std::cout << "MateriaSource: No space to learn new materia." << std::endl;
}


AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (prototype[i] && prototype[i]->getType() == type) {
            return prototype[i]->clone();
        }
    }
    std::cout << "MateriaSource: No materia of type " << type << " found." << std::endl;
    return nullptr;
}