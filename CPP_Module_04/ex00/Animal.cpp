// ****************************************************************************************** //
//                               file: Animal.cpp                                             //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/08 08:51 by mait-all                        //
//                               Updated: 2025/10/08 09:03 by mait-all                        //
// ****************************************************************************************** //

#include "Animal.hpp"


// Default constructor
Animal::Animal() {
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