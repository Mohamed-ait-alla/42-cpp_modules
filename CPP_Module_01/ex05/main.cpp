/*
 * @author:
 *			mait-all
 *
 * @github:
 * 			https://github.com/Mohamed-ait-alla
 * 
 * @description:
 * 			The goal is to design a simple class (Harl) that simulates different levels
 * 			of complaints. Each complaint level ("DEBUG", "INFO", "WARNING", "ERROR")
 * 			corresponds to a specific private member function. The task is to map input
 * 			strings to these member functions, triggering the appropriate complaint level.
 * 
 * 			This exercise introduces the concept of function pointers to member functions
 * 			and how they can be used to implement dynamic behavior.
 * 
 * @usage:
 * 			1. Compile:		make
 * 			2. Run:			./harl
 * 			3. Full clean:	make fclean
*/

#include "Harl.hpp"

int main()
{
	Harl	harl;

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	return (0);
}