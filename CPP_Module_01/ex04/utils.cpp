#include "utils.hpp"

std::string replaceOccurrences(std::string& line, std::string& s1, std::string& s2)
{
	std::string	newLine = "";
	size_t		i = 0;

	if (line.empty() || s1.empty() || s2.empty())
		return ("");
	while (i < line.size())
	{
		if (line.substr(i, s1.size()) == s1)
		{
			newLine += s2;
			i += s1.size();
		}
		else
		{
			newLine += line[i];
			i++;
		}
	}
	return (newLine + '\n');
}
