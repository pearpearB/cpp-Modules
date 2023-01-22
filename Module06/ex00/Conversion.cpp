#include "Conversion.hpp"

/* orthodox canonical form */
Conversion::Conversion() : _param("42"), _value(std::strtod(_param.c_str(), NULL)) {}

Conversion::Conversion(std::string param) : _param(param), _value(std::strtod(_param.c_str(), NULL)) {}

Conversion::Conversion(Conversion const &src) {
	*this = src;
}

Conversion::~Conversion() {}

Conversion &Conversion::operator=(Conversion const &rhs) {
	if (this != &rhs) {
		this->_param = rhs._param;
		this->_value = rhs._value;
	}
	return *this;
}

/* member functions */
void Conversion::convertToChar(void) {
	if (std::isprint(this->_value)) {
		std::cout << "'" << static_cast<char>(this->_value) << "'" << std::endl;
		return ;
	}
	if (this->_value > std::numeric_limits<char>::min() - 1.0 && this->_value < std::numeric_limits<char>::max() + 1.0) { // 소수점 아래 버림되는 문제 해결
		throw Conversion::NonDisplayableException();
	}
	throw Conversion::ImpossibleException();
}

void Conversion::convertToInt(void) {
	if (this->_value > std::numeric_limits<int>::min() - 1.0 && this->_value < std::numeric_limits<int>::max() + 1.0) {
		std::cout << static_cast<int>(this->_value) << std::endl;
		return ;
	}
	throw Conversion::ImpossibleException();
}

void Conversion::convertToFloat(void) {
	if (this->_value != this->_value) { // nan 확인하는 방법
		std::cout << "nanf" << std::endl;
		return ;
	}
	if (this->_value == std::numeric_limits<double>::infinity()) {
		std::cout << "+inff" << std::endl;
		return ;
	}
	if (this->_value == -std::numeric_limits<double>::infinity()) {
		std::cout << "-inff" << std::endl;
		return ;
	}
	if (this->_value > -std::numeric_limits<float>::max() - 1.0 && this->_value < std::numeric_limits<float>::max() + 1.0) {
		std::cout << std::setprecision(6) << static_cast<float>(this->_value) << "f" << std::endl;
		return ;
	}
	throw Conversion::ImpossibleException();
}

void Conversion::convertToDouble(void) {
	if (this->_value != this->_value) {
		std::cout << "nan" << std::endl;
		return ;
	}
	if (this->_value == std::numeric_limits<double>::infinity()) {
		std::cout << "+inf" << std::endl;
		return ;
	}
	if (this->_value == -std::numeric_limits<double>::infinity()) {
		std::cout << "-inf" << std::endl;
		return ;
	}
	if (this->_value > -std::numeric_limits<double>::max() - 1.0 && this->_value < std::numeric_limits<double>::max() + 1.0) {
		std::cout << std::setprecision(15) << static_cast<double>(this->_value) << std::endl;
		return ;
	}
	throw Conversion::ImpossibleException();
}

/* exception */
const char* Conversion::ImpossibleException::what() const throw() {
	return "impossible";
}

const char* Conversion::NonDisplayableException::what() const throw() {
	return "Non displayable";
}

/* global functions */
std::ostream &operator<<(std::ostream &o, Conversion const &rhs) {
	Conversion	obj(rhs);

	try {
		std::cout << "char: ";
		obj.convertToChar();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "int: ";
		obj.convertToInt();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "float: ";
		obj.convertToFloat();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "double: ";
		obj.convertToDouble();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return o;
}
