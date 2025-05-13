#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Dog deployed!" << std::endl;
    this->brain = new Brain();
    this->type = "Dog";
}

Dog::Dog(const Dog& other) {
    std::cout << "Dog copy constructor called!" << std::endl;
    brain = new Brain(*other.brain);
    this->type = other.type;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog copy operator called" << std::endl;
    if (this != &other)
    {
        delete brain;
        brain = new Brain(*other.brain);
        this->type = other.type;
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog left chat!" << std::endl;
    delete brain;
}

void Dog::makeSound() const {
    std::cout << this->type << " : Woof Woof!" << std::endl;
}
