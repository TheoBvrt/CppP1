#include "Contact.hpp"

void Contact::setContact(int index, std::string firstName, std::string lastName,
	std::string nickName, std::string phoneNumber, std::string darkestSecret)
{
	this->index = index;
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickName = nickName;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
}

std::string Contact::getColumnValue(std::string str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";

	return std::string(10 - str.length(), ' ') + str;
}

void Contact::displayContact()
{
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|         "
		<< this->index
		<< "|" << getColumnValue(this->firstName)
		<< "|" << getColumnValue(this->lastName)
		<< "|" << getColumnValue(this->nickName)
		<< "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "press key to continue:" << std::endl;
	std::cin.get();
}