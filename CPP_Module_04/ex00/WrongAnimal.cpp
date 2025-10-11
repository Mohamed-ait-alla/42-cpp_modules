// ****************************************************************************************** //
//                               file: WrongAnimal.cpp                                        //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/11 13:33 by mait-all                        //
//                               Updated: 2025/10/11 14:21 by mait-all                        //
// ****************************************************************************************** //

#include "WrongAnimal.hpp"

// Default constructor
WrongAnimal::WrongAnimal() {
    this->type = "unkown";
    std::cout << "WrongAnimal: Default constructor called" << std::endl;
}

// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    this->type = other.type;
    std::cout << "WrongAnimal: Copy constructor called" << std::endl;
}

// Copy asignment operator
WrongAnimal&    WrongAnimal::operator=(const WrongAnimal& other) {
    this->type = other.type;
    std::cout << "WrongAnimal: Copy assignment operator called" << std::endl;

    return (*this);
}

// Destructor 
WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal: Destructor called" << std::endl;
}

// --- Member functions ---
void    WrongAnimal::makeSound(void) const {
    std::cout << "!! No default Animal sound !!" << std::endl;
}

std::string WrongAnimal::getType(void) const {
    return (type);
}