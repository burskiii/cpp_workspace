#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat deployed!" << std::endl;
    this->brain = new Brain();
    this->type = "Cat";
}

Cat::Cat(const Cat& other) {
    std::cout << "Cat copy constructor called!" << std::endl;
    brain = new Brain(*other.brain);
    this->type = other.type;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Operator constructor called! " << std::endl;
    if (this != &other)
    {
        delete brain;
        brain = new Brain(*other.brain);
        this->type = other.type; 
    }
    return *this;
}
Cat::~Cat() {
    std::cout << "Cat left chat!" << std::endl;
    delete brain;
}

void Cat::makeSound() const {
    std::cout << this->type <<  " : Meow!" << std::endl;
}