// ****************************************************************************************** //
//                               file: ScalarConverter.hpp                                    //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/26 19:49 by mait-all                        //
//                               Updated: 2025/10/26 19:59 by mait-all                        //
// ****************************************************************************************** //

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>


// ************************************************************************** //
//                            ScalarConverter Class                           //
// ************************************************************************** //

class ScalarConverter {

    public:
        static void convert(std::string& input);

    private:
        // ocf
        // I make the orthodox canonical form private to make the class instantiable
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter&    operator=(const ScalarConverter& other);
        ~ScalarConverter();

};


#endif /* __SCALARCONVERTER_HPP__ */