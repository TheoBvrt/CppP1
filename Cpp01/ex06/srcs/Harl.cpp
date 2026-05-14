#include "../headers/Harl.hpp"

void Harl::debug()
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
	info();
}

void Harl::info()
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	warning();
}

void Harl::warning()
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
	error();
}

void Harl::error()
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	std::string stringArray[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	index = 0;

	while (index != 5 && level != stringArray[index])
		index ++;
	switch (index)
	{
		case(0):
			debug();
			break;
		case(1):
			info();
			break;
		case(2):
			warning();
			break;
		case(3):
			error();
			break;
		default:
			std::cout << "[ Hmmm... problems ]" << std::endl;
			break;
	}
}