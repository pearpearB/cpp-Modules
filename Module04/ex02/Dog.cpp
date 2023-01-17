#include "Dog.hpp"

/* orthodox canonical form */
Dog::Dog(): AAnimal(), _brain(new Brain()) {
	this->_type = "Dog";
	std::cout << "Dog is born" << std::endl;
}

Dog::Dog(const Dog &src): AAnimal(src), _brain(new Brain()) {
	*this = src;
	std::cout << "Copy dog is born by copy constructor" << std::endl;
}

Dog::~Dog() {
	delete this->_brain;
	std::cout << "Dog is died" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
		*this->_brain = *rhs._brain;
	}
	return *this;
}

/* member function */
void Dog::makeSound() const {
	std::cout << "Bark Bark Bark ▽･ｪ･▽ﾉ”" << std::endl;
}