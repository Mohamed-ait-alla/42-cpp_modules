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
		Span sp = Span(5);
		// std::vector<int> v;
		// for (size_t i = 0; i < 10; i++)
		// {
		// 	v.push_back(i+1);
		// }
		// sp.addRangeOfNumbers(v.begin(), v.end());
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}