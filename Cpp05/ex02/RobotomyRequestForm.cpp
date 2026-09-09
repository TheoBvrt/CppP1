#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request", 72, 45){
	this->target = target;
}

RobotomyRequestForm::~RobotomyRequestForm() {

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {
	*this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if(this != &other) {
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& bureaucrat) const {

	AForm::execute(bureaucrat);

	std::cout << "*some drilling noises*" << std::endl;

	if (std::rand() % 2 == 0)
		throw RobotomyFailedException();

	std::cout << "*[" << target << "] Robotomy has been successful!*" << std::endl;
	
}

const char* RobotomyRequestForm::RobotomyFailedException::what() const throw() {
	return ("Robotomy failed");
}
