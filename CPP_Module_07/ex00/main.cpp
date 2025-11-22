/*
 * @author:
 * 			mait-all
 * 
 * @github:
 * 			https://github.com/Mohamed-ait-alla
 * 
 * @description:
 * 			ToDo...
 * 
 * 
 * @usage:
 * 			1. Compile:	make
 * 			2. Run:		./whatever
 * 			3. CleanUp:	make fclean
*/

#include "whatever.hpp"

int	main(void)
{

	std::string a = "hello";
	std::string b = "world";
	std::cout << "before => a: " << a << " b: " << b << std::endl;
	::swap<std::string>(a, b);
	std::cout << "after => a: " << a << " b: " << b << std::endl;
	return (0);
}