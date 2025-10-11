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

	delete meta; delete i; delete j;

	std::cout << std::endl;
	std::cout << std::endl;

	// === lack of polymorphism tests ===
	const	WrongAnimal* wrongMeta = new WrongAnimal();
	const	WrongAnimal* wrongA = new WrongCat();

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Type of this Wrong Animal is: " << wrongA->getType() << " " << std::endl;
	wrongA->makeSound();
	wrongMeta->makeSound();

	std::cout << std::endl;
	std::cout << std::endl;
	 
	delete wrongMeta; delete wrongA;
	return (0);
}