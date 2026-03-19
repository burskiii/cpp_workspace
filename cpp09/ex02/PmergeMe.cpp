#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        this->input = other.input;
        this->inputSize = other.inputSize;
        this->vectorData = other.vectorData;
        this->dequeData = other.dequeData;
        this->vectorResult = other.vectorResult;
        this->dequeResult = other.dequeResult;
        this->vectorTime = other.vectorTime;
        this->dequeTime = other.dequeTime;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}


void PmergeMe::checkAndReadInput(int ac, char **av)
{
    for (int i = 1; i < ac; ++i)
    {
        std::string s = av[i];
        if (s. find_first_not_of("0123456789 ") != std::string::npos)
        {
            std::cout << "Error: Invalid character in input" << std::endl;
            exit(1);
        }

        std::stringstream ss(s);
        std::string temp;
        while (ss >> temp)
        {
            long value = std::atol(temp.c_str());
            if (value < 0 || value > 2147483647)
            {
                std::cout << "Error: Invalid number in input" << std::endl;
                exit(1);
            }

            node n;
            n.value = static_cast<int>(value);
            vectorData.push_back(n);
            dequeData.push_back(n);

        }
        //should return the size of ss? for the printresult?
        this->inputSize = vectorData.size();
    }
    //debug
    std::cout << "--- DEBUG: vectorData content ---" << std::endl;
    for (size_t i = 0; i < this->vectorData.size(); ++i)
        std::cout << "Element[" << i << "]: " << this->vectorData[i].value << std::endl;
    std::cout << "Total size: " << this->vectorData.size() << std::endl;
    std::cout << "--- End ---" << std::endl;

    std::cout << "--- DEBUG: dequeData content ---" << std::endl;
    for (size_t i = 0; i < this->dequeData.size(); ++i) 
        std::cout << "Element[" << i << "]: " << this->dequeData[i].value << std::endl;
    std::cout << "Total size: " << this->dequeData.size() << std::endl;
    std::cout << "--- End ---" << std::endl;    

}

void PmergeMe::compareNodes(std::vector<node> &data, std::vector<node> &winners)
{
    //data[0]vs[1], data[2]vs[3]...
    for (size_t i = 0; i + 1 < data.size(); i += 2)
    {
        if (data[i].value > data[i + 1].value)
        {
            winners.push_back(data[i]);
            winners.back().loser.push_back(data[i + 1].value);
        }
        else 
        {
            winners.push_back(data[i + 1]);
            winners.back().loser.push_back(data[i].value);
        }
    }
}

void PmergeMe::binaryInsertionVector(std::vector<node> &dest, node &toInsert) {

//find position
    int low = 0;
    int high = dest.size() - 1;
    while (low <= high) 
    {
        int mid = low + (high - low) / 2;
        if (dest[mid].value < toInsert.value)
            low = mid + 1;
        else
            high = mid - 1;
    }
    dest.insert(dest.begin() + low, toInsert);
}

std::vector<node> PmergeMe::fordJohnsonSortVector(std::vector<node> &data)
{
    if (data.size() <= 1) return data;

    std::vector<node> currentData = data;
    size_t n = currentData.size();

    bool hasstraggler = (n % 2 != 0);
    node straggler;
    if (hasstraggler)
    {
        straggler = currentData.back();
        currentData.pop_back();
    }
    
    std::vector<node> winners;
    compareNodes(currentData, winners); 
    
    std::vector<node> sortedWinners = fordJohnsonSortVector(winners);
    
    std::vector<node> pending;
    for (size_t i = 0; i < sortedWinners.size(); ++i)
    {
        if (!sortedWinners[i].loser.empty()) 
        {
            node p;
            p.value = sortedWinners[i].loser.back();
            // sortedWinners[i].loser.pop_back();
            p.loser.clear();
            pending.push_back(p);
        }
    }
    if (hasstraggler)
        pending.push_back(straggler);

    // if (!pending.empty())
    //     mainChain.insert(mainChain.begin(), pending[0]);

    // if (pending.empty()) return sortedWinners;

    std::vector<node> mainChain = sortedWinners;
    mainChain.insert(mainChain.begin(), pending[0]);
    
    std::vector<int> order = generateJacobsthal(pending.size());
    for (size_t i = 0; i < order.size(); ++i)
    {
        int index = order[i] - 1;   
        if (index <= 0 || index >= (int)pending.size())
            continue;
        binaryInsertionVector(mainChain, pending[index]);
    }
    return mainChain;
}

std::vector<int> PmergeMe::generateJacobsthal(int n)
{
    std::vector<int> order;
    if (n == 0)
        return order;

    std::vector<int> jacob;
    jacob.push_back(1); // J(1)
    jacob.push_back(3); // J(2)
    while(jacob.back() < (int)n)
    {
        jacob.push_back(jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2]);
    }

    int last = 1;
    for (size_t i = 0; i < jacob.size(); ++i)
    {
        int current = jacob[i];
        if (current > (int)n)
            current = n;
        for (int k = current; k > last; --k)
            order.push_back(k);
        last = current;
    }
    if (order.empty() || order[0] != 1)
        order.insert(order.begin(), 1);
    return order;
}

std::deque<node> PmergeMe::fordJohnsonSortDeque(std::deque<node> &data)
{
    if (data.size() <= 1) return data;

    std::deque<node> currentData = data;
    size_t n = currentData.size();

    bool hasstraggler = (n % 2 != 0);
    node straggler;
    if (hasstraggler) {
        straggler = currentData.back();
        currentData.pop_back();
    }
    
    std::deque<node> winners;
    compareNodesDeque(currentData, winners); 
    
    std::deque<node> sortedWinners = fordJohnsonSortDeque(winners);
    
    std::deque<node> pending;
    for (size_t i = 0; i < sortedWinners.size(); ++i) 
    {
        if (!sortedWinners[i].loser.empty()) 
        {
            node p;
            p.value = sortedWinners[i].loser.back();
            // sortedWinners[i].loser.pop_back();
            p.loser.clear();
            pending.push_back(p);
        }
    }
    if (hasstraggler)
        pending.push_back(straggler);

    // if (!pending.empty())
    //     mainChain.insert(mainChain.begin(), pending[0]);
    // if (pending.empty()) return sortedWinners;

    std::deque<node> mainChain = sortedWinners;
    mainChain.insert(mainChain.begin(), pending[0]);
    
    std::vector<int> order = generateJacobsthal(pending.size());
    for (size_t i = 0; i < order.size(); ++i) {
        int index = order[i] - 1;   
        if (index <= 0 || index >= (int)pending.size())
            continue;
        binaryInsertionDeque(mainChain, pending[index]);
    }
    return mainChain;
}


void PmergeMe::compareNodesDeque(std::deque<node> &data, std::deque<node> &winners)
{
    for (size_t i = 0; i + 1 < data.size(); i += 2)
    {
        if (data[i].value > data[i + 1].value)
        {
            winners.push_back(data[i]);
            winners.back().loser.push_back(data[i + 1].value);
        }
        else 
        {
            winners.push_back(data[i + 1]);
            winners.back().loser.push_back(data[i].value);
        }
    }
}

void PmergeMe::binaryInsertionDeque(std::deque<node> &dest, node &toInsert) 
{
    int low = 0;
    int high = dest.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (dest[mid].value < toInsert.value)
            low = mid + 1;
        else
            high = mid - 1;
    }
    dest.insert(dest.begin() + low, toInsert);
}


void PmergeMe::runVectorSort() 
{
    struct timeval start, end;
    gettimeofday(&start, NULL);

    this->vectorResult = fordJohnsonSortVector(this->vectorData);

    gettimeofday(&end, NULL);
    // 1sec = 1000000us
    this->vectorTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
}

void PmergeMe::runDequeSort() 
{
    struct timeval start, end;
    gettimeofday(&start, NULL);

    this->dequeResult = fordJohnsonSortDeque(this->dequeData);

    gettimeofday(&end, NULL);
    this->dequeTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
}

//calculate the time for vector and deque, and print the results
void PmergeMe::printResults() const 
{
    std::cout << "Before: ";
    for (size_t i = 0; i < vectorData.size(); ++i) {
        std::cout << vectorData[i].value << (i == vectorData.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;

    std::cout << "After:  ";
    for (size_t i = 0; i < dequeResult.size(); ++i) {
        std::cout << dequeResult[i].value << (i == dequeResult.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << vectorData.size() 
              << " elements with std::vector : " << std::fixed << std::setprecision(5) 
              << this->vectorTime << " us" << std::endl;

    std::cout << "Time to process a range of " << dequeData.size() 
              << " elements with std::deque  : " << std::fixed << std::setprecision(5) 
              << this->dequeTime << " us" << std::endl;
}