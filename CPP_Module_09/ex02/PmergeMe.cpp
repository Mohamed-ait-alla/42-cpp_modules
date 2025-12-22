// ****************************************************************************** //
//                        file: PmergeMe.cpp                                      //
//                        by: mait-all <mait-all@student.1337.ma>                 //
//                                                                                //
//                        Created: 2025/12/15 14:25 by mait-all                   //
//                        Updated: 2025/12/22 11:47 by mait-all                   //
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

void	Int::saveIndex(int idx)
{
	if (_c < 35)
		_idxs[_c++] = idx; 
}

bool	Int::operator<(const Int& other)
{
	return (this->_value < other._value);
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


void	makePairs(std::vector<Int>& input, std::vector<Int>& a, std::vector<Int>& b)
{
	int	n = input.size() - 1;
	a.reserve(n / 2);
	a.reserve(n / 2 + 1);

	for (int i = 0; i < n; i += 2)
	{
		if (input[i] < input[i + 1])
		{
			input[i + 1].saveIndex(a.size());
			a.push_back(input[i + 1]);
			b.push_back(input[i]);
		}
		else
		{
			input[i].saveIndex(a.size());
			a.push_back(input[i]);
			b.push_back(input[i + 1]);
		}
	}
	
	// if there is an odd number add it to b
	if ((n + 1) % 2 != 0)
		b.push_back(input[n]);
}

void	mergeInsert(std::vector<Int>& input)
{
	// base case for recursion
	if (input.size() < 2)
		return ;

	std::vector<Int>	a; // store larger nums
	std::vector<Int>	b; // store small nums
	std::vector<Int>	restoredB;

	// step 1: make pairs and separate them into a (larger) and b (smaller)
	makePairs(input, a, b);

	// step 2: sort large elements recursively
	mergeInsert(a);

	std::cout << "a: ";
	for (size_t i = 0; i < a.size(); i++)
	{
		std::cout << a[i].getValue() << " ";
	}
	std::cout << "\nb: ";
	for (size_t i = 0; i < b.size(); i++)
	{
		std::cout << b[i].getValue() << " ";
	}

	std::cout << "\n\n";
	
	
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
	mergeInsert(vect);
	for (size_t i = 0; i < vect.size(); i++)
	{
		std::cout << vect[i].getValue() << " ";
	}
	std::cout << std::endl;
}