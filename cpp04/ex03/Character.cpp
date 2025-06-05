#include "Character.hpp"
#include <iostream>

Character::Character(const std::string& name) : name(name) {
    for (int i = 0; i < 4; ++i) {
        materia[i] = nullptr;
    }
}

Character::Character(const Character& other) : name(other.name) {
    for (int i = 0; i < 4; ++i) {
        if (other.materia[i])
            materia[i] = other.materia[i]->clone();
        else
            materia[i] = nullptr;
    }
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        name = other.name;
        for (int i = 0; i < 4; ++i) {
            delete materia[i];
            materia[i] = nullptr;
        }
        for (int i = 0; i < 4; ++i) {
            if (other.materia[i])
                materia[i] = other.materia[i]->clone();
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
    materia[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4) 
        return;
    if (materia[idx]) {
        materia[idx]->use(target);
    }
}