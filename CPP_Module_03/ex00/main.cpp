/*
 * @author:
 * 			ToDo...
 * 
 * @github:
 * 			ToDo...
 * 
 * @description:
 * 				ToDo...
 * 
 * @usage:
 * 			ToDo...
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
	// claptrap.takeDamage(2);
	// claptrap.takeDamage(2);
	claptrap.attack("enemy");
	claptrap.beRepaired(10);
	claptrap.attack("enemy");
	return (0);
}