#include "Cat.hpp"

/* orthodox canonical form */
Cat::Cat(): AAnimal(), _brain(new Brain()) {
	this->_type = "Cat";
	std::cout << "Cat is born" << std::endl;
}

Cat::Cat(const Cat &src): AAnimal(src), _brain(new Brain()) {
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
		*this->_brain = *rhs._brain;
	}
	return *this;
}

/* member function */
void Cat::makeSound() const {
	std::cout << "Meow Meow Meow =^._.^= ∫" << std::endl;
}