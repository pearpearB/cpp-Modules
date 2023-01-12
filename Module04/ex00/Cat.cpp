#include "Cat.hpp"

/* orthodox canonical form */
Cat::Cat(): Animal() {
	this->_type = "Cat";
	std::cout << "Cat is born" << std::endl;
}

Cat::Cat(const Cat &src): Animal(src) {
	*this = src;
	std::cout << "Copy cat is born" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat is died" << std::endl;
}

Cat &Cat::operator=(const Cat &rhs) {
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

/* member function */
void Cat::makeSound() const {
	std::cout << "Meow Meow Meow =^._.^= ∫" << std::endl;
}