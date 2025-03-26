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
