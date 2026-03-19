#include "PmergeMe.hpp" 

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "Usage: ./PmergeMe [numbers...]" << std::endl;
        return 1;
    }
    PmergeMe pmergeMe;
    pmergeMe.checkAndReadInput(ac, av);
    pmergeMe.runVectorSort();
    pmergeMe.runDequeSort();
    pmergeMe.printResults();

     return 0;
}