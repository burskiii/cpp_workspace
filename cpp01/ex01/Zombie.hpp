#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <sstream>

class Zombie
{
    public:
        void announce(void);
        void setName(std::string name);
        Zombie();
        Zombie(std::string name);
        ~Zombie();
    
    private:
        std::string name;
};

Zombie* zombieHorde( int N, std::string name );
std::string intToString(int n);

#endif

//TODO
//It must allocate N Zombie objects in a single allocation. Then, it must initialize the
//zombies, giving each of them the name passed as a parameter. The function returns a
//pointer to the first zombie
//TODO: check how to return the pointer to 
//the first zombie
