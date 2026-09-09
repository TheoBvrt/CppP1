#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include <exception>
# include "AForm.hpp"

class Bureaucrat {
	public:
		virtual ~Bureaucrat() throw();
		Bureaucrat(int grade, std::string name);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);

		std::string getName();
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		
		class GradeTooHighException : public std::exception {
			const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			const char *what() const throw();
		};

	private:
		int grade;
		const std::string name;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif