#include <Weapon.hpp>

// Constructor
Weapon::Weapon(std::string t)
{
	type = t;
}

// getter
const std::string& Weapon::getType()
{
	return (type);
}

// setter
void	Weapon::setType(std::string newType)
{
	type = newType;
}