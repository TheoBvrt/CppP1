#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
	private:
	protected:
		std::string type;
	public:
		virtual ~Animal();
		Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual void makeSound() const = 0;
		std::string getType() const;
};

#endif