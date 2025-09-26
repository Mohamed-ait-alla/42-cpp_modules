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

// Parametrized constructor: Integer
Fixed::Fixed( int const intValue ) {
	std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = intValue << _nbFractionalBits;
}

// Parametrized constructor: Float
Fixed::Fixed( float const floatValue ) {
	std::cout << "Float constructor called" << std::endl;
	_fixedPointValue = roundf(floatValue * (1 << _nbFractionalBits));
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

// converting fixed points to floating number
float	Fixed::toFloat( void ) const {
	return ((float)_fixedPointValue / (float)(1 << _nbFractionalBits));
}

// converting fixed points to integer number
int	Fixed::toInt( void ) const {
	return (_fixedPointValue >> _nbFractionalBits);
}

// (<<) insertion operator
std::ostream&	operator<<(std::ostream& output, const Fixed& fixedObj) {
	return (output << fixedObj.toFloat());
}