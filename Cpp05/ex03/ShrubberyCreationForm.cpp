#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("Shrubbery Creation", 145, 137),
      target(target)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other),
      target(other.target)
{

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& bureaucrat) const
{
    AForm::execute(bureaucrat);

    std::ofstream file((target + "_shrubbery").c_str());

    if (!file.is_open())
        throw std::runtime_error("Could not create shrubbery file");

	file << "       /\\\n";
	file << "      /  \\\n";
    file << "     /    \\\n";
    file << "    /      \\\n";
    file << "   /________\\\n";
    file << "      ||\n";
    file << "      ||\n";

    file.close();
}
