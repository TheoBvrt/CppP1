#include "Form.hpp"

Form::Form(std::string name, int gradeForSign, int gradeForExecute) : name(name), gradeForSign(gradeForSign), gradeForExecute(gradeForExecute) {
	this->isSigned = false;
}

Form::~Form() {

}

Form::Form(const Form& other) : name(other.name), gradeForSign(other.gradeForSign), gradeForExecute(other.gradeForExecute) {
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

int Form::getGradeForSign() {
	return this->gradeForSign;
}

int Form::getGradeForExecute() {
	return this->gradeForExecute;
}

bool Form::getIsSigned() {
	return this->isSigned;
}

void Form::beSigned(Bureaucrat& Bureaucrat) {
	if (Bureaucrat.getGrade() > this->gradeForSign)
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
	os << "Name : " << form.getName() <<  " Grade for sign : " << form.getGradeForSign()
		<< " Grade for execute : " << form.getGradeForExecute()
		<< " IsSigned : " << form.getIsSigned() << '\n';
	return (os);
}