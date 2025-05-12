#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* j = new Dog();
const Animal* i = new Cat();
const WrongAnimal* wrong = new WrongCat();

std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
std::cout << wrong->getType() << " " << std::endl;

i->makeSound(); //will output the cat sound!
j->makeSound();
wrong->makeSound();

delete j;
delete i;
delete wrong;

return 0;
}
