#ifndef AAnimal_HPP
#define AAnimal_HPP

#include <iostream>

class AAnimal {
    protected:
        std::string type;
    public:
        AAnimal();
        AAnimal(std::string type); //Parameterized constructor
        AAnimal(const AAnimal& other); // copy constructor
        AAnimal& operator=(const AAnimal& other);// copy assignment operator
        virtual ~AAnimal();

        virtual void makeSound() const = 0;
        std::string getType() const;

} ;

#endif