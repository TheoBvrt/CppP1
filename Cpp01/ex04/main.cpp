#include <fstream>
#include <iostream>
#include <string>

std::string replaceOccurence(std::string newFile, std::string s1, std::string s2)
{
	size_t pos = 0;

	while ((pos = newFile.find(s1, pos)) != std::string::npos)
	{
		newFile.erase(pos, s1.length());
		newFile.insert(pos, s2);
		pos += s2.length();
	}
	return (newFile);
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Use : ./a.out <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	std::ifstream file(argv[1]);
	std::string line;
	std::string newFile;

	while (std::getline(file, line))
	{
		newFile += line;
		newFile += "\n";
	}
	newFile = replaceOccurence(newFile, argv[2], argv[3]);

	std::ofstream replaceFile;
	std::string filename = argv[1];
	replaceFile.open((filename += ".replace").c_str());
	replaceFile << newFile;
	replaceFile.close();

	return (0);
}
