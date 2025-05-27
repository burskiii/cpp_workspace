#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    std::cout << "Wrong animal sneak in!" << std::endl;
    this->type = "WRONG ANIMAL";
}

WrongAnimal::~WrongAnimal() {
    std::cout << "Wrong animal left chat!" << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << this->type << " : WRONG ANIMAL!" << std::endl;
}
std::string WrongAnimal::getType() const {
    return this->type;
}
