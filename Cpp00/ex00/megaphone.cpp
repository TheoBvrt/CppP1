#include <iostream>

std::string ToUpperCase(std::string line) {
	for (size_t i = 0; i < line.length(); i++) {
		if (std::islower(line[i])) {
			line[i] = std::toupper(line[i]);
		}
	}
	return (line);
}

int	main(int argc, char *argv[]) {
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		for (int i = 0; i < argc; i++) {
			std::cout << ToUpperCase(argv[i]);
		}
		std::cout << std::endl;
	}
	return (0);
}
