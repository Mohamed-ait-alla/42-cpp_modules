/*
 * @author:
 * 			ToDo...
 * 
 * @github:
 * 			ToDo...
 * 
 * @description:
 * 			ToDo...
 * 
 * 
 * @usage:
 * 			ToDo...
 *
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