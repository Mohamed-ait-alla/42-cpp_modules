/*
* @author:
* 			mait-all
* 
* @github:
* 			https://github.com/Mohamed-ait-alla
* 
* @description:
* 			This program takes command line arguments and converts them to uppercase.
* 			If no arguments are specified, it shows a default message.
* 
* @usage:
* 			./megaphone [arg1] [arg2] [...] [argn]
*/

#include <iostream>

int	main(int ac, char **av)
{
	if (ac != 1)
	{
		for (int i = 1; i < ac; i++)
		{
			for (int j = 0; av[i][j] != '\0'; j++)
				std::cout << (char)toupper(av[i][j]);
			std::cout << " ";
		}
		std::cout << "\n";
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	return (0);
}
