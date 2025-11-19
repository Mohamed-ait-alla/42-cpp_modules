// ****************************************************************************** //
//                        file: ScalarConverter.hpp                               //
//                        by: mait-all <mait-all@student.1337.ma>                 //
//                                                                                //
//                        Created: 2025/10/26 19:49 by mait-all                   //
//                        Updated: 2025/11/19 11:47 by mait-all                   //
// ****************************************************************************** //

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <limits>
# include <iomanip>


enum    ScalarTypes {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    NAN_INF,
    INVALID
};

// ****************************************************************************** //
//                            ScalarConverter Class                               //
// ****************************************************************************** //

class ScalarConverter {

    public:
		// public member functions
        static void         convert(std::string& input);

    private:
        // ocf
        // I make the orthodox canonical form private to make the class instantiable
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter&    operator=(const ScalarConverter& other);
        ~ScalarConverter();

		// private helper member functions
		static bool		hasMultipleSameChars(std::string& input, char c);
		static bool		isValidFPosition(std::string& input);
		static bool		isValidArg(std::string& input);
		static bool		isValidSignPosition(std::string& input);
		static bool		isSpecialLiteral(std::string& input);
		static bool		isChar(std::string& input);
		static void		handleSpecialLiterals(std::string& input);
		static void		convertToChar(double nb);
		static void		convertToInt(double nb);
		static void		convertToFloat(double nb);
		static void		convertToDouble(double nb);

};


#endif /* __SCALARCONVERTER_HPP__ */