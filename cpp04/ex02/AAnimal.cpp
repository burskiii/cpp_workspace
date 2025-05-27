#include "AAnimal.hpp"

AAnimal::AAnimal()
{
    std::cout << "Animal Manager comes!" << std::endl;
}

AAnimal::~AAnimal() {
    std::cout << "Animal Manager left!" << std::endl;
}

std::string AAnimal::getType() const {
    return this->type;
}

void AAnimal::makeSound() const {}


