#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Bureaucrat mehdi(1, "Mehdi");
	Intern intern;
	AForm *aform;


	try
	{
		aform = intern.makeForm("RobotomyRequestForM", "Mehdi");
		aform->beSigned(mehdi);
		aform->execute(mehdi);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return 1;
}