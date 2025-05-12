#include "WrongCat.hpp"

WrongCat::WrongCat() {
    std::cout << "Wrong cat sneak in!" << std::endl;
    this->type = "WRONG CAT";
}

WrongCat::~WrongCat() {
    std::cout << "Wrong cat left chat!" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << this->type << " : WRONG CAT!" << std::endl;
}
