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
 * @usage:
 * 			1. Compile:	make
 * 			2. Run:		./array
 * 			3. CleanUp:	make fclean
*/

#include "easyfind.hpp"

int	main(void)
{
	try
	{
		std::vector<int> v;
		v.push_back(3);
		v.push_back(4);
		v.push_back(2);
		v.push_back(7);
		int	found = easyfind(v, 0);
		std::cout << "Element " << found << " found in container" << std::endl;  
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	


	return (0);
}