#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	this->currentIndex = 0;
}

int PhoneBook::addContact()
{
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestString;

	std::cout << "First name : ";
	std::getline(std::cin, firstName);
	std::cout << "Last name : ";
	std::getline(std::cin, lastName);
	std::cout << "Nickname : ";
	std::getline(std::cin, nickName);
	std::cout << "Phone number : ";
	std::getline(std::cin, phoneNumber);
	std::cout << "Darkest secret : ";
	std::getline(std::cin, darkestString);

	contacts[currentIndex].setContact(
		currentIndex,
		firstName,
		lastName,
		nickName,
		phoneNumber,
		darkestString
	);

	if (currentIndex == 7)
		currentIndex = 0;
	else
		currentIndex ++;
	return (1);
}


int PhoneBook::search()
{
	int index;
	std::string line;
	
	std::cout << "\033[2J\033[1;1H enter index of the contact: ";
	std::getline(std::cin, line);

	if (line.length() != 1 || !isdigit(line[0])) {
		return (0);
	}

	index = std::atoi(line.c_str());

	if (index > 7)
		return (0);

	contacts[index].displayContact();
	return (1);
}
