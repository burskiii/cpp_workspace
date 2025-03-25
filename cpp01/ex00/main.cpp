#include "Zombie.hpp"

int main()
{
    Zombie *Zombie1 = newZombie("Zombie_heap1");
    Zombie1->announce();
    Zombie *Zombie2 = newZombie("Zombie_heap2");
    Zombie2->announce();
    Zombie *Zombie3 = newZombie("Zombie_heap3");
    Zombie3->announce();
    Zombie *Zombie4 = newZombie("Zombie_heap4");
    Zombie4->announce();

    randomChump("Zombie_stack5");
    randomChump("Zombie_stack6");
    randomChump("Zombie_stack7");
    randomChump("Zombie_stack8");

    delete Zombie1;
    delete Zombie2;
    delete Zombie3;
    delete Zombie4;

    return 0;
}