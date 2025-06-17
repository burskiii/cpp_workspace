#include "WrongCat.hpp"


WrongCat::WrongCat(): WrongAnimal("wrong cat")
{
	std::cout << "WrongCat default constructor" << std::endl;
}

WrongCat::WrongCat(std::string type): WrongAnimal(type)
{
	std::cout << "WrongCat parameterized constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other)
{
	type = other.type;
	std::cout << "Class WrongCat: " << other.type << " is copied!" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if(this != &other)
	{
		type = other.type;
	}
	std::cout << "Class WrongCat: " << type << " is assigned!" << std::endl;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "Class WrongCat: " << type << " make a sound: Meow Meow ..." << std::endl;
}