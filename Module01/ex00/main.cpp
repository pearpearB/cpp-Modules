#include "Zombie.hpp"

int main(void) {
	Zombie* newZ = newZombie("ping");

    randomChump("pong");
    newZ->announce();
    delete newZ;
	return 0;
}
