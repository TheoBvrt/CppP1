#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "invalid argument" << std::endl;
		return (0);
	}

	BitcoinExchange bitcoinExchange;

	try
	{
		bitcoinExchange.loadData("data.csv");
		bitcoinExchange.convertPrice(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return (1);
}
