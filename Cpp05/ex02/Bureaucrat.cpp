#include "Bureaucrat.hpp"

Bureaucrat::~Bureaucrat()throw() {

};

Bureaucrat::Bureaucrat(int grade, std::string name)
	: grade(grade), name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if ( grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this == &other)
		return *this;
	
	this->grade = other.grade;
	return *this;
}

int Bureaucrat::getGrade() const {
	return this->grade;}

std::string Bureaucrat::getName() const {
	return this->name;
}

void Bureaucrat::incrementGrade() {
	if (this->grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade --;
}

void Bureaucrat::decrementGrade() {
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade ++;
}

void Bureaucrat::executeForm(AForm const& form) const {
	try
	{
		std::cout << this->name << " executed " << form.getName();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << this->name << " couldn't execute " << form.getName() << std::endl;
	}
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getGrade();
	return (os);
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too High!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too Low!");
}