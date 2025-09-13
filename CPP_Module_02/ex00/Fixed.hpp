#pragma ONCE

#include <iostream>

class Fixed {
	private:
		int					fixedPointValue;
		static const int	nbFractionalBits = 8;
	public:
		Fixed();
		Fixed(const Fixed &obj);
		Fixed& operator=(const Fixed &obj);
		~Fixed();
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};