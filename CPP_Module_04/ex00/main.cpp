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

int main(void)
{
	const Animal* meta = new Animal();
	const Animal* i = new Dog();
	const Animal* j = new Cat();
	
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Type of this Animal is: " << i->getType() << " " << std::endl;
	std::cout << "Type of this Animal is: " << j->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;
	std::cout << std::endl;

	delete meta;
	delete i;
	delete j;
	return (0);
}