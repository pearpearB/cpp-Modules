#include "Fixed.hpp"

int main(void) { 
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c(10);
	Fixed d(10.0f);

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << (c == d) << std::endl;

	return 0; 
}

/*
0 // a
0.00390625 // ++a
0.00390625 // a
0.00390625 // a++
0.0078125  // a
10.1016    // b 
// Fixed( 5.05f ) 5.05 * 256 = 1292.8 -> 1293
// Fixed( 2 ) 2 * 256 = 512 -> 512
// (1293 / 256) * (512 / 256) = 10.1015625 -> 10.1016
10.1016    // max(a, b)
1          // c == d
*/