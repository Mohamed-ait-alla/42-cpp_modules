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
	// Test 1: vector container
	try
	{
		std::vector<int> v;
		for (int i = 0; i < 100; i++)
		{
			v.push_back(i+1);
		}
		int	found = easyfind(v, 99);
		std::cout << "Element " << found << " found in container" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	// Test 2: deque container
	try
	{
		std::deque<int> d;
		for (int i = 0; i < 10; i++)
		{
			d.push_back(i*2);
		}
		int found = easyfind(d, 19);
		std::cout << "Element " << found << " found in container" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	// Test 3: list container
	try
	{
		std::list<int> l;
		for(int i = 0; i < 20; i++)
		{
			l.push_back(i + 1);
		}
		int found = easyfind(l, 15);
		std::cout << "Element " << found << " found in container" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}