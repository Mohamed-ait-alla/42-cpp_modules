// ****************************************************************************************** //
//                               file: Brain.cpp                                              //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/11 20:15 by mait-all                        //
//                               Updated: 2025/10/11 21:27 by mait-all                        //
// ****************************************************************************************** //

#include "Brain.hpp"

// Default constructor
Brain::Brain() {
    std::cout << "Brain: Default constructor called" << std::endl;
}

// Copy constructor
Brain::Brain(const Brain& other) {
    for (int i = 0; i < 100; i++)
        this->ideas[i] = other.ideas[i];
    std::cout << "Brain: Copy constructor called" << std::endl;
}

// Copy assignment operator
Brain&  Brain::operator=(const Brain& other) {
    for (int i = 0; i < 100; i++)
        this->ideas[i] = other.ideas[i];
    std::cout << "Brain: Copy assignment operator called" << std::endl;
    return (*this);
}

// Destructor
Brain::~Brain() {
    std::cout << "Brain: Destructor called" << std::endl;
}
