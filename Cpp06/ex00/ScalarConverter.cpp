#include "ScalarConverter.hpp"
#include <cstring>

ScalarConverter::~ScalarConverter() {
	
}

ScalarConverter::ScalarConverter() {
	
}

ScalarConverter::ScalarConverter(const ScalarConverter& src) {
	(void)src;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return *this;
}

void ScalarConverter::convert(const std::string& literal) {
	if (literal.length() == 1 && !isdigit(literal[0])) {
		char c = literal[0];
		std::cout << "char: '" << c << "'\n";
		std::cout << "int: " << static_cast<int>(c) << "\n";
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f\n";
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << "\n";
		return;
	}


	char* end;
	double value = std::strtod(literal.c_str(), &end);

	std::cout << end << " " << value << std::endl; 
}