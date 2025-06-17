#include "Character.hpp"
#include <iostream>

Character::Character(const std::string& name) : name(name) {
    for (int i = 0; i < 4; ++i) {
        materia[i] = NULL;
    }
}

Character::Character(const Character& other)  {
    this->name = other.name;
    for (int i = 0; i < 4; ++i) {
        if (other.materia[i])
            this->materia[i] = other.materia[i]->clone(); //deep copy
        else
            this->materia[i] = NULL;
    }
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        this->name = other.name;
		for (int i = 0; i < 4; i++) {
			if (this->materia[i])
				delete this->materia[i];
		
			if (other.materia[i])
				this->materia[i] = other.materia[i]->clone();
			else
				this->materia[i] = NULL;
        }
    }
    return *this;
}

Character::~Character() {
    for (int i = 0; i < 4; ++i) {
        delete materia[i];
    }
}

std::string const & Character::getName() const {
    return name;
}

void Character::equip(AMateria* m) {
    if (!m) return;
    for (int i = 0; i < 4; ++i) {
        if (!materia[i]) {
            materia[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4) 
        return;
    materia[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4) 
        return;
    if (materia[idx]) {
        materia[idx]->use(target);
    }
}