#include "HumanA.hpp"

// Constructor
HumanA::HumanA(std::string manName, Weapon& weapon) : humanAWeapon(weapon), name(manName) {}

// member function
void	HumanA::attack()
{
	std::cout << name
			  << " attacks with their "
			  << humanAWeapon.getType()
			  << std::endl;
}