#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Self conciousness loading..." << std::endl;
    std::cout << "  ^ ------ ^  " << std::endl;
    std::cout << " |  .    .  | " << std::endl;
    std::cout << " |    O    | " << std::endl;
    std::cout << "    ------   " << std::endl;

}

Brain::Brain(const Brain& other) {
    std::cout << "Brain copied!" << std::endl;
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = other.ideas[i];
    }
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain assigned!" << std::endl;
    if (this != &other)
        for (int i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    return *this;
}
Brain::~Brain() {
    std::cout << "Brain shutting down..." << std::endl;

}

