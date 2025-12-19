// ****************************************************************************** //
//                        file: PmergeMe.cpp                                      //
//                        by: mait-all <mait-all@student.1337.ma>                 //
//                                                                                //
//                        Created: 2025/12/15 14:25 by mait-all                   //
//                        Updated: 2025/12/19 10:30 by mait-all                   //
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


bool	compare(size_t a, size_t b)
{
	return (a < b);
}

void	swapPair(std::vector<int>& _vect, int leftPair, int rightPair, int pairLevel)
{
	for (int i = 0; i < pairLevel; i++)
	{
		std::swap(_vect[leftPair - i], _vect[rightPair - i]);
	}
}


/**
 * todo...
 * 
 * 
 * @param input todo...
*/
void	mergeInsertionSort(std::vector<int>& input, int pairLevel)
{
	int totalPairs = input.size() / pairLevel;

	if (totalPairs < 2)
		return ;

	// step 1: devide into pairs && sorting those pairs
	bool hasOdd = (totalPairs % 2 != 0);

	int	pairsToCompare = hasOdd ? totalPairs - 1 : totalPairs;

	for (int i = 0; i < pairsToCompare ; i += 2)
	{
		// get the last indexes in each pair 
		int	leftPairLast = (i + 1) * pairLevel - 1;
		int	rightPairLast = (i + 2) * pairLevel - 1;

		// compare and swap
		if (compare(input[rightPairLast], input[leftPairLast]))
			swapPair(input, leftPairLast, rightPairLast, pairLevel);
	}

	mergeInsertionSort(input, pairLevel * 2);

	// step 2: insertion

	




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

	mergeInsertionSort(_vect, 1);
	for (size_t i = 0; i < _vect.size(); i++)
	{
		std::cout << _vect[i] << " ";
	}

	// std::cout << std::endl;
	// std::cout << std::endl;
	
	// for (size_t i = 0; i < _deq.size(); i++)
	// {
	// 	std::cout << _deq[i] << " ";
	// }
	// std::cout << std::endl;
	
}