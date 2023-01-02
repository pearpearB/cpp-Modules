#include "Zombie.hpp"

void makeHeapZ(void) {
	Zombie* newZ = newZombie("heapZ");
	newZ->announce();
	delete newZ;
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
