#include "Cat.hpp"

/* orthodox canonical form */
Cat::Cat(): Animal(), _brain(new Brain()) {
	this->_type = "Cat";
	std::cout << "Cat is born" << std::endl;
}

Cat::Cat(const Cat &src): Animal(src), _brain(new Brain()) { // _brain(new Brain(*src._brain)) ?
	// this->_brain = new Brain();
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
		*this->_brain = *rhs._brain; // 조건? NULL이 아니면이 필요할까? 깊은복사로 만들어주기!
		// *(this->_brain) = *(rhs._brain); //[1]    55487 bus error  ./animal 
		// this->_brain = rhs._brain; 		// [1]    55654 abort      ./animal
											// malloc: *** error for object 0x7fa9de00b600: pointer being freed was not allocated
		// this->_brain = new Brain(*rhs._brain); // 얕은 복사
	}
	return *this;
}

/* member function */
void Cat::makeSound() const {
	std::cout << "Meow Meow Meow =^._.^= ∫" << std::endl;
}