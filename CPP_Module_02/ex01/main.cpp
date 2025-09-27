/*
 * @author:
 * 			Mohamed Ait Alla
 * 
 * @description:
 * 				This exercise extends the ex00 Fixed class by adding two parameterized constructors:
 * 				one that takes an integer and one that takes a floating number. These constructors are
 * 				responsible for converting the input value into the internal fixed-point representation.
 * 				Two member functions are also introduced:
 * 					- toFloat(): converts the fixed-point value back into a float.
 * 					- toInt(): converts the fixed-point value back into a int.
 * 				The main goal of this exercise is to understand how constructors can provide multiple ways to
 * 				initialize objects (a first glimpse of polymorphism in c++), and how fixed-point numbers works.
 * 
 * @usage:
 * 			1.Compile:	make
 * 			2.Run:		./fixedPoint
 * 			3.Clean Up:	make fclean
*/

#include "Fixed.hpp"

int	main()
{
	Fixed	a;
	Fixed	const	b( 10 );
	Fixed	const	c( 42.42f );
	Fixed	const	d( b );

	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return (0);
}