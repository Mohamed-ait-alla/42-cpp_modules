// ****************************************************************************************** //
//                               file: AForm.hpp                                              //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/22 13:50 by mait-all                        //
//                               Updated: 2025/10/22 17:38 by mait-all                        //
// ****************************************************************************************** //

#pragma once

#include "Bureaucrat.hpp"


// ************************************************************************** //
//                                 AForm Class                                //
// ************************************************************************** //

class AForm {

    public:
        // ocf
        AForm();
        AForm(const std::string name, int gradeToSign, int gradeToExecute);
        AForm(const AForm& other);
        AForm&   operator=(const AForm& other);
        virtual ~AForm();

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
std::ostream&	operator<<(std::ostream& output, const AForm& formObj);