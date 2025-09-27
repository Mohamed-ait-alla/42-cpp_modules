/*
 * @author:
 * 			mait-all
 * 
 * @github:
 * 			https://github.com/Mohamed-ait-alla
 * 
 * @description:
 * 			This exercice introduces the basics of dynamic and static memory allocation, by
 * 			understanding the difference between creating objects on the stack and on the heap.
 * 			The functions newZombie(zombieName) and randomChump(zombieName) demonstrate this concept.
 * 
 * @usage:
 * 			1. Compile source files:	make
 * 			2. Run the executable:		./zombies
 * 			3. For cleaning up:			make clean
*/



#include "Zombie.hpp"

int main()
{
	Zombie*	z1;

	z1 = newZombie("Alice");
	z1->announce();
	delete(z1);

	randomChump("Bob");
}