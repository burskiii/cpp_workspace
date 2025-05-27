#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    AAnimal* dog = new Dog();
    AAnimal* cat = new Cat();

    std::cout << "type is " << dog->getType() << std::endl;
    std::cout << "type is " << cat->getType() << std::endl;

    dog->makeSound();
    cat->makeSound();

    delete dog;
    delete cat;

    return 0;
}