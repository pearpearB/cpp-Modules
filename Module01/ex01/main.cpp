#include "Zombie.hpp"

void makeZombieHorde(void) {
	Zombie* z = zombieHorde(5, "zombie");

	for (int i = 0; i < 5; i++) z[i].announce();
	delete[] z;
}

int main(void) {
	
	makeZombieHorde();

	std::cout << "<-----check leaks----->" << std::endl;
	system("leaks zombie");

	return 0;
}