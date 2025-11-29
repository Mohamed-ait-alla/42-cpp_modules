// ****************************************************************************** //
//                        file: Span.cpp                                          //
//                        by: mait-all <mait-all@student.1337.ma>                 //
//                                                                                //
//                        Created: 2025/11/28 08:57 by mait-all                   //
//                        Updated: 2025/11/29 11:30 by mait-all                   //
// ****************************************************************************** //

#include "Span.hpp"


// -------------------------------
// Orthodox Canonical Form
// -------------------------------

// Default constructor
Span::Span() : _maxSize(0)
{
}

// Parametrised constructor
Span::Span(unsigned int N) : _maxSize(N)
{
}

// Copy constructor
Span::Span(const Span& other) : _vect(other._vect), _maxSize(other._maxSize)
{
}

// Copy assignment operator
Span&	Span::operator=(const Span& other)
{
	if (this != &other)
	{
		this->_vect = other._vect;
		this->_maxSize = other._maxSize;
	}
	return (*this);
}

// Destructor
Span::~Span()
{
}


// -------------------------------
// Member functions
// -------------------------------

// add a number to the span
void	Span::addNumber(int nb)
{
	if (_vect.size() >= _maxSize)
		throw std::out_of_range("Error: No space left in span to add a new number!");
	_vect.push_back(nb);
}

// find the shortest span between all stored numbers
int	Span::shortestSpan(void)
{
	if (_vect.size() <= 1)
		throw std::runtime_error("Error: Not enough elements!");
	std::sort(_vect.begin(), _vect.end());
	int	diff;
	int	min_diff = _vect[1] - _vect[0];
	for (size_t i = 1; i < _vect.size() - 1; i++)
	{
		diff = _vect[i + 1] - _vect[i];
		if (diff <= min_diff)
			min_diff = diff;
	}
	return (min_diff);
}

// find the longest span between all stored numbers
int	Span::longestSpan(void)
{
	int	min;
	int	max;

	if (_vect.size() <= 1)
		throw std::runtime_error("Error: Not enough elements!");
	min = *(std::min_element(_vect.begin(), _vect.end()));
	max = *(std::max_element(_vect.begin(), _vect.end()));
	return (max - min);
}