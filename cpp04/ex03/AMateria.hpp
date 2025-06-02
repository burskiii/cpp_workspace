#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class AMateriaSource {

    protected:
       
    public:
        AMateria(std::string const & type);

        std::string const & getType() const; //returns the material type
        virtual AMateria* clone() const = 0;
        virtual void use(int i, ICharacter& target);
        unequip();//must not delete material.

};

#endif