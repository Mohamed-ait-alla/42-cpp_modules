// ****************************************************************************************** //
//                               file: Dog.cpp                                                //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/11 20:04 by mait-all                        //
//                               Updated: 2025/10/11 20:04 by mait-all                        //
// ****************************************************************************************** //

#include "Dog.hpp"


// Default constructor
Dog::Dog() {
	this->type = "Dog";
	std::cout << "Dog: Default constructor called" << std::endl;
}

// Copy constructor
Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog: Copy constructor called" << std::endl;
}

// Copy assignment operator
Dog&	Dog::operator=(const Dog& other) {
	Animal::operator=(other);
	std::cout << "Dog: Copy assignment operator called" << std::endl;
	return (*this);
}

// Destructor
Dog::~Dog() {
	std::cout << "Dog: Destructor called" << std::endl;
}

// --- Member functions ---
void	Dog::makeSound(void) const {
	std::cout << "!! bark bark !!" << std::endl;
}