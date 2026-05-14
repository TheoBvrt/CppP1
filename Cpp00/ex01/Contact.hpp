#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact {
	private:
		int			index;
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
		std::string getColumnValue(std::string str);
	public:
		void setContact(int index, std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret);
		void displayContact();
};

#endif
