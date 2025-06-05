#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class ICharacter;

class Cure : public AMateria{

    public:
        Cure();
        Cure(const Cure& other);
        Cure &operator=(const Cure& other);
        virtual ~Cure();
        virtual AMateria* clone() const;
        void use(ICharacter& target);
        void getName() const;
};

#endif