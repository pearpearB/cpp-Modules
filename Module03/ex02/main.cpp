#include "FragTrap.hpp"

int main(void) {
	FragTrap jabae("jabae");
	FragTrap jiyokim("jiyokim");

	jabae.attack("jiyokim");
	jiyokim.takeDamage(20);
	jiyokim.beRepaired(10);

	jiyokim.attack("jabae");
	jiyokim.takeDamage(10);
	jiyokim.beRepaired(10);

	jabae.highFivesGuys();
	
	return 0;
}
