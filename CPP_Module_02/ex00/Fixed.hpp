// ****************************************************************************************** //
//                               file: Fixed.hpp                                              //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/09/13 08:57 by mait-all                        //
// ****************************************************************************************** //

#pragma once

#include <iostream>


// ************************************************************************** //
//                                Fixed Class                                 //
// ************************************************************************** //

class Fixed {
	private:
		int					_fixedPointValue;
		static const int	_nbFractionalBits = 8;

	public:
		// OCF
		Fixed();
		Fixed(const Fixed &obj);
		Fixed& operator=(const Fixed &obj);
		~Fixed();
		// Member functions
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};