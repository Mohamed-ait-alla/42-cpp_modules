#include "HumanB.hpp"

// Constructor
HumanB::HumanB(std::string manName)
{
	name = manName;
	humanBWeapon = NULL;
}

// member function
void	HumanB::attack()
{
	std::cout << name
			  << " attacks with their ";
	if (humanBWeapon)
			std::cout << (*humanBWeapon).getType();
	else
			std::cout << "no weapon";
	std::cout << std::endl;
}

// setter
void	HumanB::setWeapon(Weapon& weapon)
{
	humanBWeapon = &weapon;
}