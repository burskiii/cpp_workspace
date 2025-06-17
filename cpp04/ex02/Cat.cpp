#include "Cat.hpp"

Cat::Cat() : AAnimal("cat") {
	brain = new Brain();
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(std::string type) : AAnimal(type) {
	brain = new Brain();
    std::cout << "Cat constructor is called, " << type << " is born!" << std::endl;
}

Cat::Cat(const Cat& other): AAnimal(other)
{
	if(this != &other)
	{
		type = other.type;
		brain = new Brain(*other.brain);
	}
	std::cout << "Class Cat: " << other.type << " is copied!" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if(this != &other)
	{
		type = other.type;
		delete brain;
		brain = new Brain(*other.brain); // Deep copy of the brain
	}
	std::cout << "Class Cat:  " << type << " is assigned!" << std::endl;
	return *this;
}

Cat::~Cat() {
	delete brain; // Free the allocated Brain memory
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << this->type <<  " : Meow!" << std::endl;
}