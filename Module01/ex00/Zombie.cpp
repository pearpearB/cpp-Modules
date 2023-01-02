#include "Zombie.hpp"

void Zombie::announce(void) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name): _name(name) {}

Zombie::Zombie(): Zombie("default") {} // 위임 생성자

Zombie::~Zombie() {
	std::cout << this->_name << " is dead" << std::endl;
}
