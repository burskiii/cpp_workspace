#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat deployed!" << std::endl;
    this->type = "Cat";
}

Cat::~Cat() {
    std::cout << "Cat left chat!" << std::endl;
}

void Cat::makeSound() const {
    std::cout << this->type <<  " : Meow!" << std::endl;
}