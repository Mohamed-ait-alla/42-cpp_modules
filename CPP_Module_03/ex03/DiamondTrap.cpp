// ****************************************************************************************** //
//                               file: DiamondTrap.cpp                                        //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/09/30 10:44 by mait-all                        //
//                               Updated: 2025/10/01 19:14 by mait-all                        //
// ****************************************************************************************** //

#include "DiamondTrap.hpp"


// Default constructor
DiamondTrap::DiamondTrap()
	: ClapTrap(),
	  ScavTrap(),
	  FragTrap()
{
	this->_name = "unknown";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
	std::cout << "DiamondTrap: Default constructor called" << std::endl;
}

// Parametrised constructor
DiamondTrap::DiamondTrap(std::string newName) 
	: ClapTrap(newName + "_clap_name"),
	  ScavTrap(newName),
	  FragTrap(newName)
{
	this->_name = newName;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
	std::cout << "DiamondTrap: Parametrised constructor called" << std::endl;
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other),
	  ScavTrap(other),
	  FragTrap(other)
{
	this->_name = other._name;
	std::cout << "DiamondTrap: Copy constructor called" << std::endl;
}

// Copy assignment operator
DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other) {
	// call base assignment operators
	ClapTrap::operator=(other);
	ScavTrap::operator=(other);
	FragTrap::operator=(other);

	// copy DiamondTrap-specific members
	this->_name = other._name;
	std::cout << "DiamondTrap: Copy assignment operator called" << std::endl;
	return (*this);
}

// Destructor
DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap: Destructor called" << std::endl;
}


// --- Member functions ---
void	DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "I am DiamondTrap: " << _name << std::endl;
	std::cout << "My ClapTrap name is: " << ClapTrap::_name << std::endl;
}
