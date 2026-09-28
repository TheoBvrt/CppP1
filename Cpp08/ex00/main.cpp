#include "easyfind.hpp"
#include <iostream>
#include <map>

int main(void)
{
	std::vector<int> container;
	container.push_back(10);
	container.push_back(2);
	container.push_back(1); 


	try
	{
		std::vector<int>::iterator it = easyfind(container, 0);
		std::cout << *it;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	return 1;
}