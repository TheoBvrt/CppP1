#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <cstdlib>
#include "Contact.hpp"

class PhoneBook {
	private:
		int		currentIndex;
		Contact contacts[8];
	public:
		PhoneBook();
		int addContact();
		int search();
};

#endif
