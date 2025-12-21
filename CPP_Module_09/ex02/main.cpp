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

#include "PmergeMe.hpp"

int	main(int ac, char** av)
{
	try
	{
		if (!av || ac <= 1)
			throw std::invalid_argument("Usage: ./PmergeMe [n1] [n2] [...] [n]");
		processInput(ac, av);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}