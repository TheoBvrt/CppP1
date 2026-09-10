#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <cctype>
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern();

		AForm *makeForm(const std::string &formName, const std::string &target);

		class UnknownFormException : public std::exception {
			const char *what() const throw();
		};
	private:
		AForm *createPresidentialForm(const std::string& target) const;
		AForm *createRobotomyForm(const std::string& target) const;
		AForm *createShrubberyForm(const std::string& target) const;
};

bool equalsIgnoreCase(std::string str1, std::string str2) ;

#endif
