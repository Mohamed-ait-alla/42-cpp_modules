// ****************************************************************************************** //
//                               file: ICharacter.cpp                                         //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/14 19:42 by mait-all                        //
//                               Updated: 2025/10/14 20:12 by mait-all                        //
// ****************************************************************************************** //

#include "ICharacter.hpp"

// Default constructor
ICharacter::ICharacter() {
    std::cout << "ICharacter: Default constructor called" << std::endl;
}

// Copy constructor
ICharacter::ICharacter(const ICharacter& other) {
    *this = other;
    std::cout <<  "ICharacter: Copy constructor called" << std::endl;
}

// Copy assignment operator called 
ICharacter& ICharacter::operator=(const ICharacter& other) {
    *this = other;
    std::cout << "ICharacter: Copy assignment operator called" << std::endl;
    return (*this);
}

// Destructor
ICharacter::~ICharacter() {
    std::cout << "ICharacter: Destructor called" << std::endl;
}