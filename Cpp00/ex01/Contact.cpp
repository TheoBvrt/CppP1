#include "Contact.hpp"

Contact::Contact() {
	this->index = -1;
}

int Contact::getIndex() {
	return this->index;
}

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
	return str;
}

void Contact::displayContact()
{
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|"
			<< std::setw(10) << this->index
			<< "|"
			<< std::setw(10) << getColumnValue(this->firstName)
			<< "|"
			<< std::setw(10) << getColumnValue(this->lastName)
			<< "|"
			<< std::setw(10) << getColumnValue(this->nickName)
			<< "|"
			<< std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "press key to continue:" << std::endl;
	std::cin.get();
}