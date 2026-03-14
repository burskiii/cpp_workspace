#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        this->input = other.input;
        this->vectorData = other.vectorData;
        this->dequeData = other.dequeData;
        // this->vectorTime = other.vectorTime; --- IGNORE ---
        // this->dequeTime = other.dequeTime; --- IGNORE ---
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

std::vector<node> PmergeMe::fordJohnsonSortVector(std::vector<node> &data)
{
    if (data.size() <= 1) 
        return data;

    

}
