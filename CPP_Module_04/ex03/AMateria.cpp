// ****************************************************************************************** //
//                               file: AMateria.cpp                                           //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/13 19:57 by mait-all                        //
//                               Updated: 2025/10/13 20:20 by mait-all                        //
// ****************************************************************************************** //

#include "AMateria.hpp"

// Default constructor
AMateria::AMateria() {
    this->type = "default";
    std::cout << "AMateria: Default constructor called" << std::endl;
}

// Parametrised constructor
AMateria::AMateria(std::string const & type) {
    this->type = type;
    std::cout << "AMateria: Parametrised constructor called" << std::endl;
}

// Copy constructor
AMateria::AMateria(const AMateria& other) {
    this->type = other.type;
    std::cout << "AMateria: Copy constructor called" << std::endl;
}

// Copy assignment operator
AMateria&   AMateria::operator=(const AMateria& other) {
    this->type = other.type;
    std::cout << "AMateria: Copy assignment operator called" << std::endl;
    return (*this);
}

// Destructor
AMateria::~AMateria() {
    std::cout << "AMateria: Default constructor called" << std::endl;
}

// --- Member functions ---
void    AMateria::use(Icharacter& target) {
    // todo...
}

std::string const & AMateria::getType() const {
    return (type);
}