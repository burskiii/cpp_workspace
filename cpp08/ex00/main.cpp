#include "easyfind.hpp"

int main()
{
	std::vector<int> vector;
	std::list<int> list;

	for (int i = 0; i < 20; i++)
	{
		vector.push_back(i);
		list.push_back(i);
	}

	::easyfind(vector, 9);
	::easyfind(list, 9);
	std::cout << "---------------" << std::endl;
	::easyfind(vector, 19);
	::easyfind(list, 19);
	std::cout << "---------------" << std::endl;
	::easyfind(vector, 21);
	::easyfind(list, 21);

	return (0);
}
