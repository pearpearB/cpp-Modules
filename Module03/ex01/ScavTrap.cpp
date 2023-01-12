#include "ScavTrap.hpp"

/* orthodox canonical form */
ScavTrap::ScavTrap(): ClapTrap() {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << this->_name << " constructor created" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << this->_name << " constructor created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) {
	*this = src;
	std::cout << "ScavTrap " << this->_name << " copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->_name << " destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return *this;
}

/* member function */
void ScavTrap::guardGate() {
	if (!this->_hitPoints) {
		std::cout << "ScavTrap " << this->_name << " died" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " has entered in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
	if (!this->_hitPoints) {
		std::cout << "ScavTrap " << this->_name << " died" << std::endl;
		return ;
	}
	if (!this->_energyPoints) {
		std::cout << "ScavTrap " << this->_name << " has no energy points!" << std::endl;
		return ;
	}

	this->_energyPoints -= 1;
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage! " << std::endl;
}