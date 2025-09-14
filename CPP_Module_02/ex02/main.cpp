/*
 * @author:
 *				TODO...
 * 
 * 
 * @description:
 * 				TODO...
 * 
 * @usage:
 * 				TODO...
*/

#include "Fixed.hpp"

int	main()
{
	Fixed a(12), b(4);
	
	std::cout << "Comparison operator: " << ((a > b) ? "true" : "false") << std::endl;
	std::cout << "Arithmetic operator: " << (a / b) << std::endl;
	return (0);
}