#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateriaSource{
    Private:
    
    public:
        Ice();
        ~Ice();
        std::string getType(std::string name);
        std::string use(ICharacter& );
};

#endif