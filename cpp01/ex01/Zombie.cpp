#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie( std::string name )
{
    this->name = name;

}

Zombie::~Zombie()
{
    std::cout << this->name << ", you are out" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    this->name = name;
    std::cout << this->name << " is here" << std::endl;
    announce();
}