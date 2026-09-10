#ifndef ROBOTOMOYREQUESTFORM_HPP
# define ROBOTOMOYREQUESTFORM_HPP

#include "AForm.hpp"
#include "cstdlib"

class RobotomyRequestForm : public AForm{
	public:
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		void execute(const Bureaucrat& bureaucrat) const;

		class RobotomyFailedException : public std::exception {
			const char *what() const throw();
		};
	private:
		std::string target;
};

#endif