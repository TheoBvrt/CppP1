#include "AForm.hpp"

AForm::AForm(std::string name, int gradeForSign, int gradeForExecute) : name(name), gradeForSign(gradeForSign), gradeForExecute(gradeForExecute) {
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

void AForm::execute(const Bureaucrat& bureaucrat) const {
	if (!this->isSigned)
		throw FormIsNotSigned();
	
	if (bureaucrat.getGrade() > this->gradeForExecute)
		throw GradeTooLowException();
}

std::string AForm::getName() const {
	return this->name;
}

int AForm::getGradeForSign() const {
	return this->gradeForSign;
}

int AForm::getGradeForExecute() const {
	return this->gradeForExecute;
}

bool AForm::getIsSigned() const {
	return this->isSigned;
}

void AForm::beSigned(Bureaucrat& Bureaucrat) {
	if (Bureaucrat.getGrade() > this->gradeForSign)
		throw Bureaucrat::GradeTooLowException();
	else
	{
		std::cout << Bureaucrat.getName() << " Signed the form" << std::endl;
		this->isSigned = true;
	}
}

const char *AForm::GradeTooHighException::what() const throw() {
	return ("Grade is too High!");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("Grade is too Low!");
}

const char *AForm::FormIsNotSigned::what() const throw() {
	return ("Form is not signed !");
}


std::ostream& operator<<(std::ostream &os, AForm& form) {
	os << "Name : " << form.getName() <<  " Grade for sign: " << form.getGradeForSign()
		<< " Required Grade for Execute : " << form.getGradeForExecute()
		<< " IsSigned : " << form.getIsSigned() << '\n';
	return (os);
}