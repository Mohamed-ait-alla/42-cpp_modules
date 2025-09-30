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

#include "ScavTrap.hpp"

int main( void )
{
	ScavTrap	a("Teo");
	ScavTrap	b(a);
	ScavTrap	c;

	c = b;
	b.attack("enemy");
	b.takeDamage(99);
	// b.beRepaired(12);
	b.attack("enemy");
	b.guardGate();

	return (0);
}