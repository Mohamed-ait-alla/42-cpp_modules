/*
 * @author:
 * 			mait-all
 * 
 * @github:
 * 			https://github.com/Mohamed-ait-alla
 * 
 * @description:
 * 			This exercise focuses on runtime type identification (RTTI) in C++ using
 * 			dynamic_cast. A simple class hierarchy is implemented:
 * 
 * 				- Base (with a virtual destructor)
 * 				- A, B, C (three empty derived classes)
 * 
 * 			A generate() function is provided, which returns a pointer to a randomly
 * 			instantiated derived object.
 * 
 * 			Two identify() functions must be implemented:
 * 
 * 				- identify(Base* p)
 * 					Uses dynamic_cast on pointers. If the cast fails, the result is NULL.
 * 
 * 				- identify(Base& p)
 * 					Uses dynamic_cast on references. If the cast fails, a bad_cast
 * 					exception is thrown and must be caught with a try/catch block.
 * 
 * 			These functions determine the actual dynamic type of the randomly generated
 * 			object, demonstrating how dynamic_cast works with both pointer and reference
 * 			semantics.
 * 
 * 			The purpose of this exercise is to understand dynamic_cast type,
 * 			how it works, when it's useful, and it's behavior with pointers vs references.
 * 
 * @usage:
 * 			1. Compile:	make
 * 			2. Run:		./typeIdentifier
 * 			3. CleanUp:	make fclean
*/

#include "BaseFactory.hpp"

int main(void)
{

	Base* base = generate();
	identify(base);
	identify(*base);

	delete base;

	return (0);
}