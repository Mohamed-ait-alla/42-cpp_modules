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

	std::cout << "----------------------- swap template test -----------------------" << std::endl;
	std::cout << std::endl;
	{
		std::string a = "hello";
		std::string b = "world";
		std::cout << "before => a: " << a << " b: " << b << std::endl;
		::swap<std::string>(a, b);
		std::cout << "after => a: " << a << " b: " << b << std::endl;
	}
	std::cout << std::endl;

	std::cout << "----------------------- min max templates test -----------------------" << std::endl;
	std::cout << std::endl;
	{
		int a = 6;
		int b = 4;
	
		std::cout << "min is: " << ::min<int>(a, b) << std::endl;
		std::cout << "max is: " << ::max<int>(a, b) << std::endl;
	}
	std::cout << std::endl;


	return (0);
}