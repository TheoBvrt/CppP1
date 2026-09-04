#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	Form form("Divorce", 140, 140);
	Bureaucrat Bureaucrat(150, "Mehdi");

	std::cout << form << std::endl;
	Bureaucrat.signForm(form);
}