// ****************************************************************************************** //
//                               file: ScavTrap.cpp                                           //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/09/28 17:55 by mait-all                        //
//                               Updated: 2025/09/30 08:51 by mait-all                        //
// ****************************************************************************************** //

#include "ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap() {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap: Default constructor called" << std::endl;
}

// Parametrised constructor
ScavTrap::ScavTrap(const std::string newName) : ClapTrap(newName) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap: Parametrised constructor called" << std::endl;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	// note: copy constructor of ClapTrap will copy required variables, preventing redundancy here.
	std::cout << "ScavTrap: Copy constructor called" << std::endl;
}

// Copy assignment operator
ScavTrap&	ScavTrap::operator=(const ScavTrap& other) {
	ClapTrap::operator=(other);
	std::cout << "ScavTrap: Copy assignment operator called" << std::endl;
	return (*this);
}

// Destructor
ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap: Destructor called" << std::endl;
}

// --- Member functions ---

void	ScavTrap::attack(const std::string& target) {
	if (_hitPoints <= 0)
	{
		std::cout << "ScavTrap: " << _name << " is dead!" << std::endl;
		return ;
	}
	if (_energyPoints <= 0)
	{
		std::cout << "ScavTrap: " << _name << " can not attacks " << target << ": has no energy points!" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ScavTrap: " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate(void) {
	if (_hitPoints <= 0 || _energyPoints <= 0)
	{
		std::cout << "ScavTrap: " << _name << " is dead and cannot enter Gate keeper mode!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap: " << _name << " is now in Gate keeper mode!" << std::endl;
}