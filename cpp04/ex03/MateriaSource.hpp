#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

// #include "AMateria.hpp"
#include "IMateriaSource.hpp"

class IMateriaSource : public IMateriaSource
{
    public:

    private:
        void learnMateria(AMateria*);
        int createMateria(std::string const &);
};

#endif