#include <iostream>
#include "iter.hpp"
#include <cctype>

void print(const int& value)
{
	std::cout << value << std::endl;
}

void custom_toupper(std::string &target)
{
	for (size_t i = 0; i < target.length(); i++)
	{
		target[i] = std::toupper(target[i]);
	}
}

int main(void)
{
	int int_array[] = {10, 2, 123, 4};
	iter(int_array, 4, print);

	std::string string_array[] = {"bonjour", "hello", "theo", "mehdi"};
	iter(string_array, 4, custom_toupper);
	std::cout << string_array[0];

	return (1);
}