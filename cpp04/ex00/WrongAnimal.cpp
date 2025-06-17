#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal():type("wrong animal")
{
	std::cout << "WrongAnimal default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type): type(type)
{
	std::cout << "WrongAnimal parameterized constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	type = other.type;
	std::cout << "Class WrongAnimal: " << other.type << " is copied!" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if(this != &other)
	{
		type = other.type;
	}

	std::cout << "Class WrongAnimal: " << type << " is assigned!" << std::endl;
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Class WrongAnimal: " << type << " makes a sound!" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return type;
}