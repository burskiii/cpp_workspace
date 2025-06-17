#include "Dog.hpp"

Dog::Dog() : AAnimal("dog"){
    brain = new Brain();
    std::cout << "Dog default constructor called!" << std::endl;
}

Dog::Dog(std::string type): AAnimal(type)
{
    brain = new Brain();
	std::cout << "Dog constructor is called, " << type << " is born!" << std::endl;
}

Dog::Dog(const Dog& other): AAnimal(other)
{
    if (this != &other)
    {
        type = other.type;
        brain = new Brain(*other.brain); // Deep copy of the brain
    }
    std::cout << "Class Dog: " << other.type << " is copied!" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        type = other.type;
        delete brain; // Free existing memory
        brain = new Brain(*other.brain); // Deep copy of the brain
    }
    std::cout << "Class Dog: " << type << " is assigned!" << std::endl;
    return *this;
}

Dog::~Dog() {
    delete brain; // Free the allocated Brain memory
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << this->type << " : Woof Woof!" << std::endl;
}
