#include <cstdlib>
#include <iostream>
#include <ctime>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "unistd.h"

Base* generate(void) {
	int randomNumber = rand() % 3;

	if (randomNumber == 0) {
		std::cout << "A class created\n";
		return (new A());
	}
	else if (randomNumber == 1) {
		std::cout << "B class created\n";
		return (new B());
	}
	else {
		std::cout << "C class created\n";
		return (new C());
	}
}

void identify(Base* p) {
	std::cout << "Identification by pointer : \n";
	if (dynamic_cast<A*>(p))
		std::cout << "A class identified\n";
	if (dynamic_cast<B*>(p))
		std::cout << "B class identified\n";
	if (dynamic_cast<C*>(p))
		std::cout << "C class identified\n";
}

void identify(Base& p) {

	std::cout << "Identification by reference : \n";
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A class identified\n";
		return ;
	}
	catch(const std::exception& e) {
		//
	}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B class identified\n";
		return ;
	}
	catch(const std::exception& e) {
		//
	}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C class identified\n";
		return ;
	}
	catch(const std::exception& e) {
		//
	}
	
}


int main(void)
{
	srand(time(0) * getpid());

	Base* randomClass = generate();

	identify(randomClass);
	delete(randomClass);
	return (1);
}