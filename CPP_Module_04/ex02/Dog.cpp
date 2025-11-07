// ****************************************************************************************** //
//                               file: Dog.cpp                                                //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/12 19:40 by mait-all                        //
//                               Updated: 2025/11/07 11:36 by mait-all                        //
// ****************************************************************************************** //

#include "Dog.hpp"


// Default constructor
Dog::Dog() {
	this->type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog: Default constructor called" << std::endl;
}

// Copy constructor
Dog::Dog(const Dog& other) : AAnimal(other) {
	this->_brain = new Brain(*other._brain);
	std::cout << "Dog: Copy constructor called" << std::endl;
}

// Copy assignment operator
Dog&	Dog::operator=(const Dog& other) {
	if (this == &other)
		return (*this);
	AAnimal::operator=(other);
	*this->_brain = *other._brain;
	std::cout << "Dog: Copy assignment operator called" << std::endl;
	return (*this);
}

// Destructor
Dog::~Dog() {
	delete this->_brain;
	std::cout << "Dog: Destructor called" << std::endl;
}


// --- Member functions ---
void	Dog::makeSound(void) const {
	std::cout << "!! bark bark !!" << std::endl;
}

Brain*	Dog::getBrain() const {
	return (_brain);
}