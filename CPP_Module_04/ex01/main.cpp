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
	std::cout << "==== creating array of Animals ====" << std::endl;

	Animal*	animals[6];
	for (int i = 0; i < 6; i++){
		if (i < 3)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << "\n==== Printing Animals types and sounds ====" << std::endl;
	for (int i = 0; i < 6; i++)
	{
		std::cout << "Animal " << i << " is a " << animals[i]->getType() << " and it says: ";
		animals[i]->makeSound();
	}

	std::cout << "\n==== Deleting Animals ====" << std::endl;
	for (int i = 0; i < 6; i++) {
		delete animals[i];
	}

	// deep copy test for dog
	std::cout << "\n==== Deep copy test: Dog ====" << std::endl;
	Dog	dog1;

	dog1.getBrain()->setIdea(0, "I want a bone");

	Dog	dog2 = dog1;

	std::cout << std::endl;
	std::cout << std::endl;

	dog2.getBrain()->setIdea(0, "I want to sleep");

	std::cout << "Dog1 Brain idea: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog2 Brain idea: " << dog2.getBrain()->getIdea(0) << std::endl;

	// deep copy test for cat
	std::cout << "\n==== Deep copy test: Cat ====" << std::endl;
	Cat cat1;

	cat1.getBrain()->setIdea(0, "I want to scratch the sofa");

	Cat cat2 = cat1;

	std::cout << std::endl;
	std::cout << std::endl;

	cat2.getBrain()->setIdea(0, "I want to eat");

	std::cout << "Cat1 Brain idea: " << cat1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat2 Brain idea: " << cat2.getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

	return (0);
}