#include "Animal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


int main()
{    
    
    const Animal *Animals[10]; 
    int dog_count = 0;
    int cat_count = 0;
    
    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
        {
            dog_count++;
            std::cout << "Dog deploying..." << dog_count << std::endl;
            Animals[i] = new Dog();
            std::cout << std::endl;
        }
        else
        {
            cat_count++;
            std::cout << "Cat deploying..." << cat_count << std::endl;
            Animals[i] = new Cat();
            std::cout << std::endl;
        } 
    }

    for (int i = 0; i < 10; i++)
    {
        std::cout << "Animal " << i + 1 << " is a " << Animals[i]->getType() << std::endl;
        Animals[i]->makeSound();
        std::cout << std::endl;
    }

    for (int i = 0; i < 10; i++)
    {
        std::cout << "Deleting Animal[" << i + 1 << "]: "<< Animals[i]->getType() << std::endl;
        delete Animals[i];
    }

    return 0;
}