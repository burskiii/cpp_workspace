#include "MateriaSource.hpp"
#include "color.hpp"
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
    std::cout << RED << " XX-->MateriaSource: No space to learn new materia [" <<  m->getType()  << " ]. <--XX" << RESET << std::endl;
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (materia[i] && materia[i]->getType() == type) {
            return materia[i]->clone();
        }
    }
    std::cout << RED << "XX-->MateriaSource: No materia of type of [ " << type << " ] found. <--XX" << RESET << std::endl;
	return NULL;
}
