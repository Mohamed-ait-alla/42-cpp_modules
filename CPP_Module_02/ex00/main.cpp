/*
 * @author:
 * 			Mohamed Ait Alla
 * 
 * @description:
 * 				This exercise introduces the Orthodox Canonical Form and the concept of fixed-point numbers.
 * 				The Fixed class implemented with the 4 canonical form functions (constructor, copy constructor,
 * 				copy assignment operator, destructor). At this stage, the class can only represent the constant
 * 				value 0.0 in fixed-point form.
 * 
 * @usage:
 * 			1.Compile:	make
 * 			2.Run:		./fixedPoint
 * 			3.Clean Up:	make fclean
*/

#include "Fixed.hpp"

int	main()
{
	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return (0);
}