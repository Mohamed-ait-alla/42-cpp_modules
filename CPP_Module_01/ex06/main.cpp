/*
 * @author:
 *			mait-all
 * 
 * @github:
 * 			https://github.com/Mohamed-ait-alla
 * 
 * @description:
 * 			This exercise extends the previous Harl class by implementing a complaint
 * 			filtering system. The program receives a complaint level and executes only
 * 			the complaints that are equal to or above that level.
 * 			The available levels are: "DEBUG", "INFO", "WARNING", "ERROR"
 * 
 * 			This exercise focuses on practicing switch-case statements with fall-through
 * 			behavior.
 * 
 * @usage:
 * 			1. Compile:		make
 * 			2. Run:			./harlFilter [level]
 * 			3. Clean up:	make clean
 * 			4. Full clean:	make fclean
*/

#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl	harl;
	
	// Invalid args
	if (ac != 2)
		return (std::cerr << CYAN "Usage: ./harlFilter [level]" RESET "\n", 1);
	
	// Process the entred level
	harl.complain(av[1]);
	return (0);
}