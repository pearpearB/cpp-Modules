#include "Zombie.hpp"

void Zombie::announce(void) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name): _name(name) {}

Zombie::Zombie(): _name("default") {}

Zombie::~Zombie() {
	std::cout << this->_name << " is dead" << std::endl;
}
