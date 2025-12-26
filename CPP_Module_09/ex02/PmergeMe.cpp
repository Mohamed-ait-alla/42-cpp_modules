// ****************************************************************************** //
//                        file: PmergeMe.cpp                                      //
//                        by: mait-all <mait-all@student.1337.ma>                 //
//                                                                                //
//                        Created: 2025/12/15 14:25 by mait-all                   //
//                        Updated: 2025/12/26 18:05 by mait-all                   //
// ****************************************************************************** //

#include "PmergeMe.hpp"

int	Int::compCount = 0;

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

Int::Int(const std::string& s) : _c(0), _value(0)
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

int	Int::getIndex()
{
	if (_c > 0)
		return (_idxs[--_c]);
	return (-1);
}

void	Int::saveIndex(int idx)
{
	if (_c < 35)
		_idxs[_c++] = idx;
}

bool	Int::operator<(const Int& other)
{
	compCount++;
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

size_t t_sequence(size_t k) {
	size_t powerOfTwo = (1 << (k + 1));
	int sign = (k % 2 == 0) ? 1 : -1;
	size_t jacobsthal_number = (powerOfTwo + sign) / 3;
	return jacobsthal_number - 1;
}

double	getCurrentTimeMicroseconds()
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000.0 + time.tv_usec);
}

void	display(std::vector<Int>& nums, int status)
{
	std::cout << (status ? "Before: " : "After: ");
	for (size_t i = 0; i < nums.size(); i++)
	{
		std::cout << nums[i].getValue() << " ";
	}
	std::cout << std::endl;
}

void	displayTimings(size_t size, double vectTime, double deqTime, int comparisons)
{
   std::cout << "Time to process a range of " << size
              << " elements with std::vector : " << vectTime << " us" << std::endl;
    std::cout << "Time to process a range of " << size
              << " elements with std::deque : " << deqTime << " us" << std::endl;

    std::cout << std::endl;
    std::cout << "number of comparisons: " << comparisons << std::endl;
}


/**
 * todo...
 * 
 * @param ac todo...
*/
void parseArguments(int ac, char **av, std::vector<Int>& vect, std::deque<Int>& deq)
{
    for (int i = 1; i < ac; i++)
    {
        if (!isValidArg(av[i]))
            throw std::invalid_argument("Error: invalid argument!");
        Int nb(av[i]);
        vect.push_back(nb);
        deq.push_back(nb);
    }
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
	std::deque<Int>		deq;

	parseArguments(ac, av, vect, deq);

	display(vect, 1);

	double	vectElapsedTime = sortAndTime(vect);

	Int::compCount = 0;
	double	deqElapsedTime = sortAndTime(deq);

	display(vect, 0);
	displayTimings(vect.size(), vectElapsedTime, deqElapsedTime, Int::compCount);

	// Verify sorting
	isSorted(vect);
	isSorted(deq);

}