// ****************************************************************************** //
//                        file: ScalarConverter.hpp                               //
//                        by: mait-all <mait-all@student.1337.ma>                 //
//                                                                                //
//                        Created: 2025/10/26 19:49 by mait-all                   //
//                        Updated: 2025/11/16 17:42 by mait-all                   //
// ****************************************************************************** //

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <cstdlib>


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
        static ScalarTypes  detectType(std::string& value);

    private:
        // ocf
        // I make the orthodox canonical form private to make the class instantiable
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter&    operator=(const ScalarConverter& other);
        ~ScalarConverter();

		// private member functions
		static bool	hasMultipleSameChars(std::string& input, char c);
		static bool	isValidFPosition(std::string& input);

};


#endif /* __SCALARCONVERTER_HPP__ */