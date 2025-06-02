#ifnde ICHARACTER_HPP
#define ICHARACTER_HPP


#include <iostream>
// #include "AMateria.hpp"

class ICharacter
{
        virtual ~ICharacter() {}
    public:
        ICharacter();
        ~ICharacter();
        virtual void equip(AMateria* m) = 0;
        virtual std::string const & getName() const = 0;
        virtual void use(int idx, ICharacter& target) = 0;
        virtual void unequip(int idx) = 0;
};

#endif