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

#include <iostream>
#include <fstream>

int	main(int ac, char **av)
{
	std::ifstream	inFile;
	std::ofstream	outFile;
	std::string		line;
	std::string		newLine;
	std::string		target;
	
	// Check for invalid args
	if (!av || ac < 4)
	{
		std::cerr << "Usage: ./program <filename> <string1> <string2>" << std::endl;
		return (1);
	}
	inFile.open(av[1], std::ios::in);
	if (!inFile.is_open())
	{
		std::cerr << "Error: failed to open the file!" << std::endl;
		return (1);
	}
	outFile.open("result.replace", std::ios::out);
	if (!outFile.is_open())
	{
		std::cerr << "Error: failed to open the result file!" << std::endl;
		return  (1);
	}
	target = av[2];
	while (std::getline(inFile, line))
	{
		std::cout << "line is: " << line << std::endl;
		size_t i = 0;
		newLine = "";
		while(i < line.size())
		{
			if (line.substr(i, target.size()) == target)
			{
				newLine += av[3];
				i += target.size();
			}
			else
			{
				newLine += line[i];
				i++;
			}
		}
		outFile << newLine << '\n';
	}
	return (0);
}