#include "Zombie.hpp"

int makeHeapZ(void) {
	Zombie* newZ = newZombie("heapZ");
	newZ->announce();
	delete newZ;
	return 0;
}

int main(void) {
	Zombie defaultZ;
	defaultZ.announce();

	randomChump("stackZ");
	
	makeHeapZ();

	std::cout << "<-----check leaks----->" << std::endl;
	system("leaks zombie");

	return 0;
}
