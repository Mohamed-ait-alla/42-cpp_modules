// ****************************************************************************** //
//                        file: Span.cpp                                          //
//                        by: mait-all <mait-all@student.1337.ma>                 //
//                                                                                //
//                        Created: 2025/11/28 08:57 by mait-all                   //
//                        Updated: 2025/11/28 20:28 by mait-all                   //
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