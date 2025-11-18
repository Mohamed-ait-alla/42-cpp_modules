// ****************************************************************************** //
//                        file: ScalarConverter.cpp                               //
//                        by: mait-all <mait-all@student.1337.ma>                 //
//                                                                                //
//                        Created: 2025/11/06 09:27 by mait-all                   //
//                        Updated: 2025/11/18 18:24 by mait-all                   //
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
// --42 / ++42 / int overflow ; char overlows in float double
// --- --- --- ----


// check if the argument has one f and in the correct position
// bool	ScalarConverter::isValidFPosition(std::string& input)
// {
// 	size_t len = input.length();
// 	if (input[len - 1] != 'f')
// 		return (false);
// 	return (true);
// }


// check if the argument has more than one dots
// bool	ScalarConverter::hasMultipleSameChars(std::string& input, char c)
// {
// 	int	count = 0;

// 	for (unsigned long i = 0; i < input.length(); i++)
// 	{
// 		if (input[i] == c)
// 			count++;
// 	}
// 	return (count > 1 ? true : false);
// }

// Detect the type of the content inside the string parameter
// ScalarTypes ScalarConverter::detectType(std::string& value)
// {
//     // char 
//     if (value.length() == 1 && !isdigit(value[0]))
//         return (CHAR);
//     // special float/double values
//     else if (value == "+inff" || value == "-inff" || value == "nanf"
//         || value == "+inf" || value == "-inf" || value == "nan")
//         return (NAN_INF);
//     // invalid
//     else if (value.find_first_not_of("-+") == std::string::npos)
//         return (INVALID);
//     // int
//     else if (value.find_first_not_of("-+0123456789") == std::string::npos)
//         return (INT);
//     // double
//     else if (value.find_first_not_of("-+0123456789.") == std::string::npos)
// 	{
// 		if (hasMultipleSameChars(value, '.'))
// 			return (INVALID);
//         return (DOUBLE);
// 	}
//     // float: 42..0f, multiple dots: 42.42.42, f in rong pos: 42f42, multiple signs: --42, char overlows: 300
//     else if (value.find_first_not_of("-+0123456789.f") == std::string::npos)
// 	{
// 		if (hasMultipleSameChars(value, '.')) // edge case: 42..42f
// 			return (INVALID);
// 		if (hasMultipleSameChars(value, 'f')) // edge case: 42.42fff
// 			return (INVALID);
// 		if (!isValidFPosition(value)) // edge case: 42f42
// 			return (INVALID);
// 		if (value.find(".") == std::string::npos) // edge case: 42f
// 			return (INVALID);
//         return (FLOAT);
// 	}
//     else
//         return (INVALID);
// }

// convert to scalar type: char
void	ScalarConverter::convertToChar(double nb)
{
	// std::cout << "nb is : " << nb << std::endl;
	// check for overflow/underflow
	if (nb > std::numeric_limits<int>::max()
		|| nb < std::numeric_limits<int>::min()
		|| nb < 0
		|| nb > 255)
		std::cout << "char: impossible" << std::endl;
	else
	{
		if (isprint(nb))
			std::cout << "char: '" << static_cast<char>(nb) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
}

// convert to scalar type: int
void	ScalarConverter::convertToInt(double nb)
{
	// check for overflow/underflow
	if (nb > std::numeric_limits<int>::max()
		|| nb < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(nb) << std::endl;
}

// convert to scalar type: float
void	ScalarConverter::convertToFloat(double nb)
{
	if (nb > std::numeric_limits<float>::max()
		|| nb < -std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1)
				  << "float: " << static_cast<float>(nb)
				  << "f" << std::endl;
}

// convert to scalar type: double
void	ScalarConverter::convertToDouble(double nb)
{
	if (nb > std::numeric_limits<double>::max()
		|| nb < -std::numeric_limits<double>::max())
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << static_cast<double>(nb) << std::endl;
}

// convert the detected type to scalar types (Char, Int, Float, Double)
void    ScalarConverter::convert(std::string& input)
{
	double	nb;
	bool	isChar = false;
	int		convertedInt;

	// check for empty string
	if (input.empty())
		throw std::invalid_argument("Oops! Invalid argument");

	nb = strtod(input.c_str(), 0);
	// check for char data type
	if (input.length() == 1 && !isdigit(input[0]))
	{
		isChar = true;
		convertedInt = static_cast<int>(input[0]);
		convertToChar(convertedInt);
		nb = convertedInt;
	}

	if (!isChar)
		convertToChar(nb);
	convertToInt(nb);
	convertToFloat(nb);
	convertToDouble(nb);
}
