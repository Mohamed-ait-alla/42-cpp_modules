/*
 * @author:
 * 			mait-all
 *
 * @github:
 * 			https://github.com/Mohamed-ait-alla
 *
 * @description:
 *          ToDo...
 *
 * @usage:
 * 			1. Compile:	make
 * 			2. Run:		./easyFind
 * 			3. CleanUp:	make fclean
*/

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	try
	{
		if (ac != 2)
			throw std::invalid_argument("Usage: ./btc <file>");
		launch(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
    return (0);
}