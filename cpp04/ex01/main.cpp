#include "Animal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const int size = 100;  
    Animal *Animals[100];  
    
    std::cout << "<----- Single test --->" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;//should not create a leak
    delete i;

    std::cout << "<----- Multi test --->" << std::endl;
    for (int i = 0; i < size / 2; ++i)
    {
        Animals[i] = new Dog();
        std::cout << i << std::endl;
    }
    
    for (int i = size / 2; i < size; ++i)
    {  
        Animals[i] = new Cat();
        std::cout << i << std::endl;
    }
    std::cout << "\n<----- Deleting all animals --->\n" << std::endl;
    for (int i = 0; i < size; ++i)
    {
        delete Animals[i];
        std::cout << i << std::endl;
    }

    return 0;
}