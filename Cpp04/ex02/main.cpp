#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	//Animal annimal; ne marche pas

	// Animal animal;

	Cat cat;
	Dog dog;
	Animal* dog2 = new Dog();
	Animal* cat2 = new Cat();

	cat.makeSound();
	dog.makeSound();
	dog2->makeSound();
	cat2->makeSound();

	delete(dog2);
	delete(cat2);

	return 0;
}