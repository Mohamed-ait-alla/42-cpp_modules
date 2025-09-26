#pragma once

#include <iostream>

class Fixed {
	private:
		int					_fixedPointValue;
		static const int	_nbFractionalBits = 8;
	public:
		Fixed();
		Fixed(const Fixed &obj);
		Fixed& operator=(const Fixed &obj);
		~Fixed();
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};