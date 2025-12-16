// ****************************************************************************** //
//                        file: PmergeMe.cpp                                      //
//                        by: mait-all <mait-all@student.1337.ma>                 //
//                                                                                //
//                        Created: 2025/12/15 14:25 by mait-all                   //
//                        Updated: 2025/12/16 14:45 by mait-all                   //
// ****************************************************************************** //

#include "PmergeMe.hpp"

/**
 * todo...
 * 
 * 
 * @param ac todo...
 * @param av todo...
*/
bool	isValidArg(std::string arg)
{
	double	toDouble;

	if (arg.empty() || (arg.find_first_not_of("0123456789") != std::string::npos))
		return (false);
	toDouble = std::strtod(arg.c_str(), 0);
	if (toDouble > std::numeric_limits<int>::max())
		return (false);
	return (true);
}

/**
 * todo...
 * 
 * 
 * @param ac todo...
 * @param av todo...
*/
void	processInput(int ac, char **av)
{
	std::vector<int>	_vect;
	std::deque<int>		_deq;

	if (!av)
		throw std::runtime_error("Error");
	for (int i = 1; i < ac; i++)
	{
		if (!isValidArg(av[i]))
			throw std::invalid_argument("Error: invalid argument");
		_vect.push_back(atoi(av[i]));
		_deq.push_back(atoi(av[i]));
	}

	for (size_t i = 0; i < _vect.size(); i++)
	{
		std::cout << _vect[i] << " ";
	}

	std::cout << std::endl;
	std::cout << std::endl;
	
	for (size_t i = 0; i < _deq.size(); i++)
	{
		std::cout << _deq[i] << " ";
	}
	std::cout << std::endl;
	
}