#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(char *target, std::string data) : _dataFilename(data), _targetFilename(target) {
	this->_data = parseData(_dataFilename);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &ref) {
	*this = ref;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &ref) {
	if (this != &ref) {
		this->_data = ref._data;
		this->_dataFilename = ref._dataFilename;
		this->_targetFilename = ref._targetFilename;
	}
	return *this;
}

std::map<std::string, float> BitcoinExchange::parseData(std::string filename) {
	std::map<std::string, float> data;
	std::ifstream ifs;
	std::string buf;

	ifs.open(filename);
	if (!ifs) {
		std::cout << FILEOPEN_ERROR << std::endl;
		exit (EXIT_FAILURE);
	}

	std::getline(ifs, buf);
	while (std::getline(ifs, buf)) {
		size_t pos = buf.find(",");
    std::string date = buf.substr(0, pos);
    std::string value = buf.substr(pos + 1);

		data[date] = std::stof(value);
	}

	ifs.close();
	return data;
}

std::pair<std::string, float> BitcoinExchange::parseTargetLine(std::string line) {
	size_t pos = line.find(" | ");

	if (pos == std::string::npos)
		throw std::invalid_argument("1bad input => " + line);

	std::string date = checkValidDate(line.substr(0, pos));
	float value = checkValidValue(line.substr(pos + 3));

	return std::pair<std::string, float>(date, value);
}

std::string BitcoinExchange::checkValidDate(std::string date) {
	if (date.length() != 10)
		throw std::invalid_argument("2bad input => " + date);
	if (date[4] != '-' || date[7] != '-')
		throw std::invalid_argument("3bad input => " + date);
	if(stoi(date.substr(5, 2)) > 12 || stoi(date.substr(8, 2)) > 31)
		throw std::invalid_argument("4bad input => " + date);
	return date;
}

float BitcoinExchange::checkValidValue(std::string value) {
	if (value.length() == 0)
		throw std::invalid_argument("5bad input => " + value);
	
	size_t dotPos = value.find(".");
	if (value.find(".", dotPos + 1) != std::string::npos)
		throw std::invalid_argument("6bad input => " + value);
	
	size_t minusPos = value.find("-");
	if (minusPos != std::string::npos && minusPos != 0)
		throw std::invalid_argument("7bad input => " + value);

	for (size_t i = 0; i < value.length(); i++) {
		if (i == dotPos)
			continue ;
		if (i == minusPos)
			continue ;
		if (!isdigit(value[i]))
			throw std::invalid_argument("8bad input => " + value);
	}

	if (dotPos != std::string::npos && value.substr(dotPos + 1).length() > 6)
		throw std::invalid_argument("too long decimal.");

	double dValue = std::stod(value);
	if (dValue > 1000)
		throw std::invalid_argument("too large a number.");
	if (dValue < 0)
		throw std::invalid_argument("not a positive number.");

	return std::stof(value);
}

void BitcoinExchange::printResult(std::pair<std::string, float> data) {
	std::map<std::string, float>::iterator it = _data.lower_bound(data.first);

	if (it == _data.begin())
    throw std::invalid_argument("no such date.");
  if (it->first != data.first)
    it--;

	float result = it->second * data.second;

	std::cout << data.first << " => " << data.second << " = " << result << std::endl;
}

void BitcoinExchange::execute() {
	std::ifstream ifs;
	std::string buf;
	std::string date;
	std::string value;

	ifs.open(_targetFilename);
	if (!ifs) {
		std::cout << FILEOPEN_ERROR << std::endl;
		exit (EXIT_FAILURE);
	}

	std::getline(ifs, buf);
	while (std::getline(ifs, buf)) {
		try {
			std::pair<std::string, float> data = parseTargetLine(buf);
			printResult(data);
		} catch (std::exception &e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}

	ifs.close();
}
