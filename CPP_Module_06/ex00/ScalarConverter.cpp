// ****************************************************************************** //
//                        file: ScalarConverter.cpp                               //
//                        by: mait-all <mait-all@student.1337.ma>                 //
//                                                                                //
//                        Created: 2025/11/06 09:27 by mait-all                   //
//                        Updated: 2025/11/17 09:22 by mait-all                   //
// ****************************************************************************** //

#include "ScalarConverter.hpp"


// -------------------------------
// Orthodox Canonical Form
// -------------------------------

// Default constructor
ScalarConverter::ScalarConverter()
{
}

// Copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    *this = other;
}

// Copy assignment operator
ScalarConverter&    ScalarConverter::operator=(const ScalarConverter& other)
{
    if (this != &other)
        *this = other;
    return (*this);
}

// Destructor
ScalarConverter::~ScalarConverter()
{
}


// -------------------------------
// Member functions
// -------------------------------

// ---- checks ----
// 42. / 42f
// --- --- --- ----


// check if the argument has one f and in the correct position
bool	ScalarConverter::isValidFPosition(std::string& input)
{
	size_t len = input.length();
	if (input[len - 1] != 'f')
		return (false);
	return (true);
}


// check if the argument has more than one dots
bool	ScalarConverter::hasMultipleSameChars(std::string& input, char c)
{
	int	count = 0;

	for (unsigned long i = 0; i < input.length(); i++)
	{
		if (input[i] == c)
			count++;
	}
	return (count > 1 ? true : false);
}

// Detect the type of the content inside the string parameter
ScalarTypes ScalarConverter::detectType(std::string& value)
{
    // char 
    if (value.length() == 1 && !isdigit(value[0]))
        return (CHAR);
    // special float/double values
    else if (value == "+inff" || value == "-inff" || value == "nanf"
        || value == "+inf" || value == "-inf" || value == "nan")
        return (NAN_INF);
    // invalid
    else if (value.find_first_not_of("-+") == std::string::npos)
        return (INVALID);
    // int
    else if (value.find_first_not_of("-+0123456789") == std::string::npos)
        return (INT);
    // double
    else if (value.find_first_not_of("-+0123456789.") == std::string::npos)
	{
		if (hasMultipleSameChars(value, '.'))
			return (INVALID);
        return (DOUBLE);
	}
    // float: 42..0f, multiple dots: 42.42.42, f in rong pos: 42f42, multiple signs: --42, char overlows: 300
    else if (value.find_first_not_of("-+0123456789.f") == std::string::npos)
	{
		if (hasMultipleSameChars(value, '.')) // edge case: 42..42f
			return (INVALID);
		if (hasMultipleSameChars(value, 'f')) // edge case: 42.42fff
			return (INVALID);
		if (!isValidFPosition(value)) // edge case: 42f42
			return (INVALID);
		if (value.find(".") == std::string::npos) // edge case: 42f
			return (INVALID);
        return (FLOAT);
	}
    else
        return (INVALID);
}

// convert the detected type to scalar types (Char, Int, Float, Double)
void    ScalarConverter::convert(std::string& input)
{
    switch (detectType(input))
    {
    case CHAR:
        {
            // scalar type: char
            if (isprint(input[0]))
                std::cout << "char: '" << input << "'" << std::endl;
            else
                std::cout << "char: Non Displayable" << std::endl;
            // scalar type: int
            std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
            // scalar type: float
            std::cout << "float: " << static_cast<float>(input[0]) << ".0f" << std::endl;
            // scalar type: double
            std::cout << "double: " << static_cast<double>(input[0]) << ".0" << std::endl;
            break;
        }
    case INT:
        {
            // scalar type: char
			int	convertedInt = atoi(input.c_str());
			if (convertedInt >= 0 && convertedInt <= 255)
			{
				char    castedChar = static_cast<char>(convertedInt);
				if (isprint(castedChar))
					std::cout << "char: '" << castedChar << "'" << std::endl;
				else
					std::cout << "char: Non Displayable" << std::endl;
			}
			else
				std::cout << "char: impossible" << std::endl;
            // scalar type: int
            std::cout << "int: " << convertedInt << std::endl;
            // scalar type: float
            std::cout << "float: " << static_cast<float>(convertedInt) << ".0f" << std::endl;
            // scalar type: double
            std::cout << "double: " << static_cast<double>(convertedInt) << ".0" << std::endl;
            break;
        }
    case FLOAT:
        {
            // scalar type: char
			char	castedChar = static_cast<char>(atoi(input.c_str()));
            if (isprint(castedChar))
                std::cout << "char: '" << castedChar << "'" << std::endl;
            else
                std::cout << "char: Non Displayable" << std::endl;
            // scalar type: int
            std::cout << "int: " << static_cast<int>(atof(input.c_str())) << std::endl;
            // scalar type: float
            std::cout << "float: " << atof(input.c_str());
            if (atof(input.c_str()) == static_cast<int>(atof(input.c_str())))
                std::cout << ".0";
            std::cout << "f" << std::endl;
            // scalar type: double
            std::cout << "double: " << static_cast<double>(strtod(input.c_str(), 0));
            if (atof(input.c_str()) == static_cast<int>(strtod(input.c_str(), 0)))
                std::cout << ".0";
            std::cout << std::endl;
            break;
        }
    case DOUBLE:
        {
            // scalar type: char
            if (isprint(static_cast<char>(atof(input.c_str()))))
                std::cout << "char: '" << static_cast<char>(atof(input.c_str())) << "'" << std::endl;
            else
                std::cout << "char: Non Displayable" << std::endl;
            // scalar type: int
            std::cout << "int: " << static_cast<int>(atof(input.c_str())) << std::endl;
            // scalar type: float
            std::cout << "float: " << atof(input.c_str());
            if (atof(input.c_str()) == static_cast<int>(atof(input.c_str())))
                std::cout << ".0";
            std::cout << "f" << std::endl;
            // scalar type: double
            std::cout << "double: " << static_cast<double>(strtod(input.c_str(), 0));
            if (atof(input.c_str()) == static_cast<int>(strtod(input.c_str(), 0)))
                std::cout << ".0";
            std::cout << std::endl;
            break;
        }
    case NAN_INF:
        {
            // scalar type: char
            std::cout << "char: impossible" << std::endl;
            // scalar type: int
            std::cout << "char: impossible" << std::endl;
            // scalar type: float
            std::cout << "float: ";
            if (input == "+inf" || input == "+inff")
                std::cout << "+inff";
            else if (input == "-inf" || input == "-inff")
                std::cout << "-inff";
            else
                std::cout << "nanf";
            std::cout << std::endl;
            // scalary type: double
            std::cout << "double: ";
            if (input == "+inf" || input == "+inff")
                std::cout  << "+inf";
            else if (input == "-inf" || input == "-inff")
                std::cout << "-inf";
            else
                std::cout << "nan";
            std::cout << std::endl;
            break;
        }
    
    default:
        throw std::invalid_argument("Oops! Invalid argument");
        break;
    }
}
