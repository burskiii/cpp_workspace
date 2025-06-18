#ifndef CHARACTER_HPP
#define CHARACTER_HPP


#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
   
    public:
        Character(const std::string& name);
        Character(const Character& other);
        Character& operator=(const Character& other);
        virtual ~Character();
        virtual std::string const & getName() const;

        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);
		void printInventory() const;
   
    private:
        std::string name;
        AMateria* materia[4];
};

#endif
