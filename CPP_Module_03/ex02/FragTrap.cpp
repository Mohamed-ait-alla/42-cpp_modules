// ****************************************************************************************** //
//                               file: FragTrap.cpp                                           //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/09/30 09:22 by mait-all                        //
//                               Updated: 2025/09/30 09:57 by mait-all                        //
// ****************************************************************************************** //

#include "FragTrap.hpp"


// Default constructor
FragTrap::FragTrap() {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap: Default constructor called" << std::endl;
}

// parametrised constructor
FragTrap::FragTrap(std::string newName) : ClapTrap(newName) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap: Parametrised constructor called" << std::endl;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap: Copy constructor called" << std::endl;
}

// Copy assignment operator
FragTrap&	FragTrap::operator=(const FragTrap& other) {
	ClapTrap::operator=(other);
	std::cout << "FragTrap: Copy assignment operator called" << std::endl;
	return (*this);
}

// Destructor
FragTrap::~FragTrap() {
	std::cout << "FragTrap: Destructor called" << std::endl;
}

// --- Member functions ---

void	FragTrap::attack(const std::string& target) {
	if (_hitPoints <= 0)
	{
		std::cout << "FragTrap: " << _name << " is dead!" << std::endl;
		return ;
	}
	if (_energyPoints <= 0)
	{
		std::cout << "FragTrap: " << _name << " can not attacks " << target << ": has no energy points!" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "FragTrap: " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void	FragTrap::highFivesGuys(void) {
	if (_hitPoints <= 0 || _energyPoints <= 0)
	{
		std::cout << "FragTrap: " << _name << " is dead and cannot request high fives!" << std::endl;
		return ;
	}
	std::cout << "FragTrap: " << _name << " requests a positive high five!" << std::endl;
}