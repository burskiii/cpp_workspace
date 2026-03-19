#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <sys/time.h>
#include <sstream>
#include <iomanip>

struct node {
    int value;
    std::vector<int> loser;
};

class PmergeMe {
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        void checkAndReadInput(int ac, char **av);
        
        // Vector 
        std::vector<node> fordJohnsonSortVector(std::vector<node> &data);
        std::vector<int> generateJacobsthal(int n);
        void compareNodes(std::vector<node> &data, std::vector<node> &winners);
        void binaryInsertionVector(std::vector<node> &dest, node &toInsert);
        void runVectorSort();
        
        //deque
        std::deque<node> fordJohnsonSortDeque(std::deque<node> &data);
        // std::deque<int> generateJacobsthalOrderDeque(size_t n);
        void compareNodesDeque(std::deque<node> &data, std::deque<node> &winners);
        void binaryInsertionDeque(std::deque<node> &dest, node &toInsert);
        void runDequeSort();

        void printResults() const;

    private:
        std::string input;
        size_t inputSize; // size of the input sequence
        std::vector<node> vectorData;
        std::deque<node> dequeData;
        std::vector<node> vectorResult;
        std::deque<node> dequeResult;
        double vectorTime;
        double dequeTime;
};

#endif
