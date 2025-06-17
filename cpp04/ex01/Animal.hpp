#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
    protected:
        std::string type;
    public:
        Animal();
        Animal(std::string type); //Parameterized constructor
        Animal(const Animal& other); // copy constructor
        Animal& operator=(const Animal& other);// copy assignment operator
        virtual ~Animal();

        virtual void makeSound() const;
        std::string getType() const;

} ;

#endif