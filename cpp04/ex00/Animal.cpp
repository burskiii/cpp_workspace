#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal Manager comes!" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal Manager left!" << std::endl;
}

std::string Animal::getType() const {
    return this->type;
}

void Animal::makeSound() const {}


