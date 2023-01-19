#include "Cat.hpp"

/* orthodox canonical form */
Cat::Cat(): Animal(), _brain(new Brain()) {
	this->_type = "Cat";
	std::cout << "Cat is born" << std::endl;
}

Cat::Cat(const Cat &src): Animal(src), _brain(new Brain()) { // _brain(new Brain(*src._brain)) 도 가능, Brain의 copy constructor가 깊은 복사를 하기 때문
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
		*this->_brain = *rhs._brain; // 깊은 복사
		// this->_brain = rhs._brain; // 얕은 복사 // 이렇게 하게 되면, main의 두번째 case delete에서 터지게 된다. (dog1과 dog2가 같은 주소를 공유하고 있으므로, 해제한 곳을 또 해제해서)
	}
	return *this;
}

/* member function */
void Cat::makeSound() const {
	std::cout << "Meow Meow Meow =^._.^= ∫" << std::endl;
}