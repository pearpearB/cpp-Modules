#include "ScavTrap.hpp"

int main(void) {
	ScavTrap jabae("jabae");
	ScavTrap jiyokim("jiyokim");

	jabae.attack("jiyokim");
	jiyokim.takeDamage(20);
	jiyokim.beRepaired(10);

	jiyokim.attack("jabae");
	jiyokim.takeDamage(10);
	jiyokim.beRepaired(10);

	jabae.guardGate();
	
	return 0;
}
