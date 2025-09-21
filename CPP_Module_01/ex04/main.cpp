/*
 * @author:
 * 			Mohamed Ait Alla
 * 
 * @description:
 * 				This exercise focuses on file manipulation in c++.
 * 				The program takes three arguments:
 * 					1. The name of the input file
 * 					2. The string to search for (s1)
 * 					3. The string to replace it with (s2)
 * 				It creates a new file with the same name as the input file, suffixed
 * 				with ".replace", where every occurrence of s1 is replaced by s2.
 * 
 * @usage:
 * 			1. Compile:		make
 * 			2. Run:			./sed_is_for_losers <filename> <s1> <s2>
 * 			3. Clean up:	make clean
 * 			4. Full clean:	make fclean
*/

#include "utils.hpp"

int	main(int ac, char **av)
{
	// Check for invalid args
	if (ac != 4)
	{
		std::cerr << "Usage: ./program <filename> <string1> <string2>" << std::endl;
		return (1);
	}

	// Declaration & initialization of variables
	std::string		line;
	std::string		fileName = av[1];
	std::string		resultFileName = fileName + ".replace";
	std::string		s1 = av[2];
	std::string		s2 = av[3];

	// Open files
	std::ifstream	inFile(fileName.c_str());
	if (!inFile)
		return (std::cerr << "Error: failed to open \"" << fileName << "\" file" << std::endl, -1);
	std::ofstream outFile(resultFileName.c_str());
	if (!outFile)
		return (std::cerr << "Error: failed to open \"" << resultFileName << "\" file" << std::endl, -1);

	// Proccessing fileName and replacing found occurrences
	while (std::getline(inFile, line))
	{
		outFile << replaceOccurrences(line, s1, s2);
	}

	inFile.close();
	outFile.close();
	return (0);
}