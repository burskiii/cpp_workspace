#include "Animal.hpp"

Animal::Animal() : type("animal")
{
    std::cout << "Animal default constructor called!" << std::endl;
}

Animal::Animal(std::string type) : type(type){
     std::cout << "Animal parameterized constructor called" << std::endl;
}

Animal::Animal(const Animal& other){
    type = other.type;
    std::cout << "Animal Class" << other.type << " is copied! " << std::endl;
}

Animal& Animal::operator=(const Animal& other){
    if (this != &other)
        type = other.type;
    std::cout << "Animal Class: " << type << " is assigned!" << std::endl;
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destructor called!" << std::endl;
}

void Animal::makeSound() const {
    std::cout << "Animal Class : " << type << " made a sound!" << std::endl;
}

std::string Animal::getType() const {
    return this->type;
}


