// ****************************************************************************************** //
//                               file: Fixed.hpp                                              //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/09/13 11:56 by mait-all                        //
// ****************************************************************************************** //

#pragma once

#include <iostream>
#include <ostream>
#include <cmath>


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
		Fixed( const Fixed &obj );
		Fixed& 	operator=( const Fixed &obj );
		~Fixed();

		// Parameterised constructors
		Fixed( int const intValue );
		Fixed( float const floatValue );

		// Member functions
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

};

std::ostream&	operator<<(std::ostream& output, const Fixed& fixedObj);