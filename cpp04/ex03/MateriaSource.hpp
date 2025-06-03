#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include <string>

class MateriaSource : public IMateriaSource
{
    private:
        AMateria* prototype[4];
    public:
        MateriaSource();
        ~MateriaSource();
        MateriaSource(const MateriaSource& other);
        MateriaSource& operator=(const MateriaSource& other);
        virtual AMateria* createMateria(std::string const & type) override;
        virtual void learnMateria(AMateria*) override;
};

#endif