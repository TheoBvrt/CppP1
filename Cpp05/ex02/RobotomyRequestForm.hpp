#ifndef ROBOTOMOYREQUESTFORM_HPP
# define ROBOTOMOYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm{
	public:
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		void execute(Bureaucrat& bureaucrat) override;
	private:
		std::string target;
};

#endif