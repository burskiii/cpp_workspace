#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <stdexcept>
#include <ctime>
#include <sstream>

struct node {
    int value;
    std::vector<int> losers;
};

class PmergeMe {
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        void checkAndReadInput(int ac, char **av);
        // std::vector<node> fordJohnsonSortVector(std::vector<int> &winners);
        // std::deque<node> fordJohnsonSortDeque(std::deque<int> &deque);


    private:
        std::string input;
        std::vector<node> vectorData;
        std::deque<node> dequeData;
        // double vectorTime;
        // double dequeTime;
};

#endif
