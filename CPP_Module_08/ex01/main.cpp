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
 * 			2. Run:		./span
 * 			3. CleanUp:	make fclean
*/

#include "Span.hpp"

int	main(void)
{
	try
	{
		Span sp(3);
		std::vector<int> v;
		for (size_t i = 0; i < 20; i++)
		{
			v.push_back(i);
		}
		sp.addRangeOfNumbers(v.begin(), v.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}