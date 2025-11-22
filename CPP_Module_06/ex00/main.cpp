/*
 * @author:
 * 			mait-all
 * 
 * @github:
 * 			https://github.com/Mohamed-ait-alla
 * 
 * @description:
 * 			This exercise introduces scalar type conversion in C++ through the
 * 			implementation of a ScalarConverter class. The class provides a single
 * 			static member function:
 * 				
 * 				- static void	convert(std::string& input)
 * 			
 * 			The function is responsible for detecting the input's actual type
 * 			(char, int, float, or double) and converting it into all corresponding
 * 			scalar representations.
 * 
 * 			The key objective of this exercise is to understand the use of static_cast
 * 			type, how it works, and when to use it.
 * 
 * @usage:
 * 			1. Compile:	make
 * 			2. Run:		./scalarConverter
 * 			3. CleanUp:	make fclean
*/

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    try
    {
		if (av && ac == 2)
		{
			std::string input = av[1];
            ScalarConverter::convert(input);
		}
		else
			throw std::invalid_argument("Too many arguments!");
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << '\n';
    }
    
    return (0);
}