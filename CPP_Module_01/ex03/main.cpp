/*
 * @author:
 *			Mohamed Ait Alla
 * 
 * @description:
 * 				The goal is to implement two classes (HumanA and HumanB) that both use a Weapon class,
 * 				but with different behaviors:
 * 				  - HumanA is always armed and takes its Weapon by reference in the constructor.
 * 				  - HumanB may start unarmed and can be assigned a Weapon later via a setter.
 * 				This exercise focuses on references vs pointers, and illustrates when each should be used.
 * 
 * @usage:
 * 			1. Compile:		make
 * 			2. Run:			./weapon
 * 			3. full clean:	make fclean
*/

#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
}