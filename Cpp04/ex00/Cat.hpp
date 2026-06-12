#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat : public Animal {
	private:
	public:
		~Cat();
		Cat();
		Cat(const Cat& cat);
		Cat& operator=(const Cat& cat);
		void makeSound();
};

#endif