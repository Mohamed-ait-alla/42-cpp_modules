// ****************************************************************************************** //
//                               file: ClapTrap.cpp                                           //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/09/27 10:30 by mait-all                        //
//                               Updated: 2025/09/27 18:12 by mait-all                        //
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