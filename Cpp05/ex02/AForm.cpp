#include "AForm.hpp"

AForm::AForm(std::string target, int gradeForSign, int gradeForExecute) : name(name), gradeForSign(gradeForSign), gradeForExecute(gradeForExecute) {
	this->isSigned = false;
}

AForm::~AForm() {

}

AForm::AForm(const AForm& other) : name(other.name), gradeForSign(other.gradeForSign), gradeForExecute(other.gradeForExecute) {
	*this = other;
}

AForm& AForm::operator=(const AForm& other) {
	if (this == &other)
		return *this;
	
	this->isSigned = other.isSigned;
	return *this;
}

std::string AForm::getName()	{
	return this->name;
}

int AForm::getGradeForSign() {
	return this->gradeForSign;
}

int AForm::getGradeForExecute() {
	return this->gradeForExecute;
}

bool AForm::getIsSigned() {
	return this->isSigned;
}

void AForm::beSigned(Bureaucrat& Bureaucrat) {
	if (Bureaucrat.getGrade() > this->gradeForSign)
		throw Bureaucrat::GradeTooLowException();
	else
		this->isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return ("Grade is too High!");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("Grade is too Low!");
}

std::ostream& operator<<(std::ostream &os, AForm& form) {
	os << "Name : " << form.getName() <<  " Grade for sign: " << form.getGradeForSign()
		<< " Required Grade for Execute : " << form.getGradeForExecute()
		<< " IsSigned : " << form.getIsSigned() << '\n';
	return (os);
}