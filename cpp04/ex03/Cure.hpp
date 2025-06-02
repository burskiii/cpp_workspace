#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMaterialSource{
    private:

    public:
        Cure();
        ~Cure();
        std::string getType(std::string name);
        std::string use(ICharacter& );
};

#endif