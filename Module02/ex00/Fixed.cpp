#include "Fixed.hpp"

/* constructors */
Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPointValue = 0;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
} // *this 객체 대상으로 operator= 함수를 호출하면서 fixed를 인자로 전달한다.

/* operator */
Fixed	&Fixed::operator=(const Fixed &fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed) 							// 나 자신이 아니라면
		this->_fixedPointValue = fixed.getRawBits(); // 값을 할당함. 예외처리.
	return *this; // 값을 보내줌
} // 함수 오버로딩, 'Fixed 객체 = 우변에 Fixed 객체 ' 이렇게 사용한다면 위 함수가 호출된다.

/* member function */
int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}

void	Fixed::setRawBits(int const raw) {
	this->_fixedPointValue = raw;
}
