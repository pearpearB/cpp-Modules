#include "Fixed.hpp"

/* constructors */
Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	_fixedPointValue = 0;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const int number) {
	std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = number << _fractionalBits;
} // b는 비트 연산으로 10진수 10에서 2560으로 바뀜
  // 2진수로 10은 1010에서  1010 0000 0000으로 바꾸어 저장한다.

Fixed::Fixed(const float number) {
	std::cout << "Float constructor called" << std::endl;
	_fixedPointValue = roundf(number * (1 << _fractionalBits));
} // float는 저장 형식이 다르기 때문에 다르게 연산한다. 
  // 2의 지수 만큼을 곱해서 저장한다. 지수 비트 만큼 꺼내 쓸 수 있도록!
  // roundf로 반올림해서 버려지는 값을 정규화 해준다.

/* operator */
Fixed			&Fixed::operator=(const Fixed &fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		_fixedPointValue = fixed.getRawBits();
	return *this;
}

std::ostream	&operator<<(std::ostream &ostream, const Fixed &fixed) {
	return ostream << fixed.toFloat();
}

/* member function */
int		Fixed::getRawBits(void) const {
	return _fixedPointValue;
}

void	Fixed::setRawBits(int const raw) {
	_fixedPointValue = raw;
}

int		Fixed::toInt(void) const {
	return _fixedPointValue >> _fractionalBits;
}

float	Fixed::toFloat(void) const {
	return (float)_fixedPointValue / (1 << _fractionalBits);
} // 2의 지수 만큼을 나눠서 원래의 값으로 되돌린다.
