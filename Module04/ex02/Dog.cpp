#include "Dog.hpp"

/* orthodox canonical form */
Dog::Dog(): AAnimal() {
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog is born" << std::endl;
}

Dog::Dog(const Dog &src): AAnimal(src) {
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
		// *(this->_brain) = *(rhs._brain); //[1]    55487 bus error  ./AAnimal 
		// this->_brain = rhs._brain; 		// [1]    55654 abort      ./AAnimal
											// malloc: *** error for object 0x7fa9de00b600: pointer being freed was not allocated
		this->_brain = new Brain(*rhs._brain);
	}
	return *this;
}

/* member function */
void Dog::makeSound() const {
	std::cout << "Bark Bark Bark ▽･ｪ･▽ﾉ”" << std::endl;
}