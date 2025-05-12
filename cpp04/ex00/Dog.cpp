#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Dog deployed!" << std::endl;
    this->type = "Dog";
}

Dog::~Dog() {
    std::cout << "Dog left chat!" << std::endl;
}

void Dog::makeSound() const {
    std::cout << this->type << " : Woof Woof!" << std::endl;
}
