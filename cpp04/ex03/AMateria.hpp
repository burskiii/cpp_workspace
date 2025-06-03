#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class ICharacter;

class AMateria {

    protected:
       std::string type;
    public:
        AMateria(std::string const & type);
        virtual ~AMateria();
        std::string const & getType() const; //returns the material type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);

};

#endif