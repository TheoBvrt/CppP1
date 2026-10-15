#include "RPN.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2)
		return (0);

	RPN rpn(argv[1]);
	try
	{
		rpn.runRPN();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return (1);
}