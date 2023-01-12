#include "Dog.hpp"

/* orthodox canonical form */
Dog::Dog(): Animal() {
	this->_type = "Dog";
	std::cout << "Dog is born" << std::endl;
}

Dog::Dog(const Dog &src): Animal(src) {
	*this = src;
	std::cout << "Copy dog is born" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog is died" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs) {
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

/* member function */
void Dog::makeSound() const {
	std::cout << "Bark Bark Bark ▽･ｪ･▽ﾉ”" << std::endl;
}