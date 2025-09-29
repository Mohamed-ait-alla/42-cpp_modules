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
	ScavTrap	a;
	ScavTrap	b(a);
	ScavTrap	c;

	c = b;
	a.attack("enemy");
	b.attack("enemy");
	c.attack("enemy");
	return (0);
}