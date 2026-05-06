#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook phoneBook;
	std::string line;
	int	status = 1;

	std::cout << "\033[2J\033[1;1H------------------------\n| Welcome to PhoneBook |\n------------------------\n" << std::endl;
	while (1)
	{
		std::cout << "Please, use ADD, SEARCH or EXIT" << std::endl << " >> ";
		std::getline(std::cin, line);

		if (line == "EXIT")
			break ;
		else if (line == "ADD")
			status = phoneBook.addContact();
		else if (line == "SEARCH")
			status = phoneBook.search();
		else
			status = 0;
		std::cout << "\033[2J\033[1;1H";
		if (status == 0) {
			std::cout << "[error] - ";
			status = 1;
		}
	}
	return (0);
}
