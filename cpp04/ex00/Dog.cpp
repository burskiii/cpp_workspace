#include "Dog.hpp"

Dog::Dog() : Animal("dog"){
    std::cout << "Dog default constructor called!" << std::endl;
}

Dog::Dog(std::string type): Animal(type)
{
	std::cout << "Dog constructor is called, " << type << " is born!" << std::endl;
}

Dog::Dog(const Dog& other): Animal(other)
{
    if (this != &other)
        type = other.type;
    std::cout << "Class Dog: " << other.type << " is copied!" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
        type = other.type;
    std::cout << "Class Dog: " << type << " is assigned!" << std::endl;
    return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << this->type << " : Woof Woof!" << std::endl;
}
