#include "AAnimal.hpp"


AAnimal::AAnimal() : type("AAnimal")
{
    std::cout << "Animal default constructor called!" << std::endl;
}

AAnimal::AAnimal(std::string type) : type(type){
     std::cout << "Animal parameterized constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other){
    type = other.type;
    std::cout << "Animal Class" << other.type << " is copied! " << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other){
    if (this != &other)
        type = other.type;
    std::cout << "Animal Class: " << type << " is assigned!" << std::endl;
    return *this;
}

AAnimal::~AAnimal() {
    std::cout << "Animal destructor called!" << std::endl;
}

void AAnimal::makeSound() const {
    std::cout << "Animal Class : " << type << " made a sound!" << std::endl;
}

std::string AAnimal::getType() const {
    return this->type;
}


