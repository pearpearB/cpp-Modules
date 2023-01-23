#include "Array.hpp"

void testLeak() {
	srand(time(NULL));

	Array<int> a(5);
	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = rand() % 100;
	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << a[i] << std::endl;
	
	Array<int> b(a);
	for (unsigned int i = 0; i < b.size(); i++)
		std::cout << b[i] << std::endl;
	
	Array<int> c;
	c = b;
	for (unsigned int i = 0; i < c.size(); i++)
		std::cout << c[i] << std::endl;

	std::cout << "test deep copy" << std::endl;
	a[0] = 0;
	std::cout << a[0] << ", " << b[0] << ", " << c[0] << std::endl;
	
	try {
		std::cout << c[100] << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

int main() {

	testLeak();

	system("leaks array");

	return 0;
}