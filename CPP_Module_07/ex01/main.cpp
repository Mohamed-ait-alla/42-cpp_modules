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
 * 			2. Run:		./iter
 * 			3. CleanUp:	make fclean
*/

#include "iter.hpp"


// testing helper functions
void	duplicateInt(int& i) { i *= 2; }
void	duplicateFloat(float& f) { f *= 2; }
void	incrementChar(char& c) { c += 1; }
void	concatenate(std::string& s) { s += " world"; }
void	printInt(const int& i) { std::cout << i << std::endl; }
void	printChar(const char& c) { std::cout << c << std::endl; }
void	printFloat(const float& f) { std::cout << f << std::endl; }
void	printString(const std::string& s) { std::cout << s << std::endl; }

int	main(void)
{
	// declaring arrays
	int			intArray[] = {1, 2, 3};
	char		charArray[] = {'a', 'b', 'c'};
	float		floatArray[] = {1.1, 1.2, 1.3};
	std::string	stringArray[] = {"hello", "hello", "hello"};

	// calling iter template on each type: duplicating
	iter(intArray, 3, duplicateInt);
	iter(charArray, 3, incrementChar);
	iter(floatArray, 3, duplicateFloat);
	iter(stringArray, 3, concatenate);

	// calling iter template on each type: displaying
	iter(intArray, 3, printInt);
	iter(charArray, 3, printChar);
	iter(floatArray, 3, printFloat);
	iter(stringArray, 3, printString);


	return (0);
}