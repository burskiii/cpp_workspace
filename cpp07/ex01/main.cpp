#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void printConst(const T& x)
{
    std::cout << x << std::endl;
}

void addOne(int& x)
{
    x += 1;
}

void toUpper(std::string& s)
{
    for (size_t i = 0; i < s.size(); ++i)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = static_cast<char>(s[i] - 'a' + 'A');
    }
}

int main()
{
    std::cout << "=== int array (modifiable) ===" << std::endl;
    int nums[] = {1, 2, 3, 4, 5};
    ::iter(nums, 5, addOne);               // modifies
    ::iter(nums, 5, printConst<int>);      // prints (template function)

    std::cout << "=== const int array (read-only) ===" << std::endl;
    const int cnums[] = {10, 20, 30};
    ::iter(cnums, 3, printConst<int>);     // ok

    std::cout << "=== string array (modifiable) ===" << std::endl;
    std::string words[] = {"apple", "banana", "strawberry"};
    ::iter(words, 3, toUpper);             // modifies
    ::iter(words, 3, printConst<std::string>);

    std::cout << "=== const string array (read-only) ===" << std::endl;
    const std::string cwords[] = {"const", "array"};
    ::iter(cwords, 2, printConst<std::string>);

    std::cout << "=== null safety ===" << std::endl;
    ::iter((int*)0, 3, addOne);            // should do nothing
    ::iter(nums, 5, (void(*)(int&))0);     // should do nothing

    return 0;
}
