#include "Fixed.hpp"

int main(void) {
	Fixed a;
	Fixed b(a);
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0; 
}

/*
Default constructor called // Fixed a; 에서 호출
Copy constructor called    // Fixed b(a); 에서 호출
Copy assignment operator called
getRawBits member function called
Default constructor called // Fixed c; 에서 호출

Copy assignment operator called // c = b; 에서 호출
getRawBits member function called

getRawBits member function called
0
getRawBits member function called
0
getRawBits member function called
0

Destructor called
Destructor called
Destructor called
*/