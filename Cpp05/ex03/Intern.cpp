#include "Intern.hpp"

Intern::Intern() {
	
}

Intern::Intern(const Intern &other) {
	(void)other;
}

Intern &Intern::operator=(const Intern &other) {
	(void)other;
	return (*this);
}

Intern::~Intern(){

}

AForm *Intern::createPresidentialForm(const std::string& target) const {
	return new PresidentialPardonForm(target);
}


AForm *Intern::createRobotomyForm(const std::string& target) const {
	return new RobotomyRequestForm(target);
}

AForm *Intern::createShrubberyForm(const std::string& target) const {
	return new ShrubberyCreationForm(target);
}

const char *Intern::UnknownFormException::what() const throw() {
	return ("Unknown Form Exception");
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) {
	int index = -1;
	
	std::string forms[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	AForm *(Intern::*createForm[])(const std::string &) const = {
		&Intern::createPresidentialForm, &Intern::createRobotomyForm, &Intern::createShrubberyForm
	};

	for (size_t i = 0; i < 3; i++) {
		if (equalsIgnoreCase(formName, forms[i])) {
			index = i;
			std::cout << "Intern creates " << forms[i] << std::endl;
			break;
		}
	}

	if (index == -1)
		throw UnknownFormException();
	
	return (this->*createForm[index])(target);
}

bool equalsIgnoreCase(std::string str1, std::string str2) {
	if (str1.length() != str2.length())
		return (false);
	
	for (size_t i = 0; i < str1.length(); i++)
	{
		if (std::tolower(str1[i]) != std::tolower(str2[i]))
			return (false);
	}
	return (true);
}


