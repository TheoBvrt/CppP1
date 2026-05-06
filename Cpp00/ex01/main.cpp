#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook phoneBook;

	while (1)
	{
		std::string line;
		std::getline(std::cin, line);

		if (line == "EXIT")
			break ;
		else if (line == "ADD")
			phoneBook.addContact();
		else if (line == "SEARCH")
			phoneBook.search();
		else
			std::cout << "Please use ADD, SEARCH or EXIT!" << std::endl;
	}
	return (0);
}
