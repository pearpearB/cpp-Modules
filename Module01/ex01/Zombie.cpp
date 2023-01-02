#include "Zombie.hpp"

void Zombie::announce(void) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
	this->_name = name;
}

Zombie::Zombie(std::string name): _name(name) {}

Zombie::Zombie(): _name("defaultZ") {}

Zombie::~Zombie() {
	std::cout << this->_name << " is dead" << std::endl;
}
