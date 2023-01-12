#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &src);
		~ScavTrap();
		ScavTrap &operator=(const ScavTrap &rhs);

		void guardGate();
		void attack(const std::string &target);
};

#endif