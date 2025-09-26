#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() {
	_fixedPointValue = 0;
}

// Copy constructor
Fixed::Fixed( const Fixed &obj ) {
	_fixedPointValue = obj._fixedPointValue;
}

// Parametrized constructor
Fixed::Fixed( int const intValue ) {
	_fixedPointValue = intValue << _nbFractionalBits;
}

// Parametrized constructor
Fixed::Fixed( float const floatValue ) {
	_fixedPointValue = roundf(floatValue * (1 << _nbFractionalBits));
}

// Copy assignment operator
Fixed& Fixed::operator=( const Fixed &obj ) {
	this->_fixedPointValue = obj._fixedPointValue;
	return (*this);
}

// Destructor
Fixed::~Fixed() {}

// ---- Ex02 ----

// Comparison operator overloading definitions
bool	Fixed::operator>( const Fixed& obj ) const {
	return (this->_fixedPointValue > obj._fixedPointValue);
}

bool	Fixed::operator>=( const Fixed& obj ) const {
	return (this->_fixedPointValue >= obj._fixedPointValue);
}

bool	Fixed::operator<( const Fixed& obj ) const {
	return (this->_fixedPointValue < obj._fixedPointValue);
}

bool	Fixed::operator<=( const Fixed& obj ) const {
	return (this->_fixedPointValue <= obj._fixedPointValue);
}

bool	Fixed::operator==( const Fixed& obj ) const {
	return (this->_fixedPointValue == obj._fixedPointValue);
}

bool	Fixed::operator!=( const Fixed& obj ) const {
	return (this->_fixedPointValue != obj._fixedPointValue);
}

// Arithmetic operator overloading definitions
Fixed	Fixed::operator+( const Fixed& obj ) const {
	return Fixed(this->toFloat() + obj.toFloat());
}

Fixed	Fixed::operator-( const Fixed& obj ) const {
	return Fixed(this->toFloat() - obj.toFloat());
}

Fixed	Fixed::operator*( const Fixed& obj ) const {
	return Fixed(this->toFloat() * obj.toFloat());
}

Fixed	Fixed::operator/( const Fixed& obj) const {
	return Fixed(this->toFloat() / obj.toFloat());
}

// Increment/Decrement operator overloading definitions
Fixed&	Fixed::operator++() {
	this->_fixedPointValue++;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp = *this;
	this->_fixedPointValue++;
	return (tmp);
}

Fixed&	Fixed::operator--() {
	this->_fixedPointValue--;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp = *this;
	this->_fixedPointValue--;
	return (tmp);
}


// member functions

// static function overloading definitions
Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	return ((a < b) ? a : b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	return ((a > b) ? a : b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
	return (((Fixed)a < b) ? a : b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
	return (((Fixed)a > b) ? a : b);
}

// getter
int	Fixed::getRawBits( void ) const {
	return (_fixedPointValue);
}

// setter
void	Fixed::setRawBits( int const raw ) {
	this->_fixedPointValue = raw;
}

// converting fixed points to floating point
float	Fixed::toFloat( void ) const {
	return ((float)_fixedPointValue / (float)(1 << _nbFractionalBits));
}

// converting fixed points to integers
int	Fixed::toInt( void ) const {
	return (_fixedPointValue >> _nbFractionalBits);
}

// (<<) insertion operator
std::ostream&	operator<<(std::ostream& cout, const Fixed& fixedObj) {
	return (cout << fixedObj.toFloat());
}