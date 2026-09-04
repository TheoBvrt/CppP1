#include "Form.hpp"

Form::Form(std::string name, int grade, int requiredGrade) : name(name), grade(grade), requiredGrade(requiredGrade) {
	this->isSigned = false;
}

Form::~Form() {

}

Form::Form(const Form& other) : name(other.name), grade(other.grade), requiredGrade(other.requiredGrade) {
	*this = other;
}

Form& Form::operator=(const Form& other) {
	if (this == &other)
		return *this;
	
	this->isSigned = other.isSigned;
	return *this;
}

std::string Form::getName()	{
	return this->name;
}

int Form::getGrade() {
	return this->grade;
}

int Form::getRequiredGrade() {
	return this->requiredGrade;
}

bool Form::getIsSigned() {
	return this->isSigned;
}

void Form::beSigned(Bureaucrat& Bureaucrat) {
	if (Bureaucrat.getGrade() > this->requiredGrade)
		throw Bureaucrat::GradeTooLowException();
	else
		this->isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("Grade is too High!");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Grade is too Low!");
}

std::ostream& operator<<(std::ostream &os, Form& form) {
	os << "Name : " << form.getName() <<  " Grade : " << form.getGrade()
		<< " Required Grade : " << form.getRequiredGrade()
		<< " IsSigned : " << form.getIsSigned() << '\n';
	return (os);
}