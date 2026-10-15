#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
    : piceHistory(other.piceHistory)
{

}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        piceHistory = other.piceHistory;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{

}

void BitcoinExchange::loadData(std::string dataFile) {
	double doubleValue;
	std::string tmp;
	std::ifstream openedFile(dataFile);

	if (!openedFile.is_open())
		throw std::runtime_error("Erreur lors de l'ouverture du fichier " + dataFile);

	std::getline(openedFile, tmp);
	while (std::getline(openedFile, tmp)) {
		size_t comaPos = tmp.find(',');

		std::string date = tmp.substr(0, comaPos);
		std::string stringValue = tmp.substr(comaPos + 1, tmp.length());

		std::stringstream stringStream(stringValue);
		stringStream >> doubleValue;

		this->piceHistory.insert(std::make_pair(date, doubleValue));
	}
	openedFile.close();
}

void BitcoinExchange::convertPrice(std::string inputFile) {
	std::string line;
	std::ifstream openedFile(inputFile);

	if (!openedFile.is_open())
		throw std::runtime_error("Erreur lors de l'ouverture du fichier " + inputFile);
	
	while (std::getline(openedFile, line))
	{
		try
		{
			runConversion(line);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	openedFile.close();
}

void BitcoinExchange::runConversion(std::string line) {
	size_t sepPos = line.find('|');
	if (sepPos == std::string::npos)
		throw std::runtime_error("Error: bad input => " + line);

	if (sepPos == std::string::npos)
		return;

	std::string stringDate = line.substr(0, sepPos);
	std::string stringValue = line.substr(sepPos + 1, line.length());
	

	std::string date = checkDateFormat(stringDate);
	std::string value = checkValueFormat(stringValue);
	std::map<std::string, double>::iterator it = this->piceHistory.begin();
	std::tm dateToSearch = stringToDate(date);
	std::tm closestDate = stringToDate(it->first);
	double closestPrice = it->second;

	++it;
	while (it != this->piceHistory.end()) {
		std::tm tmp = stringToDate(it->first);
		std::time_t closedDateTs = std::mktime(&closestDate);
		std::time_t dateToSearchTs = std::mktime(&dateToSearch);
		std::time_t tmpDateTs = std::mktime(&tmp);


		double diff1 = std::difftime(closedDateTs, dateToSearchTs);
		double diff2 = std::difftime(tmpDateTs, dateToSearchTs);

		if (diff2 <= 0 && diff2 > diff1) {
			closestDate = tmp;
			closestPrice = it->second;
		}
		++it;
	}
	
	std::cout << date << " => " << value << " = " << std::stod(value) * closestPrice << std::endl;
}

std::tm BitcoinExchange::stringToDate(std::string date) {
	size_t firstPos = date.find('-');
	size_t secondPos = date.find('-', firstPos + 1);

	std::string elements[3] = {
		date.substr(0, firstPos),
		date.substr(firstPos + 1, secondPos - firstPos - 1),
		date.substr(secondPos + 1)
	};

	std::tm newDate = {};
	newDate.tm_year = std::stoi(elements[0]) - 1900;
	newDate.tm_mon = std::stoi(elements[1]) - 1;
	newDate.tm_mday = std::stoi(elements[2]);

	return (newDate);
}

std::string BitcoinExchange::checkDateFormat(std::string date) {
	if (std::count(date.begin(), date.end(), '-') != 2)
		throw std::runtime_error("Error: bad input => " + date);
	
	size_t firstPos = date.find('-');
	size_t secondPos = date.find('-', firstPos + 1);

	std::string elements[3] = {
		date.substr(0, firstPos),
		date.substr(firstPos + 1, secondPos - firstPos - 1),
		date.substr(secondPos + 1)
	};

	if (elements[1].length() != 2 || elements[2].length() != 3)
		throw std::runtime_error("Error: bad input => " + date);

	if (elements[2][2] != ' ')
		throw std::runtime_error("Error: bad input => " + date);

	elements[2].erase(2);
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t x = 0; x < elements[i].length(); x++)
		{
			if (!std::isdigit(elements[i][x]))
				throw std::runtime_error("Error: bad input => " + date);
		}
	}

	int year = std::stoi(elements[0]);
	int month = std::stoi(elements[1]);
	int day = std::stoi(elements[2]);

	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (month < 1 || month > 12)
		throw std::runtime_error("Error: bad input => " + date);

	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		daysInMonth[1] = 29;

	if (day < 1 || day > daysInMonth[month - 1])
		throw std::runtime_error("Error: bad input => " + date);

	date.erase(10);
	return (date);
}

std::string BitcoinExchange::checkValueFormat(std::string value) {

	if (value.length() < 2 || value[0] != ' ')
		throw std::runtime_error("Error: bad input => " + value);
	
	value.erase(0, 1);

	for (size_t i = 0; i < value.length(); i++)
	{
		if (!isdigit(value[i]) && value[i] != '.' && value[i] != '-')
			throw std::runtime_error("Error: bad input => " + value);
	}

	if (value[0] == '-')
		throw std::runtime_error("Error: not a positive number");

	
	size_t pos;
	double convertedValue = std::stod(value, &pos);
	if (pos != value.length())
		throw std::runtime_error("Error: bad input => " + value);

	
	if (convertedValue > 1000)
		throw std::runtime_error("Error: too large number");

	return (value);
}