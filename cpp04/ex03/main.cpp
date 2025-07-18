#include <iostream>
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
   

    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("ice")); // 4th
    me->equip(src->createMateria("cure")); // 5th → should be ignored
   
    src->learnMateria(new Ice());
    src->learnMateria(new Ice());
    src->learnMateria(new Ice());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure()); // Should not be stored
    
    me->use(-1, *bob); // Should do nothing
    me->use(42, *bob); // Should do nothing

    AMateria* unknown = src->createMateria("fire"); // Should return nullptr
    if (!unknown)
        std::cout << "Unknown materia creation failed as expected." << std::endl;
   
    
    delete bob;
    delete me;
    delete src;

    //character equip() stress test
    ICharacter* testChar = new Character("testChar");
    AMateria* m1 = new Ice();
    AMateria* m2 = new Cure();
    AMateria* m3 = new Ice();
    AMateria* m4 = new Cure();
    AMateria* m5 = new Ice(); // the 5th materia

    testChar->equip(m1);
    testChar->equip(m2);
    testChar->equip(m3);
    testChar->equip(m4);
    testChar->equip(m5); // should be ignored

    testChar->use(-1, *testChar); // should do nothing
    testChar->use(10, *testChar); // should do nothing
    testChar->use(3, *testChar);  // should have output
    testChar->use(4, *testChar);  // should do nothing

    testChar->unequip(1);
    delete m2; // delete the unequipped materia
    testChar->use(1, *testChar);// should do nothing

    delete testChar;
    //test deep copy
    Character* original = new Character("original");
    original->equip(new Ice());
    original->equip(new Cure());

    Character* copy = new Character(*original); 

    std::cout << "== Use original ==" << std::endl;
    original->use(0, *original);
    original->use(1, *original);

    std::cout << "== Use copy ==" << std::endl;
    copy->use(0, *copy);
    copy->use(1, *copy);
    
    delete original;
    delete copy;
    return(0);
}