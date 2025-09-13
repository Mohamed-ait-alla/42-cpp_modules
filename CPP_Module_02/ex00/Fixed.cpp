#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	fixedPointValue = 0;
}

// Copy constructor
Fixed::Fixed( const Fixed &obj )
{
	std::cout << "Copy constructor called" << std::endl;
	fixedPointValue = obj.fixedPointValue;
}

// Copy assignment operator
Fixed& Fixed::operator=( const Fixed &obj )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixedPointValue = obj.fixedPointValue;
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
	return (fixedPointValue);
}

// setter
void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedPointValue = raw;
}