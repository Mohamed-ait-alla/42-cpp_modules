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

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	Dog	dog1;

	dog1.getBrain()->setIdea(0, "hh hh hh");

	Dog dog2 = dog1;
	dog2.getBrain()->setIdea(0, "jj jj jj");

	std::cout << "dog1 idea is: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "dog2 idea is: " << dog2.getBrain()->getIdea(0) << std::endl;
	return (0);
}