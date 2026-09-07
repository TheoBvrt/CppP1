#include "Bureaucrat.hpp"

int main() {
	try
	{
		Bureaucrat Bureaucrat(150, "Mehdi");
		std::cout << Bureaucrat << std::endl;
		try
		{
			//Bureaucrat.incrementGrade();
			Bureaucrat.decrementGrade();
			std::cout << Bureaucrat << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << "Exception catched " << e.what() << std::endl;
		}
	} 
	catch (std::exception & e)
	{
		std::cout << "Exception catched" << std::endl;
	}
}