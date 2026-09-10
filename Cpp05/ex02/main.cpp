#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	Bureaucrat mehdi(150, "Mehdi");

	ShrubberyCreationForm PresidentialPardonForm("Louis");

	std::srand(std::time(NULL));

	try
	{
		PresidentialPardonForm.beSigned(mehdi);
		mehdi.executeForm(PresidentialPardonForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 1;
}