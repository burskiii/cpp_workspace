#include "Cat.hpp"

Cat::Cat() : Animal("cat") {
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(std::string type) : Animal(type) {
      std::cout << "Cat constructor is called, " << type << " is born!" << std::endl;
}

Cat::Cat(const Cat& other): Animal(other)
{
	if(this != &other)
		type = other.type;
	std::cout << "Class Cat: " << other.type << " is copied!" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if(this != &other)
		type = other.type;
	std::cout << "Class Cat:  " << type << " is assigned!" << std::endl;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << this->type <<  " : Meow!" << std::endl;
}