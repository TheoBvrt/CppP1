#include "ScalarConverter.hpp"
#include <cstring>
#include <climits>

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

	if (literal == "nan" || literal == "nanf") {
		std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n";
		return;
	}
	if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff") {
		std::cout << "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf\n";
		return;
	}
	if (literal == "-inf" || literal == "-inff") {
		std::cout << "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n";
		return;
	}

	char* end;
	double value = std::strtod(literal.c_str(), &end);

	if (*end == '\0' || (*end == 'f' && *(end + 1) == '\0')) {
		if (value < 0 || value > 127) {
			std::cout << "char: non displayable" << std::endl;
		} else {
			char c = static_cast<char>(value);
			if (std::isprint(c)) {
				std::cout << "char: '" << c << "'\n";
			} else {
				std::cout << "char: non displayable" << std::endl;
			}
		}
		
		if (value < INT_MIN || value > INT_MAX) {
			std::cout << "int: impossible" << std::endl;
		} else {
			std::cout << "int: " << static_cast<int>(value) << "\n";
		}
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f\n";
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << "\n";
		return;
	}

	std::cout << "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n";
}