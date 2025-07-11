#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain default constructor" << std::endl;
}

Brain::Brain(const Brain& other) {
    std::cout << "Brain copy constructor " << std::endl;
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = other.ideas[i];
    }
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain assignation operator called " << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destructor called " << std::endl;
}

