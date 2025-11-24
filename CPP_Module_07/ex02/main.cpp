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
		// Test 1: Empty array
		Array<int> empty;
		std::cout << "Empty array size: " << empty.size() << std::endl;

		// Test 2: Array with elements
		Array<int> arr(5);
		std::cout << "Array size: " << arr.size() << std::endl;
				
		// Test 3: Fill and display
		for (unsigned int i = 0; i < arr.size(); i++)
		    arr[i] = i * 10;

		std::cout << "Array elements: ";
		for (unsigned int i = 0; i < arr.size(); i++)
		    std::cout << arr[i] << " ";
		std::cout << std::endl;

      // Test 4: Copy constructor
		Array<int> copy(arr);
		copy[0] = 999;
		std::cout << "Original[0]: " << arr[0] << std::endl;
		std::cout << "Copy[0]: " << copy[0] << std::endl;

		// Test 5: Out of bounds exception
		std::cout << "Accessing out of bounds..." << std::endl;
		std::cout << arr[10] << std::endl;  // Should throw

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}