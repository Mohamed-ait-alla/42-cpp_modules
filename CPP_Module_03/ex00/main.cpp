/*
 * @author:
 * 			mait-all
 * 
 * @github:
 * 			https://github.com/Mohamed-ait-alla
 * 
 * @description:
 * 			This program demonstrates the behavior of the ClapTrap class,
 * 			a simple combat robot with hit points, energy points, and attack damage.
 * 			
 * 			The ClapTrap can perform three main actions:
 * 				- attack(const std::string& target): attacks the target if energy and HP allow.
 * 				- takeDamage(unsigned int amount): loses hit points when damaged.
 * 				- beRepaired(unsigned int amount): restores hit points using energy.
 * 
 * @usage:
 * 			1. Compile:	make
 * 			2. Run:		./clapTrap
 * 			3. CleanUp:	make fclean
*/


#include "ClapTrap.hpp"

int main( void )
{
	ClapTrap claptrap("Teo");
	ClapTrap claptrap2(claptrap);
	ClapTrap claptrap4;
	claptrap4 = claptrap;

	std::cout << std::endl;
	std::cout << std::endl;

	claptrap.attack("enemy");
	claptrap.takeDamage(9);
	claptrap.attack("enemy");
	claptrap.takeDamage(2);
	claptrap.attack("enemy");
	claptrap.beRepaired(10);
	claptrap.attack("enemy");
	return (0);
}