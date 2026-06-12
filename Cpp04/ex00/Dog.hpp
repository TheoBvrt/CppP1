#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <iostream>

class Dog : public Animal {
	private:
	public:
		~Dog();
		Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		void makeSound();
};

# endif