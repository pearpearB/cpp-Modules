#include "Animal.hpp"

/* orthodox canonical form */
Animal::Animal(): _type("Animal") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &src): _type(src._type) {
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &rhs) {
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

/* member function */
std::string Animal::getType() const {
	return this->_type;
}

void Animal::makeSound() const {
	std::cout << "Animal make sound: ... " << std::endl;
}