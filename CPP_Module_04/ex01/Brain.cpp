// ****************************************************************************************** //
//                               file: Brain.cpp                                              //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/11 20:15 by mait-all                        //
//                               Updated: 2025/11/06 15:21 by mait-all                        //
// ****************************************************************************************** //

#include "Brain.hpp"

// Default constructor
Brain::Brain() {
    std::cout << "Brain: Default constructor called" << std::endl;
}

// Copy constructor
Brain::Brain(const Brain& other) {
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = other._ideas[i];
    std::cout << "Brain: Copy constructor called" << std::endl;
}

// Copy assignment operator
Brain&  Brain::operator=(const Brain& other) {
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = other._ideas[i];
    std::cout << "Brain: Copy assignment operator called" << std::endl;
    return (*this);
}

// Destructor
Brain::~Brain() {
    std::cout << "Brain: Destructor called" << std::endl;
}


// --- Member functions ---

//_____________| getter |_____________//
std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100)
        return (_ideas[index]);
    std::cout << "index is out-of-range 0-99 (100 ideas)" << std::endl;
    return (_ideas[0]);
}

//_____________| setter |_____________//
void    Brain::setIdea(int index, std::string idea) {
    if (index >= 0 && index < 100)
        _ideas[index] = idea;
    else
        std::cout << "index is out-of-range 0-99 (100 ideas)" << std::endl;
}
