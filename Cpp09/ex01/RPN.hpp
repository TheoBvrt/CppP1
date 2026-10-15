#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <sstream>
# include <string>
# include <stdexcept>


class RPN {
	public:
		RPN(std::string line);
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		void runRPN();
	private:
		std::stack<int> stack;
		std::string line;
};

#endif