// ****************************************************************************************** //
//                               file: ScalarConverter.cpp                                    //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/26 19:49 by mait-all                        //
//                               Updated: 2025/10/28 13:19 by mait-all                        //
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

// Detect the type of the content inside the string parameter
ScalarTypes ScalarConverter::detectType(std::string& value) {
    // char
    if (value.length() == 1 && !isdigit(value[0]))
        return (CHAR);
    // invalid
    else if (value.find_first_not_of("-+") == std::string::npos)
        return (INVALID);
    // int
    else if (value.find_first_not_of("-+0123456789") == std::string::npos)
        return (INT);
    // double
    else if (value.find_first_not_of("-+0123456789.") == std::string::npos)
        return (DOUBLE);
    // float
    else if (value.find_first_not_of("-+0123456789.f") == std::string::npos)
        return (FLOAT);
    else
        return (INVALID);
}

// convert the detected type to scalar types (Char, Int, Float, Double)
void    ScalarConverter::convert(std::string& input) {
    switch (detectType(input))
    {
    case CHAR:
        {
            if (isprint(input[0]))
                std::cout << "char: '" << input << "'" << std::endl;
            else
                std::cout << "char: Non Displayable" << std::endl;
            std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
            std::cout << "float: " << static_cast<float>(input[0]) << ".0f" << std::endl;
            std::cout << "double: " << static_cast<double>(input[0]) << ".0" << std::endl;
            break;
        }
    case INT:
        {
            char    castedChar = static_cast<char>(atoi(input.c_str()));
            if (isprint(castedChar))
                std::cout << "char: '" << castedChar << "'" << std::endl;
            else
                std::cout << "char: Non Displayable" << std::endl;
            std::cout << "int: " << atoi(input.c_str()) << std::endl;
            std::cout << "float: " << static_cast<float>(atoi(input.c_str())) << ".0f" << std::endl;
            std::cout << "double: " << static_cast<double>(atoi(input.c_str())) << ".0" << std::endl;
            break;
        }
    case FLOAT: // note: edge case 42.0f 42.2f
        {
            if (isprint(static_cast<char>(atoi(input.c_str()))))
                std::cout << "char: '" << static_cast<char>(atoi(input.c_str())) << "'" << std::endl;
            else
                std::cout << "char: Non Displayable" << std::endl;
            std::cout << "int: " << static_cast<int>(atof(input.c_str())) << std::endl;
            std::cout << "float: " << atof(input.c_str()) << ".0f" << std::endl;
            std::cout << "double: " << static_cast<double>(strtod(input.c_str(), 0)) << ".0" << std::endl;
            break;
        }
    case DOUBLE: // note: edge case 42.0 42.1
        {
            if (isprint(static_cast<char>(atof(input.c_str()))))
                std::cout << "char: '" << static_cast<char>(atof(input.c_str())) << "'" << std::endl;
            else
                std::cout << "char: Non Displayable" << std::endl;
            std::cout << "int: " << static_cast<int>(atof(input.c_str())) << std::endl;
            std::cout << "float: " << atof(input.c_str()) << ".0f" << std::endl;
            std::cout << "double: " << static_cast<double>(strtod(input.c_str(), 0)) << std::endl;
            break;
        }
    
    default:
        throw std::invalid_argument("Oops! Invalid argument");
        break;
    }
}
