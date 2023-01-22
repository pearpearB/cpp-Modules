#include "Array.hpp"

int main() {
	Array<int> a(5);
	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = i;
	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << a[i] << std::endl;
	
	Array<int> b(a);
	for (unsigned int i = 0; i < b.size(); i++)
		std::cout << b[i] << std::endl;
	
	Array<int> c;
	c = b;
	for (unsigned int i = 0; i < c.size(); i++)
		std::cout << c[i] << std::endl;
	
	try {
		std::cout << c[9] << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return 0;
}