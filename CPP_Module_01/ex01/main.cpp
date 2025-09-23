/*
 * @author:
 *			Mohamed Ait Alla
 * 
 * @description:
 * 				This program extends the ex00 concept, It's about creating a horde of
 * 				zombies dynamically.
 * 				The goal of this exercice focuses on allocating arrays of objects on
 * 				the heap, initializing them, and managing them to avoid memory leaks.
 * 
 * @usage:
 * 			1. Compile source files:	make
 * 			2. Clean up:				make clean
 * 			3. Run the program:			./Horde
 * 			4. Full clean:				make fclean
*/

#include "Zombie.hpp"

int main()
{
	Zombie*	horde;

	horde = zombieHorde(3, "Alice");
	for (int i = 0; i < 3; i++)
	{
		horde[i].announce();
	}

	// free allocated memory
	delete[] horde;
}