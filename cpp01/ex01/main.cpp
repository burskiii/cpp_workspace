#include "Zombie.hpp"

int main()
{
    int N = 10;
    Zombie *zombie = zombieHorde(N, "Zombie_horde");
    
    delete[] zombie;
    return 0;
}