#include "Character.hpp"
#include "color.hpp"
#include <iostream>

Character::Character(const std::string& name) : name(name) {
    for (int i = 0; i < 4; ++i) {
        materia[i] = NULL;
    }
}

Character::Character(const Character& other)  {
    this->name = other.name;
	for (int i = 0; i < 4; i++) {
		if (other.materia[i])
			this->materia[i] = other.materia[i]->clone();
		else
			this->materia[i] = NULL;
	}
}


Character& Character::operator=(const Character& other) {
	std::cout << "Character copy assigment\n";
    if (this != &other) {
        this->name = other.name;
		this->deleteMateria();
		for (int i = 0; i < 4; i++) {
			if (this->materia[i])
			{
				if (other.materia[i] == NULL)
					this->materia[i] = NULL;
				else
					this->materia[i] = other.materia[i]->clone();
			}

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
			std::cout << YELLOW <<  "["<< m->getType() << "] [" << i << "] equipped." << RESET << std::endl;
            return;
        }
    }
	std::cout << RED <<  " XX--> Character: No space to equip new materia ["<< m->getType() << "] . <--XX " << RESET << std::endl;
	delete m; // Avoid memory leak if no space is available
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4) 
        return;
    materia[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4 || !materia[idx])
        return;

    std::cout << CYAN << name << " uses [" << materia[idx]->getType() 
              << "] on " << target.getName() << RESET << std::endl;

    materia[idx]->use(target);
}

void Character::printInventory() const {
    std::cout << BOLD << "Inventory of " << name << ":\n";
    for (int i = 0; i < 4; ++i) {
        if (materia[i])
            std::cout << " [" << i << "] " << materia[i]->getType() << "\n";
        else
            std::cout << " [" << i << "] <empty>\n";
    }
    std::cout << RESET;
}

void Character::deleteMateria() {
    for (int i = 0; i < 4; ++i) {
        if (materia[i]) {
            delete materia[i];
            materia[i] = NULL;
        }
    }
}

void Character::setName(const std::string& newName) {
	name = newName;
}
