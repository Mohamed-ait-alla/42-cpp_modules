// ****************************************************************************************** //
//                               file: Ice.cpp                                                //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/14 17:39 by mait-all                        //
//                               Updated: 2025/10/14 18:38 by mait-all                        //
// ****************************************************************************************** //

#include "Ice.hpp"

// Default constructor
Ice::Ice() {
    this->type = "ice";
    std::cout << "Ice: Default constructor called" << std::endl;
}

// Copy constructor
Ice::Ice(const Ice& other) : AMateria(other) {
    std::cout << "Ice: Copy constructor called" << std::endl;
}

// Copy assignment operator
Ice&    Ice::operator=(const Ice& other) {
    AMateria::operator=(other);
    std::cout << "Ice: Copy assignment operator called" << std::endl;
    return (*this);
}

// Destructor
Ice::~Ice() {
    std::cout << "Ice: Destructor called" << std::endl;
}


// --- Member functions ---
AMateria*   Ice::clone(void) const {
    return (new Ice());
}

void    Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}