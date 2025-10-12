// ****************************************************************************************** //
//                               file: Cat.cpp                                                //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/12 19:40 by mait-all                        //
//                               Updated: 2025/10/12 19:40 by mait-all                        //
// ****************************************************************************************** //

#include "Cat.hpp"

// Default constructor
Cat::Cat() {
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat: Default constructor called" << std::endl;
}

// Copy constructor
Cat::Cat(const Cat& other) : Animal(other) {
	this->brain = new Brain(*other.brain);
	std::cout << "Cat: Copy constructor called" << std::endl;
}

// Copy assignment operator
Cat&	Cat::operator=(const Cat& other) {
	Animal::operator=(other);
	if (this != &other)
		*this->brain = *other.brain;
	std::cout << "Cat: Copy assignment operator called" << std::endl;
	return (*this);
}

// Destructor
Cat::~Cat() {
	delete this->brain;
	std::cout << "Cat: Destructor called" << std::endl;
}


// --- Member functions ---
void	Cat::makeSound(void) const {
	std::cout << "!! meow meow !!" << std::endl;
}

Brain*	Cat::getBrain() const {
	return (brain);
}