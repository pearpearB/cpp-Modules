#include "FragTrap.hpp"

/* orthodox canonical form */
FragTrap::FragTrap(): ClapTrap() {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " constructor created" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " constructor created" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) {
	*this = src;
	std::cout << "FragTrap " << this->_name << " copy constructor called" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->_name << " destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs) {
	if (this != &rhs) {
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return *this;
}

/* member function */
void FragTrap::highFivesGuys() {
	if (!this->_hitPoints) {
		std::cout << "FragTrap " << this->_name << " died" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->_name << " high fives guys *^^*" << std::endl;
}

void FragTrap::attack(const std::string &target) {
	if (!this->_hitPoints) {
		std::cout << "FragTrap " << this->_name << " died" << std::endl;
		return ;
	}
	if (!this->_energyPoints) {
		std::cout << "FragTrap " << this->_name << " has no energy points!" << std::endl;
		return ;
	}

	this->_energyPoints -= 1;
	std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage! " << std::endl;
}