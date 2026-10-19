#include "PmergeMe.hpp"

bool argsIsValid(char *argv[])
{
}
int main(int argc, char *argv[])
{
	if (argc < 1 || !argsIsValid(argv)) {
		std::cout << "Error\n";
		return(0);
	}
	return (1);
}