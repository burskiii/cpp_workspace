#include "MutantStack.hpp"


int main()
{
	MutantStack<int> mstack;

    mstack.push(13);
    mstack.push(11);
	mstack.pop();
    mstack.push(8);
    mstack.push(4);
    mstack.push(6);
	mstack.push(7);
	mstack.push(12);

	 // Iterate through the stack using begin() and end()
    std::cout << "Stack iterator: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    // Iterate in reverse order using rbegin() and rend()
    std::cout << "Stack reverse iterator: ";
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
        std::cout << *rit << " ";
    std::cout << std::endl;

	return 0;
}
