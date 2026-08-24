#define BUREAUCRAT_HPP
# ifndef BREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include <exception>

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

		class GradeErrorException : public std::exception {
			virtual const char* what() const throw() {
				return "grade error (1 - 150)";
			}
		};

	private:
		int grade;
		const std::string name;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif