#include "RPN.hpp"

RPN::RPN(std::string line) : stack() {
	this->line = line;
}

RPN::RPN(const RPN& other) : stack(other.stack) {}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
		this->stack = other.stack;
	return *this;
}

RPN::~RPN() {

}

void RPN::runRPN() {
	int tmp;
	size_t pos;
	std::istringstream iss(this->line);
	std::string token;

	while (iss >> token) {
		try
		{
			tmp = std::stoi(token, &pos); 
			if (pos != token.length() || token.length() != 1)
				throw std::runtime_error("Error");
			this->stack.push(tmp);
		}
		catch(const std::exception& e)
		{
			if (token.length() != 1 || (token[0] != '+' && token[0] != '*' && token[0] != '/' && token[0] != '-'))
				throw std::runtime_error("Error");

			if (this->stack.size() >= 2) {
				int nb1 = this->stack.top();
				this->stack.pop();

				int nb2 = this->stack.top();
				this->stack.pop();

				if (token == "*")
					this->stack.push(nb1 * nb2);
				else if (token == "+")
					this->stack.push(nb1 + nb2);
				else if (token == "-")
					this->stack.push(nb2 - nb1);
				else
				{
					if (nb1 == 0)
						throw std::runtime_error("Error");
					this->stack.push(nb2 / nb1);
				}
			}
		}
	}
	std::cout << "Resultat : " << this->stack.top() << std::endl;
}