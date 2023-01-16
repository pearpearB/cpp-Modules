#include "Cat.hpp"

/* orthodox canonical form */
Cat::Cat(): AAnimal() {
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << "Cat is born" << std::endl;
}

Cat::Cat(const Cat &src): AAnimal(src) {
	*this = src;
	std::cout << "Copy cat is born by copy constructor" << std::endl;
}

Cat::~Cat() {
	delete this->_brain;
	std::cout << "Cat is died" << std::endl;
}

Cat &Cat::operator=(const Cat &rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
		this->_brain = new Brain(*rhs._brain);
	}
	std::cout << "Copy cat is born by copy operator" << std::endl;
	return *this;
}

/* member function */
void Cat::makeSound() const {
	std::cout << "Meow Meow Meow =^._.^= ∫" << std::endl;
}