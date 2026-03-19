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
#include <cstdlib>

struct node {
    int value;
    int loserValue;
    bool hasLoser;
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
        void compareVecNodes(std::vector<node> &data, std::vector<node> &winners);
        void collectVecPending(std::vector<node> &data, const std::vector<node> &winners,
                       std::vector<node> &pending);
        void binaryInsertionVector(std::vector<node> &dest, const node &toInsert);
        void runVectorSort();
        
        // Deque
        std::deque<node> fordJohnsonSortDeque(std::deque<node> &data);
        void compareNodesDeque(std::deque<node> &data, std::deque<node> &winners);
        void collectDequePending(std::deque<node> &data, const std::deque<node> &winners,
                     std::deque<node> &pending);
        void binaryInsertionDeque(std::deque<node> &dest, const node &toInsert);
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
