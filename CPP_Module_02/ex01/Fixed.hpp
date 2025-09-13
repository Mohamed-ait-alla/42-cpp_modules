#pragma once

#include <iostream>
#include <ostream>
#include <cmath>

class Fixed {
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;
	public:
		Fixed();
		Fixed( int const intValue );
		Fixed( float const floatValue );
		Fixed( const Fixed &obj );
		~Fixed();
		Fixed& 	operator=( const Fixed &obj );
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

};

std::ostream&	operator<<(std::ostream& cout, const Fixed& fixedObj);