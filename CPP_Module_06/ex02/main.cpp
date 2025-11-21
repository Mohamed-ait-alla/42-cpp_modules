/*
 * @author:
 * 			ToDo...
 * 
 * @github:
 * 			ToDo...
 * 
 * @description:
 * 			ToDo...
 * 
 * 
 * @usage:
 * 			ToDo...
 *
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