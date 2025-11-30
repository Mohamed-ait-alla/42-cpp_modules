/*
 * @author:
 * 			mait-all
 *
 * @github:
 * 			https://github.com/Mohamed-ait-alla
 *
 * @description:
 * 			ToDo...
 *
 * @usage:
 * 			1. Compile:	make
 * 			2. Run:		./mutatedAbomination
 * 			3. CleanUp:	make fclean
*/

#include "MutantStack.hpp"

int	main(void)
{
	MutantStack<int> mstack;

	mstack.push(3);
	mstack.push(4);
	mstack.push(2);
	mstack.push(1);

	MutantStack<int>::iterator it;
	MutantStack<int>::iterator ite = mstack.end();

	for (it = mstack.begin(); it != ite; it++)
	{
		std::cout << *it << " ";
	}

	return (0);
}