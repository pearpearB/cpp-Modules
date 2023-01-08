#include "Fixed.hpp"

/* constructors */
Fixed::Fixed() {
	_fixedPointValue = 0;
}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed &fixed) {
	*this = fixed;
}

Fixed::Fixed(const int number) {
	_fixedPointValue = number << _fractionalBits;
}

Fixed::Fixed(const float number) {
	_fixedPointValue = roundf(number * (1 << _fractionalBits));
}

/* operator */
Fixed			&Fixed::operator=(const Fixed &rhs) {
	if (this != &rhs)
		_fixedPointValue = rhs._fixedPointValue;
	return *this;
}

bool			Fixed::operator>(const Fixed &rhs) const {
	return _fixedPointValue > rhs._fixedPointValue;
} // 다른 인스턴스 객체지만, 같은 클래스 타입의 인스턴스를 참조하는 경우에는 getter를 쓰지 않아도 된다.
  // 그러나, 다른 클래스 타입의 인스턴스를 참조하는 경우에는 getter를 써야 한다.

bool			Fixed::operator<(const Fixed &rhs) const {
	return _fixedPointValue < rhs._fixedPointValue;
}

bool			Fixed::operator>=(const Fixed &rhs) const {
	return _fixedPointValue >= rhs._fixedPointValue;
}

bool			Fixed::operator<=(const Fixed &rhs) const {
	return _fixedPointValue <= rhs._fixedPointValue;
}

bool			Fixed::operator==(const Fixed &rhs) const {
	return _fixedPointValue == rhs._fixedPointValue;
}

bool			Fixed::operator!=(const Fixed &rhs) const {
	return _fixedPointValue != rhs._fixedPointValue;
}

Fixed			Fixed::operator+(const Fixed &rhs) const {
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed			Fixed::operator-(const Fixed &rhs) const {
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed			Fixed::operator*(const Fixed &rhs) const {
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed			Fixed::operator/(const Fixed &rhs) const {
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed			&Fixed::operator++() {
	_fixedPointValue += 1;
	return *this;
}

Fixed			&Fixed::operator--() {
	_fixedPointValue -= 1;
	return *this;
}

Fixed			Fixed::operator++(int) {
	Fixed tmp(*this);
	_fixedPointValue += 1;
	return tmp;
}

Fixed			Fixed::operator--(int) {
	Fixed tmp(*this);
	_fixedPointValue -= 1;
	return tmp;
}

std::ostream	&operator<<(std::ostream &ostream, const Fixed &rhs) {
	return ostream << rhs.toFloat();
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
}

/* static member function */
Fixed	&Fixed::min(Fixed &a, Fixed &b) {
	return a < b ? a : b;
}

Fixed	&Fixed::max(Fixed &a, Fixed &b) {
	return a > b ? a : b;
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b) {
	return a < b ? a : b;
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b) {
	return a > b ? a : b;
}
