/*
 * @author:
 * 			mait-all
 *
 * @github:
 * 			https://github.com/Mohamed-ait-alla
 *
 * @description:
 *          ToDo...
 *
 * @usage:
 * 			1. Compile:	make
 * 			2. Run:		./easyFind
 * 			3. CleanUp:	make fclean
*/

#include "RPN.hpp"

int	main(int ac, char **av)
{
	try
	{
		(void)av;
		if (ac != 2)
			throw std::invalid_argument("\nUsage: ./RPN <RPN_Expression>\n----- ----- ----- ----- -----\nExample: ./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\"\n");
		evaluateRPN(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}