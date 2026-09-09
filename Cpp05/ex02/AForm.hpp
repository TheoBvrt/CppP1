#ifndef FORM_HPP
# define FORM_HPP

# include "iostream"
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	public:
		AForm(std::string name, int gradeForSign, int gradeForExecute);
		virtual ~AForm();
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);

		void beSigned(Bureaucrat& Bureaucrat);
		virtual void execute(const Bureaucrat& bureaucrat) const = 0;
		std::string getName() const;
		int getGradeForSign() const;
		int getGradeForExecute() const;
		bool getIsSigned() const;

		class GradeTooHighException : public std::exception {
			const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			const char *what() const throw();
		};

		class FormIsNotSigned : public std::exception {
			const char *what() const throw();	
		};

	private:
		const std::string name;
		bool isSigned;
		const int gradeForSign;
		const int gradeForExecute;
};

std::ostream& operator<<(std::ostream& os, AForm& form);

#endif