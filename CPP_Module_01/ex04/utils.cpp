#include "utils.hpp"

std::string	replaceOccurrences(std::string fileContent, const std::string& s1, const std::string& s2)
{
	if (fileContent.empty() || s1.empty())
		return "";

	size_t pos = 0;
	while ((pos = fileContent.find(s1, pos)) != std::string::npos)
	{
		fileContent.erase(pos, s1.length());
		fileContent.insert(pos, s2);
		pos += s2.length();
	}
	return fileContent;
}

