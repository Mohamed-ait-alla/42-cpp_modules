// ****************************************************************************** //
//                        file: ScalarConverter.cpp                               //
//                        by: mait-all <mait-all@student.1337.ma>                 //
//                                                                                //
//                        Created: 2025/11/06 09:27 by mait-all                   //
//                        Updated: 2025/11/19 09:15 by mait-all                   //
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

// function used to check for special literals (+inf, +inff ...)
bool	ScalarConverter::isSpecialLiteral(std::string& input)
{
	if (input == "-inff" || input == "+inff" || input == "nanf"
		|| input == "-inf" || input == "+inf" || input == "nan")
		return (true);
	return (false);
}

// function used to check '-' and '+' signs
bool	ScalarConverter::isValidSignPosition(std::string& input)
{
	// check if it has as sign
	if (input.find_first_of("-+") != std::string::npos)
	{
		// check if no multiple signs
		if (hasMultipleSameChars(input, '-') || hasMultipleSameChars(input, '+'))
			return (false);
		// check if sign in the correct position
		if (input.find("-") != std::string::npos && input[0] != '-')
			return (false);
		if (input.find("+") != std::string::npos && input[0] != '+')
			return (false);
		return (true);
	}
	// no sign no check
	return (true);
}

// function used to check the position of 'f' in floating numbers
bool	ScalarConverter::isValidFPosition(std::string& input)
{
	// check if it's a float data type
	if (input.find("f") != std::string::npos)
	{
		// check if 'f' is at the end of entred argument
		size_t len = input.length();
		if (input[len - 1] != 'f')
			return (false);
		// check if the entred arg has '.'
		if (input.find(".") == std::string::npos)
			return (false);
		return (true);
	}
	// non floating data types
	return (true);
}

// function used to check for multiple 'f' or '.'
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

// function used to check if the input is a char
bool	ScalarConverter::isChar(std::string& input)
{
	if (input.length() == 1 && !isdigit(input[0]))
		return (true);
	return (false);
}

// function used to convert to scalar type: char
void	ScalarConverter::convertToChar(double nb)
{
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

// function used to convert to scalar type: int
void	ScalarConverter::convertToInt(double nb)
{
	// check for overflow/underflow
	if (nb > std::numeric_limits<int>::max()
		|| nb < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(nb) << std::endl;
}

// function used to convert to scalar type: float
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

// function used to convert to scalar type: double
void	ScalarConverter::convertToDouble(double nb)
{
	if (nb > std::numeric_limits<double>::max()
		|| nb < -std::numeric_limits<double>::max())
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << static_cast<double>(nb) << std::endl;
}

// function used to handle special literals
void	ScalarConverter::handleSpecialLiterals(std::string& input)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (input == "-inff" || input == "+inff" || input == "nanf")
	{
		std::cout << "float: " << input << std::endl;
		std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;
	}
	else
	{
		std::cout << "float: " << input << "f" << std::endl;
		std::cout << "double: " << input << std::endl;
	}
}

// does an argument valid
bool	ScalarConverter::isValidArg(std::string& input)
{
	if (input.find_first_not_of("-+0123456789.f") != std::string::npos)
	{
		// check for special literals
		if (isSpecialLiteral(input))
			return (true);
		return (false);
	}
	if (hasMultipleSameChars(input, 'f') || hasMultipleSameChars(input, '.'))
		return (false);
	if (!isValidFPosition(input))
		return (false);
	if (!isValidSignPosition(input))
		return (false);
	return (true);
}

// convert the detected type to scalar types (Char, Int, Float, Double)
void    ScalarConverter::convert(std::string& input)
{
	double	nb;
	int		convertedInt;

	// check for invalid argument
	if (input.empty() || (!isValidArg(input) && !isChar(input)))
		throw std::invalid_argument("Oops! Invalid argument");
	// if input is a special literal
	if (isSpecialLiteral(input))
		handleSpecialLiterals(input);
	// other data types
	else
	{
		nb = strtod(input.c_str(), 0);
		// if input is a char
		if (isChar(input))
		{
			convertedInt = static_cast<int>(input[0]);
			convertToChar(convertedInt);
			nb = convertedInt;
		}
		if (!isChar(input))
			convertToChar(nb);
		convertToInt(nb);
		convertToFloat(nb);
		convertToDouble(nb);
	}
}
