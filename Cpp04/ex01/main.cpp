#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// Animal* animals[4];

	// animals[0] = new Dog();
	// animals[1] = new Dog();
	// animals[2] = new Cat();
	// animals[3] = new Cat();

	// for (int i = 0; i < 4; i++)
	// {
	// 	animals[i]->makeSound();
	// }

	// for (int i = 0; i < 4; i++)
	// 	delete animals[i];

	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	// delete j;//should not create a leak
	// delete i;
	// return 0;

	
	//deep copy

	// Cat c1;
	// Cat c2;

	// c1.getBrain()->ideas[0] = "Super";
	// std::cout << c1.getBrain()->ideas[0] << std::endl;

	// c2 = c1;
	// std::cout << c2.getBrain()->ideas[0] << std::endl;
	// c1.getBrain()->ideas[0] = "Super2";

	// std::cout << c2.getBrain()->ideas[0] << std::endl;
	// std::cout << c1.getBrain()->ideas[0] << std::endl;


	
	
	// Dog d1;
	// Dog d2;

	// d1.getBrain()->ideas[0] = "Super";
	// std::cout << d1.getBrain()->ideas[0] << std::endl;

	// d2 = d1;
	// std::cout << d2.getBrain()->ideas[0] << std::endl;
	// d1.getBrain()->ideas[0] = "Super2";

	// std::cout << d2.getBrain()->ideas[0] << std::endl;
	// std::cout << d1.getBrain()->ideas[0] << std::endl;



	// Cat c1;

	// c1.getBrain()->ideas[0] = "hello";

	// Cat c2 = c1;
	// std::cout << c2.getBrain()->ideas[0] << std::endl;

	return 0;
}