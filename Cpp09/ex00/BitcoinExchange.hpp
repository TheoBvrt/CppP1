#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <stdexcept>
# include <climits>

class BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void loadData(std::string dataFile);
		void convertPrice(std::string inputFile);

	private:
		std::map<std::string, double> piceHistory;
		
		void runConversion(std::string line);
		std::tm stringToDate(std::string);
		std::string checkDateFormat(std::string date);
		std::string checkValueFormat(std::string value);
};

#endif	