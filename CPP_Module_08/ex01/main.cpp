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
		std::cout << "=== Basic Test ===" << std::endl;
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		// test if span is full, it should fail if yes
		// sp.addNumber(2);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n=== addRangeOfNumbers with vector ===" << std::endl;
		Span sp = Span(12);
		std::vector<int> numbers;

		for (int i = 0; i < 6; ++i)
			numbers.push_back((i + 1) * 5);

		sp.addRangeOfNumbers(numbers.begin(), numbers.end());
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n=== Large Dataset Test ===" << std::endl;
		Span bigSpan(10000);

		std::vector<int> bigNumbers;
		for (int i = 0; i < 10000; ++i)
			bigNumbers.push_back(i * 2);

		bigSpan.addRangeOfNumbers(bigNumbers.begin(), bigNumbers.end());
		std::cout << "10K numbers - Shortest: " << bigSpan.shortestSpan() << std::endl;
		std::cout << "10K numbers - Longest: " << bigSpan.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}