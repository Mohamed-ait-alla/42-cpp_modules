// ****************************************************************************************** //
//                               file: Cure.cpp                                               //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/14 17:39 by mait-all                        //
//                               Updated: 2025/10/14 19:37 by mait-all                        //
// ****************************************************************************************** //

#include "Cure.hpp"

// Default constructor
Cure::Cure() {
    this->type = "cure";
    std::cout << "Cure: Default constructor called" << std::endl;
}

// Copy constructor
Cure::Cure(const Cure& other) : AMateria(other) {
    std::cout << "Cure: Copy constructor called" << std::endl;
}

// Copy assignment operator
Cure&   Cure::operator=(const Cure& other) {
    AMateria::operator=(other);
    std::cout << "Cure: Copy assignment operator called" << std::endl;
    return (*this);
}

// Destructor
Cure::~Cure() {
    std::cout << "Cure: Destructor called" << std::endl;
}


// --- Member functions ---
AMateria*   Cure::clone(void) const {
    return (new Cure());
}

void    Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}