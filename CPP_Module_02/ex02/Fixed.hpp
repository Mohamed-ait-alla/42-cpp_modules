#pragma once

#include <iostream>
#include <ostream>
#include <cmath>

class Fixed {
	private:
		int					_fixedPointValue;
		static const int	_nbFractionalBits = 8;
	public:
		Fixed();
		Fixed( int const intValue );
		Fixed( float const floatValue );
		Fixed( const Fixed &obj );
		~Fixed();

		Fixed&				operator=( const Fixed &obj );

		// Comparison operator overloading declarations
		bool				operator>( const Fixed& obj ) const;
		bool				operator<( const Fixed& obj ) const;
		bool				operator>=( const Fixed& obj ) const;
		bool				operator<=( const Fixed& obj ) const;
		bool				operator==( const Fixed& obj ) const;
		bool				operator!=( const Fixed& obj ) const;

		// Arithmetic operator overloading declarations
		Fixed				operator+( const Fixed& obj ) const;
		Fixed				operator-( const Fixed& obj ) const;
		Fixed				operator*( const Fixed& obj ) const;
		Fixed				operator/( const Fixed& obj ) const;

		// Increment/Decrement operator overloading declarations
		Fixed&				operator++();
		Fixed&				operator--();
		Fixed				operator++(int);
		Fixed				operator--(int);

		// Static function overloading declarations
		static Fixed&		min(Fixed& a, Fixed& b);
		static Fixed&		max(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);

		// member function declarations
		int					getRawBits( void ) const;
		void				setRawBits( int const raw );
		float				toFloat( void ) const;
		int					toInt( void ) const;
};

std::ostream&	operator<<(std::ostream& cout, const Fixed& fixedObj);