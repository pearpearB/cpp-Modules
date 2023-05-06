#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <sstream>
#include <fstream>
#include <cctype>
#include <map>

#define FILEOPEN_ERROR "Error: could not open file."

class BitcoinExchange
{
	private:
		std::pair<std::string, float> data;
		std::map<std::string, float> _data;
		std::string _dataFilename;
		std::string _targetFilename;

		std::map<std::string, float> parseData(std::string filename);
		std::pair<std::string, float> parseTargetLine(std::string line);

		std::string checkValidDate(std::string date);
		float checkValidValue(std::string value);

		void printResult(std::pair<std::string, float> data);

	public:
		BitcoinExchange(char *target, std::string data);
		BitcoinExchange(const BitcoinExchange &ref);
		~BitcoinExchange();
		BitcoinExchange &operator=(const BitcoinExchange &ref);

		std::map<std::string, float> get_Data() const;
		std::pair<std::string, float> getData() const;

		void execute();
};

// std::ostream &operator<<(std::ostream &o, std::map<std::string, float> const &rhs);

#endif
