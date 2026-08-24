#include "Bureaucrat.hpp"

Bureaucrat::~Bureaucrat()throw() {

};

Bureaucrat::Bureaucrat(int grade, std::string name)
	: grade(grade), name(name)
{
	if (grade < 1 || grade > 150)
		throw Bureaucrat::GradeErrorException();
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

std::string Bureaucrat::getName() {
	return this->name;
}

void Bureaucrat::incrementGrade() {
	if (this->grade - 1 < 1)
		throw Bureaucrat::GradeErrorException();
	this->grade --;
}

void Bureaucrat::decrementGrade() {
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeErrorException();
	this->grade ++;
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getGrade();
	return (os);
}