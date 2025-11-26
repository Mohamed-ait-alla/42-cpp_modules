/*
 * @author:
 * 			mait-all
 *
 * @github:
 * 			https://github.com/Mohamed-ait-alla
 *
 * @description:
 * 			This exercise introduces function templates in C++. Templates allow writing
 * 			generic code that works with any data type, as long as the required operators
 * 			are supported by that type.
 * 
 * 			The header defines three fundamental template functions:
 * 
 * 				- swap<T>(T& a, T& b)
 * 						Exchanges the values of two variables of the same type T.
 * 
 * 				- min<T>(T a, T b)
 * 						Returns the smaller of the two values.
 * 
 * 				- max<T>(T a, T b)
 * 						Returns the larger of the two values.
 * 
 * 			This exercise serves as an introduction to template syntax, type deduction,
 * 			and how the compiler generates concrete versions of template functions at
 * 			compile time (template instantiation).
 *
 * @usage:
 * 			1. Compile:	make
 * 			2. Run:		./whatever
 * 			3. CleanUp:	make fclean
*/

#include "whatever.hpp"

int	main(void)
{
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	return 0;
}