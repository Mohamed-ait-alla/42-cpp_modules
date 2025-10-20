// ****************************************************************************************** //
//                               file: Form.hpp                                               //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/20 11:31 by mait-all                        //
//                               Updated: 2025/10/20 14:05 by mait-all                        //
// ****************************************************************************************** //

#pragma once

#include "Bureaucrat.hpp"


// ************************************************************************** //
//                                  Form Class                                //
// ************************************************************************** //

class Form {

    public:
        // ocf
        Form();
        Form(const std::string name, int gradeToSign, int gradeToExecute);
        Form(const Form& other);
        Form&   operator=(const Form& other);
        ~Form();

        // member functions
        std::string getName() const;
        bool        getIsSigned() const;
        int         getGradeToSign() const;
        int         getGradeToExecute() const;
        void        beSigned(Bureaucrat& b);

        // exceptions
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };

    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeToSign;
        const int           _gradeToExecute;

};

// insertion operator (<<) overloading
std::ostream&	operator<<(std::ostream& output, const Form& Obj);