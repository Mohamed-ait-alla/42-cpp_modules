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
 * 			2. Run:		./array
 * 			3. CleanUp:	make fclean
*/

#include "Array.hpp"

int	main(void)
{

	try
	{
		Array<std::string> a(3);
		a[0] = "hello";
		a[1] = "world";
		a[2] = "again";

		Array<std::string> b(a);
		b[0] = "hh";
		b[1] = "hh";
		b[2] = "hh";
		// b[3] = "hh";
		// a = b;
	
		for (size_t i = 0; i < b.size(); i++)
		{
			std::cout << a[i] << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}