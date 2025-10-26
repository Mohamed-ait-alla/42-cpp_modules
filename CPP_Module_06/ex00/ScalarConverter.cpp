// ****************************************************************************************** //
//                               file: ScalarConverter.cpp                                    //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/26 19:49 by mait-all                        //
//                               Updated: 2025/10/26 20:23 by mait-all                        //
// ****************************************************************************************** //

#include "ScalarConverter.hpp"

// -------------------------------
// Orthodox Canonical Form
// -------------------------------

// Default constructor
ScalarConverter::ScalarConverter() {}

// Copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    *this = other;
}

// Copy assignment operator
ScalarConverter&    ScalarConverter::operator=(const ScalarConverter& other) {
    if (this != &other)
        *this = other;
    return (*this);
}

// Destructor
ScalarConverter::~ScalarConverter() {}


// -------------------------------
// Member functions
// -------------------------------
