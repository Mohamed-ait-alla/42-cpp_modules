/*
 * @author:
 *			TODO:...
 * 
 * @description:
 * 				TODO:...
 * 
 * 
 * 
 * @usage:
 * 			TODO:...
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

	// Declaration and initialization of variables
	std::string		line;
	std::string		fileName = av[1];
	std::string		resultFileName = fileName + ".replace";
	std::string		s1 = av[2];
	std::string		s2 = av[3];

	// Open files
	std::ifstream	inFile(fileName.c_str());
	if (!inFile)
		return (std::cerr << "Error: failed to open " << fileName << std::endl, -1);
	std::ofstream outFile(resultFileName.c_str());
	if (!outFile)
		return (std::cerr << "Error: failed to open " << resultFileName << std::endl, -1);

	// Proccessing fileName and replacing found occurrences
	while (std::getline(inFile, line))
	{
		outFile << replaceOccurrences(line, s1, s2);
	}

	inFile.close();
	outFile.close();
	return (0);
}