#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++) {
        materia[i] = NULL;
    }
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        delete materia[i];
        materia[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    for (int i = 0; i < 4; i++) {
        if (other.materia[i])
            materia[i] = other.materia[i]->clone();
        else
            materia[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            delete materia[i];
            if (other.materia[i])
                materia[i] = other.materia[i]->clone();
            else
                materia[i] = NULL;
            }
        }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < 4; i++) {
        if (!materia[i]) {
            materia[i] = m;
            return;
        }
    }
    std::cout << "MateriaSource: No space to learn new materia." << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (materia[i] && materia[i]->getType() == type) {
            return materia[i]->clone();
        }
    }
    std::cout << "MateriaSource: No materia of type " << type << " found." << std::endl;
    return NULL;
}