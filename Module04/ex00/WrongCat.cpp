#include "WrongCat.hpp"

/* orthodox canonical form */
WrongCat::WrongCat(): WrongAnimal() {
	this->_type = "WrongCat";
	std::cout << "WrongCat is born" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src): WrongAnimal(src) {
	*this = src;
	std::cout << "Copy WrongCat is born by copy constructor" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat is died" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs) {
	if (this != &rhs)
		this->_type = rhs._type;
	std::cout << "Copy WrongCat is born by copy operator" << std::endl;
	return *this;
}

/* member function */
void WrongCat::makeSound() const {
	std::cout << "Meow Meow Meow =^._.^= ∫" << std::endl;
}