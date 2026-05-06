#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	this->currentIndex = 0;
}

void PhoneBook::addContact()
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
}

void PhoneBook::search()
{
	int index;
	std::string line;

	std::cout << "enter index of the contact";
	std::getline(std::cin, line);
	index = std::atoi(line.c_str()) + 1;

	std::cout << index << std::endl;
}
