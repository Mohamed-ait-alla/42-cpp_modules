// ****************************************************************************************** //
//                               file: ShrubberyCreationForm.hpp                              //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/22 13:50 by mait-all                        //
//                               Updated: 2025/10/22 13:50 by mait-all                        //
// ****************************************************************************************** //

#pragma once

#include "AForm.hpp"
#include <fstream>

// ************************************************************************** //
//                         ShrubberyCreationForm Class                        //
// ************************************************************************** //

class ShrubberyCreationForm : public AForm {

    public: 
        // ocf
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm&  operator=(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();

        // member functions
        void    execute(const Bureaucrat& executor);
};