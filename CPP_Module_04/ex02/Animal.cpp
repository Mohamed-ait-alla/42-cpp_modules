// ****************************************************************************************** //
//                               file: Animal.cpp                                             //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/12 19:40 by mait-all                        //
//                               Updated: 2025/10/12 19:40 by mait-all                        //
// ****************************************************************************************** //

#include "Animal.hpp"


// Default constructor
Animal::Animal() {
	this->type = "unkown";
	std::cout << "Animal: Default constructor called" << std::endl;
}

// Copy constructor
Animal::Animal(const Animal& other) {
	this->type = other.type;
	std::cout << "Animal: Copy constructor called" << std::endl;
}

// Copy assignment operator
Animal&	Animal::operator=(const Animal& other) {
	this->type = other.type;
	std::cout << "Animal: Copy assignment operator called" << std::endl;
	return (*this);
}

// Destructor
Animal::~Animal() {
	std::cout << "Animal: Destructor called" << std::endl;
}

// --- Member functions ---
void	Animal::makeSound(void) const {
	std::cout << "!! No default animal sound !!" << std::endl;
}

std::string	Animal::getType(void) const {
	return (type);
}