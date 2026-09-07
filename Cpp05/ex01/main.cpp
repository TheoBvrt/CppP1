#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	Form form("Divorce", 150, 150);
	Bureaucrat Bureaucrat(150, "Mehdi");

	std::cout << form << std::endl;
	Bureaucrat.signForm(form);
}