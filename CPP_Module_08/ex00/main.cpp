/*
 * @author:
 * 			mait-all
 *
 * @github:
 * 			https://github.com/Mohamed-ait-alla
 *
 * @description:
 * 			This exercise introduces the use of STL containers, algorithms, and
 * 			iterators in modern C++. You must implement a function template
 * 			called easyfind() that performs a simple search operation on any
 * 			container holding integers.
 *
 * 			The function prototype:
 * 				- easyfind(T& container, int toFind)
 *
 * 			Behavior:
 * 				- Uses an STL algorithm (in my implementation I used std::find) to
 * 				  search for the integer 'toFind' inside the given container.
 *
 * 				- If the 'toFind' is found, the function prints a confirmation message.
 *
 * 				- If the 'toFind' cannot be found, the function throws an exception.
 *
 * 			This exercise helps you understand:
 * 				- How to write template functions that accept any STL container
 * 				- How iterators allow generic access to container elements
 * 				- How STL algorithms (like std::find) operate independently of
 * 				  container type
 *
 * @usage:
 * 			1. Compile:	make
 * 			2. Run:		./easyFind
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