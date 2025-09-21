#include "Weapon.hpp"

// Constructor
Weapon::Weapon(std::string t)
{
	_type = t;
}

// getter
const std::string& Weapon::getType(void)
{
	return (_type);
}

// setter
void	Weapon::setType(std::string newType)
{
	_type = newType;
}