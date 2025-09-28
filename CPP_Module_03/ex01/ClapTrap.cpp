// ****************************************************************************************** //
//                               file: ClapTrap.cpp                                           //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/09/28 17:55 by mait-all                        //
//                               Updated: 2025/09/28 17:57 by mait-all                        //
// ****************************************************************************************** //

#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap()
{
	_name = "unknown";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &other)
{
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	std::cout << "Copy constructor called" << std::endl;
}

// Parametrised constructor
ClapTrap::ClapTrap(std::string newName) {
	_name = newName;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	std::cout << "Parametrised constructor called" << std::endl;
}

// Copy assignment operator
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	std::cout << "Copy assignment operator called" << std::endl;

	return (*this);
}

// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

// --- Member functions ---
void	ClapTrap::attack(const std::string& target) {
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap: " << _name << " is dead!" << std::endl;
		return ;
	}
	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap: " << _name << " can not attacks " << target << ": has no energy points!" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ClapTrap: " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap: " << _name << " is already dead!" << std::endl;
		return ;
	}
	// Prevent negative hit points
	if (amount >= _hitPoints)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	std::cout << "ClapTrap: " << _name << " takes " << amount << " points of damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap: " << _name << " is dead!" << std::endl;
		return ;
	}
	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap: " << _name << " can not be repaired: has no energy left!" << std::endl;
		return ;
	}
	_hitPoints += amount;
	_energyPoints--;
	std::cout << "ClapTrap: " << _name << " is repaired for " << amount << " hit points!" << std::endl;
}