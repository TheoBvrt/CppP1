#ifndef FORM_HPP
# define FORM_HPP

# include "iostream"
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	public:
		Form(std::string name, int grade, int requiredGrade);
		~Form();
		Form(const Form& other);
		Form& operator=(const Form& other);

		void beSigned(Bureaucrat& Bureaucrat);
		std::string getName();
		int getGrade();
		int getRequiredGrade();
		bool getIsSigned();

		class GradeTooHighException : public std::exception {
			const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			const char *what() const throw();
		};

	private:
		const std::string name;
		bool isSigned;
		const int grade;
		const int requiredGrade;
};

#endif