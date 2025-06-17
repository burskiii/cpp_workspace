#include "Animal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


int main()
{    
    const Animal *AAnimals[10]; 
    int dog_count = 0;
    int cat_count = 0;
    
    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
        {
            dog_count++;
            std::cout << "Dog deploying..." << dog_count << std::endl;
            AAnimals[i] = new Dog();
            std::cout << std::endl;
        }
        else
        {
            cat_count++;
            std::cout << "Cat deploying..." << cat_count << std::endl;
            AAnimals[i] = new Cat();
            std::cout << std::endl;
        } 
    }

    for (int i = 0; i < 10; i++)
    {
        std::cout << "AAnimal " << i + 1 << " is a " << AAnimals[i]->getType() << std::endl;
        AAnimals[i]->makeSound();
        std::cout << std::endl;
    }

    for (int i = 0; i < 10; i++)
    {
        std::cout << "Deleting AAnimal[" << i + 1 << "]: "<< AAnimals[i]->getType() << std::endl;
        delete AAnimals[i];
        std::cout << std::endl;
    }
    
    //test 2:
    // Dog basic;
    // Dog tmp = basic;
    // std::cout << "tmp type: " << tmp.getType() << std::endl;
    // tmp.makeSound();
    return 0;
}