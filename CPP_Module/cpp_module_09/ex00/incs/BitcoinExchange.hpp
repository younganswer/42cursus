#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include "Data.hpp"
# include <fstream>
# include <string>
# include <vector>

class BitcoinExchange {
	private:
		static std::vector<Data>	_db;

		BitcoinExchange(const BitcoinExchange &ref);
		BitcoinExchange	&operator=(const BitcoinExchange &rhs);
		
		static bool	openFile(std::ifstream &ifs, const std::string &filename);

	public:
		BitcoinExchange(void);
		~BitcoinExchange(void);

		// Util
		static bool	initializeDB(void) throw(std::exception);
		static bool	showDB(void);
		static bool	exchange(const std::string &filename);

		// Exception: FileOpenError
		class FileOpenError : public std::exception {
			private:
				std::string	_msg;

			public:
				FileOpenError(void);
				FileOpenError(const std::string &filename);
				virtual ~FileOpenError(void) throw();
				virtual const char *what(void) const throw();
		};
};

#endif