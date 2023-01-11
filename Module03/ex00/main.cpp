#include "ClapTrap.hpp"

int main(void) {
	ClapTrap jabae("jabae");
	ClapTrap jihyukim("jihyukim");

	jabae.attack("jihyukim");
	jihyukim.takeDamage(10);
	jihyukim.beRepaired(5);

	return 0;
}
