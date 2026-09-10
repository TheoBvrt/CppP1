#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("Presidential Pardon", 25, 5),
	  target(target)
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm::PresidentialPardonForm(
	const PresidentialPardonForm& other)
	: AForm(other),
	  target(other.target)
{

}

PresidentialPardonForm& PresidentialPardonForm::operator=(
	const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat& bureaucrat) const
{
	AForm::execute(bureaucrat);

	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
