/*
 * @author:
 * 			mait-all
 * 
 * @github:
 * 			https://github.com/Mohamed-ait-alla
 * 
 * @description:
 * 			This program demonstrates the concept of runtime polymorphism in C++.
 * 
 * 			The Animal base class defines a virtual makeSound() function that is
 * 			overridden by its derived classes Dog and Cat. When called through
 * 			a base pointer or reference, the correct derived version is invoked
 * 			thanks to dynamic dispatch (or dynamic binding).
 * 
 * 			To contrast this behavior, the program also defines WrongAnimal and
 * 			WrongCat classes without virtual functions. Calling makeSound() through
 * 			a WrongAnimal pointer will result in static dispatch, showing that
 * 			the derived version is not called.
 * 
 * 			This exercise highlights the importance of virtual functions in achieving
 * 			polymorphic behavior.
 * 
 * @usage:
 * 			1. Compile:	make
 * 			2. Run:		./polymorphism
 * 			3. CleanUp:	make fclean
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