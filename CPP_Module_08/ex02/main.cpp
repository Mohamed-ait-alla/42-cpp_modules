/*
 * @author:
 * 			mait-all
 *
 * @github:
 * 			https://github.com/Mohamed-ait-alla
 *
 * @description:
 * 			This exercise introduces an iterable version of the standard
 * 			std::stack container. Since std::stack does not provide iterator
 * 			support, the goal is to create a class template called MutantStack
 * 			that behaves exactly like a stack but exposes iterators to allow
 * 			traversal of its underlying container.
 *
 * 			Key characteristics:
 *
 * 				- MutantStack<T> inherits from std::stack<T>
 * 				- Provides iterator access through:
 * 					-> begin()
 * 					-> end()
 * 					-> begin() const
 * 					-> end() const
 *
 * 				- The underlying container of std::stack
 * 				  (std::deque by default) already supports iterators, but they
 * 				  are not exposed. MutantStack makes them accessible by
 * 				  returning iterators from the protected member c.
 * 
 * 			This exercise focuses on:
 * 				- Understanding container adaptors like std::stack
 * 				- How inheritance can expose otherwise hidden features
 * 				- Working with iterator typedefs from the underlying container
 *
 * @usage:
 * 			1. Compile:	make
 * 			2. Run:		./mutantStack
 * 			3. CleanUp:	make fclean
*/

#include "MutantStack.hpp"

int	main(void)
{
	{
		std::cout << "\n" << "MutantStack test test!!" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "mstack.top() "<< mstack.top() << std::endl;
		mstack.pop();
		std::cout << "mstack.size() " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << "\t";
			++it;
		}
	}
		
	{
		std::cout << "\n" << std::endl << "Test against another container!!" << std::endl;
		std::list<int> list;
		list.push_back(5);
		list.push_back(17);
		std::cout << "list.back() " << list.back() << std::endl;
		list.pop_back();
		std::cout << "list.size() " << list.size() << std::endl;
		list.push_back(3);
		list.push_back(5);
		list.push_back(737);
		list.push_back(0);
		std::list<int>::iterator it = list.begin();
		std::list<int>::iterator ite = list.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << "\t";
			++it;
		}
		std::cout << std::endl;
	}

	{
		std::cout << "\n" << std::endl << "Test with const object" << std::endl;
		MutantStack<char> mstack;
		mstack.push('a');
		mstack.push('b');
		mstack.push('c');
		mstack.push('d');
		mstack.push('e');

		const MutantStack<char> const_stack(mstack);
		MutantStack<char>::const_iterator it = const_stack.begin();
		MutantStack<char>::const_iterator ite = const_stack.end();

		std::cout << "const_stack.top() '" << const_stack.top() << "'" << std::endl;
		std::cout << "const_stack.size() " << const_stack.size() << std::endl;
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << "\t";
			++it;
		}
		std::cout << std::endl;
	}

	return (0);
}