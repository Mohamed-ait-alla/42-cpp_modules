// ****************************************************************************** //
//                        file: PmergeMe.cpp                                      //
//                        by: mait-all <mait-all@student.1337.ma>                 //
//                                                                                //
//                        Created: 2025/12/15 14:25 by mait-all                   //
//                        Updated: 2025/12/21 18:36 by mait-all                   //
// ****************************************************************************** //

#include "PmergeMe.hpp"

Int::Int(int val) : _c(0), _value(val)
{
	std::memset(_idxs, 0, sizeof(_idxs));
}

Int::Int(const Int& other) : _c(other._c), _value(other._value)
{
	std::memcpy(_idxs, other._idxs, sizeof(_idxs));
}

Int&	Int::operator=(const Int& other)
{
	if (this != &other)
	{
		_value = other._value;
		_c = other._c;
		std::memcpy(_idxs, other._idxs, sizeof(_idxs));
	}
	return (*this);
}

Int::Int(const std::string& s)
{
	std::memset(_idxs, 0, sizeof(_idxs));
	_value = atoi(s.c_str());
}

Int::~Int()
{
}

int	Int::getValue()
{
	return (_value);
}

/**
 * todo...
 *
 *
 * @param ac todo...
 * @param av todo...
 */
bool isValidArg(std::string arg)
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
void processInput(int ac, char **av)
{
	std::vector<Int>	vect;

	for (int i = 1; i < ac; i++)
	{
		if (!isValidArg(av[i]))
			throw std::invalid_argument("Error: invalid argument");
		Int	nb(av[i]);
		vect.push_back(nb);
	}

	for (size_t i = 0; i < vect.size(); i++)
	{
		std::cout << vect[i].getValue() << " ";
	}
	std::cout << std::endl;
}