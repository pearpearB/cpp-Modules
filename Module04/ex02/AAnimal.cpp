#include "AAnimal.hpp"

/* orthodox canonical form */
AAnimal::AAnimal(): _type("AAnimal") {
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src): _type(src._type) {
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &rhs) {
	if (this != &rhs)
		_type = rhs._type;
	return *this;
}

/* member function */
std::string AAnimal::getType() const {
	return this->_type;
}

void AAnimal::makeSound() const {
	std::cout << "AAnimal make sound: ... " << std::endl;
}