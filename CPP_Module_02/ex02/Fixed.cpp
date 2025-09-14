#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	_fixedPointValue = 0;
}

// Copy constructor
Fixed::Fixed( const Fixed &obj )
{
	std::cout << "Copy constructor called" << std::endl;
	_fixedPointValue = obj._fixedPointValue;
}

// Parametrized constructor
Fixed::Fixed( int const intValue ) {
	std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = intValue << _fractionalBits;
}

// Parametrized constructor
Fixed::Fixed( float const floatValue ) {
	std::cout << "Float constructor called" << std::endl;
	_fixedPointValue = roundf(floatValue * (1 << _fractionalBits));
}

// Copy assignment operator
Fixed& Fixed::operator=( const Fixed &obj )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedPointValue = obj._fixedPointValue;
	return (*this);
}

// Destructor
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}


// member functions

// getter
int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixedPointValue);
}

// setter
void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}

// converting fixed points to floating point
float	Fixed::toFloat( void ) const {
	return ((float)_fixedPointValue / (float)(1 << _fractionalBits));
}

// converting fixed points to integers
int	Fixed::toInt( void ) const {
	return (_fixedPointValue >> _fractionalBits);
}

// (<<) insertion operator
std::ostream&	operator<<(std::ostream& cout, const Fixed& fixedObj) {
	return (cout << fixedObj.toFloat());
}