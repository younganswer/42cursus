#include "../incs/BitcoinExchange.hpp"
#include "../incs/DataBase.hpp"
#include <iostream>
#include <sstream>

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " <file>" << std::endl;
		return (1);
	}

	try {
		std::cout << std::fixed << std::setprecision(2);
		BitcoinExchange::exchange(argv[1]);
	} catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}