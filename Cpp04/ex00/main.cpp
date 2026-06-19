#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();


	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();

///////////////////

	// Dog dog;
	// Animal& a = dog;

	// Dog newDog = Dog();

	// newDog.makeSound();
	// a.makeSound();

///////////////////

	// Animal* animals[4];

	// animals[0] = new Dog();
	// animals[1] = new Cat();
	// animals[2] = new Dog();
	// animals[3] = new Cat();

	// for (int i = 0; i < 4; i++)
	// {
	// 	std::cout << animals[i]->getType() << std::endl;
	// 	animals[i]->makeSound();
	// }

	// for (int i = 0; i < 4; i++)
	// 	delete animals[i];

	return 0;
}