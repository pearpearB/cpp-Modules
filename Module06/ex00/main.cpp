#include "Conversion.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Usage: ./conversion [value]" << std::endl;
	} else {
		std::cout << Conversion(av[1]);
	}
	return 0;
}