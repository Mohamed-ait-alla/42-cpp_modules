// ****************************************************************************************** //
//                               file: WrongCat.cpp                                           //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/12 19:40 by mait-all                        //
//                               Updated: 2025/10/12 19:40 by mait-all                        //
// ****************************************************************************************** //

#include "WrongCat.hpp"

// Default constructor
WrongCat::WrongCat() : WrongAnimal() {
    this->type = "WrongCat";
    std::cout << "WrongCat: Default constructor called" << std::endl;
}

// Copy constructor
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "WrongCat: Copy constructor called" << std::endl;
}

// Copy assignment operator
WrongCat&   WrongCat::operator=(const WrongCat& other) {
    WrongAnimal::operator=(other);
    std::cout << "WrongCat: Copy assignment operator called" << std::endl;

    return (*this);
}

// Destructor
WrongCat::~WrongCat() {
    std::cout << "WrongCat: Destructor called" << std::endl;
}

// --- Member functions ---
void    WrongCat::makeSound(void) const {
    std::cout << "!! meow meow !!" << std::endl;
}