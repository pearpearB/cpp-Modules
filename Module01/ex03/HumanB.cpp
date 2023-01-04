#include "HumanB.hpp"

void HumanB::attack() {
	std::cout << this->_name << " is attacking with " << (this->_weapon ? this->_weapon->getType() : "hand" )<< std::endl;
}

void HumanB::setWeapon(Weapon& weapon) {
	this->_weapon = &weapon;
}

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}
