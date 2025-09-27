/*
 * @author:
 * 			Mohamed Ait Alla
 * 
 * @description:
 * 				In this exercise we extend the Fixed class with operator overloading and additional utility
 * 				functions. This makes the class behave more naturally in arithmetic and comparison contexts,
 * 				similar to built-in numeric types.
 * 				Implementations include:
 * 					- The 6 comparison operators (>, <, >=, <=, ==, !=).
 * 					- The 4 arithmetic operators (+, -, *, /).
 * 					- The 4 increment/decrement operators, both prefix and postfix.
 * 					- Some overloaded static functions, min() and max(), that return the smallest or largest of
 * 					  two Fixed objects.
 * 				This exercise illustrates how operator overloading provides intuitive syntax for user-defined
 * 				types, and how they work.
 * 
 * @usage:
 * 			1.Compile:	make
 * 			2.Run:		./fixedPoint
 * 			3.Clean Up:	make fclean
*/

#include "Fixed.hpp"

int main() {
	std::cout << "=== Comparison Operators ===" << std::endl;
	Fixed a(5.5f);
	Fixed b(10);

	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "(a < b): " << (a < b) << std::endl;
	std::cout << "(a > b): " << (a > b) << std::endl;
	std::cout << "(a <= b): " << (a <= b) << std::endl;
	std::cout << "(a >= b): " << (a >= b) << std::endl;
	std::cout << "(a == b): " << (a == b) << std::endl;
	std::cout << "(a != b): " << (a != b) << std::endl;

	std::cout << "\n=== Arithmetic Operators ===" << std::endl;
	Fixed c(2);
	Fixed d(3.5f);

	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "c + d = " << (c + d) << std::endl;
	std::cout << "c - d = " << (c - d) << std::endl;
	std::cout << "c * d = " << (c * d) << std::endl;
	std::cout << "c / d = " << (c / d) << std::endl;

	std::cout << "\n=== Increment/Decrement Operators ===" << std::endl;
	Fixed e;

	std::cout << "e = " << e << std::endl;
	std::cout << "++e = " << ++e << " (pre-increment)" << std::endl;
	std::cout << "e++ = " << e++ << " (post-increment)" << std::endl;
	std::cout << "After e++ -> e = " << e << std::endl;

	std::cout << "--e = " << --e << " (pre-decrement)" << std::endl;
	std::cout << "e-- = " << e-- << " (post-decrement)" << std::endl;
	std::cout << "After e-- -> e = " << e << std::endl;

	std::cout << "\n=== Static min/max Functions ===" << std::endl;
	Fixed f(42.42f);
	Fixed g(72.521f);

	std::cout << "f = " << f << ", g = " << g << std::endl;
	std::cout << "min(f, g) = " << Fixed::min(f, g) << std::endl;
	std::cout << "max(f, g) = " << Fixed::max(f, g) << std::endl;

	const Fixed h(100);
	const Fixed i(50);

	std::cout << "const min(h, i) = " << Fixed::min(h, i) << std::endl;
	std::cout << "const max(h, i) = " << Fixed::max(h, i) << std::endl;

	return 0;
}
