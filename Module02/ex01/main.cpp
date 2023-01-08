#include "Fixed.hpp"

int main(void) {
	Fixed 		a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0; 
}

/*
a is 1234.43 // roundf로 반올림해서 뒤를 버리고 int형으로 저장한 뒤, toFloat()하면 1234.43이 나온다.
b is 10
c is 42.4219 // 256을 곱하고 올림한 뒤, toFloat()으로 256을 나누면 42.421875...이 나온다.
d is 10
a is 1234 as integer
b is 10 as integer
c is 42 as integer
d is 10 as integer
*/