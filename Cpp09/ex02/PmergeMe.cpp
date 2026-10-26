
#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe& other)
	: vecTab(other.vecTab), deqTab(other.deqTab)
{

}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		vecTab = other.vecTab;
		deqTab = other.deqTab;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{

}

void PmergeMe::parseArg(char *argv[], int argc) {
	for (int i = 1; i < argc; i++)
	{
		std::string tmp = argv[i];
		std::istringstream ss(tmp);
		int value;
		ss >> value;

		this->vecTab.push_back(value);
		this->deqTab.push_back(value);
	}
}

void PmergeMe::sortAndDisplay() {
	std::vector<int>::iterator it;

	std::cout << "Before: ";
	for (it = this->vecTab.begin(); it != this->vecTab.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}