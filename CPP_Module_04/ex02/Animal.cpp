// ****************************************************************************************** //
//                               file: Animal.cpp                                             //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/12 19:40 by mait-all                        //
//                               Updated: 2025/11/07 11:24 by mait-all                        //
// ****************************************************************************************** //

#include "Animal.hpp"


// Default constructor
AAnimal::AAnimal() {
	this->type = "unkown";
	std::cout << "Animal: Default constructor called" << std::endl;
}

// Copy constructor
AAnimal::AAnimal(const AAnimal& other) {
	this->type = other.type;
	std::cout << "Animal: Copy constructor called" << std::endl;
}

// Copy assignment operator
AAnimal&	AAnimal::operator=(const AAnimal& other) {
	this->type = other.type;
	std::cout << "Animal: Copy assignment operator called" << std::endl;
	return (*this);
}

// Destructor
AAnimal::~AAnimal() {
	std::cout << "Animal: Destructor called" << std::endl;
}


// getter
std::string	AAnimal::getType(void) const {
	return (type);
}