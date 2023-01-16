#include "WrongAnimal.hpp"

/* orthodox canonical form */
WrongAnimal::WrongAnimal(): _type("WrongAnimal") {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src): _type(src._type) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs) {
	if (this != &rhs)
		_type = rhs._type;
	std::cout << "WrongAnimal copy operator called" << std::endl;
	return *this;
}

/* member function */
std::string WrongAnimal::getType() const {
	return this->_type;
}

void WrongAnimal::makeSound() const {
	std::cout <<"Wrong animal make sound: ... " << std::endl;
}
