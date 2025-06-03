#ifndef ICE_HPP
#define ICE_HPP

#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class ICharacter;

class Ice : public AMateria {
    public:
        Ice();
        ~Ice();
        Ice(const Ice& other);
        Ice &operator=(const Ice& other);
        virtual AMateria* clone() const override;
        void use(ICharacter& target);
};

#endif