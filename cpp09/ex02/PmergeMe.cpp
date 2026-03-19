#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : inputSize(0), vectorTime(0.0), dequeTime(0.0) {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        input = other.input;
        inputSize = other.inputSize;
        vectorData = other.vectorData;
        dequeData = other.dequeData;
        vectorResult = other.vectorResult;
        dequeResult = other.dequeResult;
        vectorTime = other.vectorTime;
        dequeTime = other.dequeTime;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::checkAndReadInput(int ac, char **av)
{
    vectorData.clear();
    dequeData.clear();

    for (int i = 1; i < ac; ++i)
    {
        std::string s = av[i];
        if (s.find_first_not_of("0123456789 ") != std::string::npos)
        {
            std::cout << "Error" << std::endl;
            exit(1);
        }

        std::stringstream ss(s);
        std::string token;
        while (ss >> token)
        {
            long value = std::atol(token.c_str());
            if (value <= 0 || value > 2147483647)
            {
                std::cout << "Error" << std::endl;
                exit(1);
            }

            node n;
            n.value = static_cast<int>(value);
            n.loserValue = 0;
            n.hasLoser = false;
            vectorData.push_back(n);
            dequeData.push_back(n);
        }
    }
    inputSize = vectorData.size();
}

void PmergeMe::compareVecNodes(std::vector<node> &data, std::vector<node> &winners)
{
    for (size_t i = 0; i + 1 < data.size(); i += 2)
    {
        node winner;
        if (data[i].value > data[i + 1].value)
        {
            winner.value = data[i].value;
            winner.loserValue = data[i + 1].value;
            winner.hasLoser = true;
        }
        else
        {
            winner.value = data[i + 1].value;
            winner.loserValue = data[i].value;
            winner.hasLoser = true;
        }
        winners.push_back(winner);
    }
}

void PmergeMe::collectVecPending(std::vector<node> &data, const std::vector<node> &winners,
                                 std::vector<node> &pending)
{
    for (size_t i = 0; i < winners.size(); ++i)
    {
        if (winners[i].hasLoser)
        {
            node p;
            p.value = winners[i].loserValue;
            p.loserValue = 0;
            p.hasLoser = false;
            pending.push_back(p);
        }
    }

    if (data.size() % 2 != 0)
    {
        node p;
        p.value = data.back().value;
        p.loserValue = 0;
        p.hasLoser = false;
        pending.push_back(p);
    }
}

void PmergeMe::binaryInsertionVector(std::vector<node> &dest, const node &toInsert)
{
    int low = 0;
    int high = static_cast<int>(dest.size()) - 1;

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
    if (data.size() <= 1)
        return data;

    std::vector<node> winners;
    std::vector<node> pending;
    winners.reserve((data.size() + 1) / 2);
    pending.reserve((data.size() + 1) / 2);

    for (size_t i = 0; i + 1 < data.size(); i += 2)
    {
        node big;
        node small;

        if (data[i].value > data[i + 1].value)
        {
            big = data[i];
            small = data[i + 1];
        }
        else
        {
            big = data[i + 1];
            small = data[i];
        }

        big.hasLoser = true;
        big.loserValue = small.value;
        winners.push_back(big);

        small.hasLoser = false;
        small.loserValue = 0;
        pending.push_back(small);
    }

    if (data.size() % 2 != 0)
    {
        node straggler = data.back();
        straggler.hasLoser = false;
        straggler.loserValue = 0;
        pending.push_back(straggler);
    }

    std::vector<node> mainChain = fordJohnsonSortVector(winners);
    if (pending.empty())
        return mainChain;

    std::vector<bool> inserted(pending.size(), false);
    std::vector<int> order = generateJacobsthal(static_cast<int>(pending.size()));
    for (size_t i = 0; i < order.size(); ++i)
    {
        int index = order[i] - 1;
        if (index < 0 || index >= static_cast<int>(pending.size()) || inserted[index])
            continue;
        binaryInsertionVector(mainChain, pending[index]);
        inserted[index] = true;
    }

    for (size_t i = 0; i < pending.size(); ++i)
    {
        if (!inserted[i])
            binaryInsertionVector(mainChain, pending[i]);
    }

    return mainChain;
}

std::vector<int> PmergeMe::generateJacobsthal(int n)
{
    std::vector<int> order;
    if (n == 0)
        return order;

    std::vector<int> jacob;
    jacob.push_back(1);
    jacob.push_back(3);
    while (jacob.back() < n)
    {
        jacob.push_back(jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2]);
    }

    int last = 1;
    for (size_t i = 0; i < jacob.size(); ++i)
    {
        int current = jacob[i];
        if (current > n)
            current = n;
        for (int k = current; k > last; --k)
            order.push_back(k);
        last = current;
    }

    if (order.empty() || order[0] != 1)
        order.insert(order.begin(), 1);
    return order;
}

void PmergeMe::compareNodesDeque(std::deque<node> &data, std::deque<node> &winners)
{
    for (size_t i = 0; i + 1 < data.size(); i += 2)
    {
        node winner;
        if (data[i].value > data[i + 1].value)
        {
            winner.value = data[i].value;
            winner.loserValue = data[i + 1].value;
            winner.hasLoser = true;
        }
        else
        {
            winner.value = data[i + 1].value;
            winner.loserValue = data[i].value;
            winner.hasLoser = true;
        }
        winners.push_back(winner);
    }
}

void PmergeMe::collectDequePending(std::deque<node> &data, const std::deque<node> &winners,
                                   std::deque<node> &pending)
{
    for (size_t i = 0; i < winners.size(); ++i)
    {
        if (winners[i].hasLoser)
        {
            node p;
            p.value = winners[i].loserValue;
            p.loserValue = 0;
            p.hasLoser = false;
            pending.push_back(p);
        }
    }

    if (data.size() % 2 != 0)
    {
        node p;
        p.value = data.back().value;
        p.loserValue = 0;
        p.hasLoser = false;
        pending.push_back(p);
    }
}

void PmergeMe::binaryInsertionDeque(std::deque<node> &dest, const node &toInsert)
{
    int low = 0;
    int high = static_cast<int>(dest.size()) - 1;

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

std::deque<node> PmergeMe::fordJohnsonSortDeque(std::deque<node> &data)
{
    if (data.size() <= 1)
        return data;

    std::deque<node> winners;
    std::deque<node> pending;

    for (size_t i = 0; i + 1 < data.size(); i += 2)
    {
        node big;
        node small;

        if (data[i].value > data[i + 1].value)
        {
            big = data[i];
            small = data[i + 1];
        }
        else
        {
            big = data[i + 1];
            small = data[i];
        }

        big.hasLoser = true;
        big.loserValue = small.value;
        winners.push_back(big);

        small.hasLoser = false;
        small.loserValue = 0;
        pending.push_back(small);
    }

    if (data.size() % 2 != 0)
    {
        node straggler = data.back();
        straggler.hasLoser = false;
        straggler.loserValue = 0;
        pending.push_back(straggler);
    }

    std::deque<node> mainChain = fordJohnsonSortDeque(winners);
    if (pending.empty())
        return mainChain;

    std::vector<bool> inserted(pending.size(), false);
    std::vector<int> order = generateJacobsthal(static_cast<int>(pending.size()));
    for (size_t i = 0; i < order.size(); ++i)
    {
        int index = order[i] - 1;
        if (index < 0 || index >= static_cast<int>(pending.size()) || inserted[index])
            continue;
        binaryInsertionDeque(mainChain, pending[index]);
        inserted[index] = true;
    }

    for (size_t i = 0; i < pending.size(); ++i)
    {
        if (!inserted[i])
            binaryInsertionDeque(mainChain, pending[i]);
    }

    return mainChain;
}

void PmergeMe::runVectorSort()
{
    struct timeval start;
    struct timeval end;

    gettimeofday(&start, NULL);
    vectorResult = fordJohnsonSortVector(vectorData);
    gettimeofday(&end, NULL);

    vectorTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
}

void PmergeMe::runDequeSort()
{
    struct timeval start;
    struct timeval end;

    gettimeofday(&start, NULL);
    dequeResult = fordJohnsonSortDeque(dequeData);
    gettimeofday(&end, NULL);

    dequeTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
}

void PmergeMe::printResults() const
{
     if(vectorData.size() == 0){
        return;
    }
    std::cout << "Before: ";
    for(std::vector<node>::const_iterator it = vectorData.begin(); it != vectorData.end(); ++it){
        std::cout << it->value << " ";
    }
    std::cout << std::endl;

    std::cout << "After: ";
    for(std::vector<node>::const_iterator it = vectorResult.begin(); it != vectorResult.end(); ++it){
        std::cout << it->value << " ";
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << vectorData.size() << " elements with std::vector : " 
        << std::fixed << std::setprecision(5) << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << dequeData.size() << " elements with std::deque : "
        << std::fixed << std::setprecision(5) << dequeTime << " us" << std::endl;
}
