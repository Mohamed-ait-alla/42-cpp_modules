// ****************************************************************************************** //
//                               file: Bureaucrat.hpp                                         //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/19 10:59 by mait-all                        //
//                               Updated: 2025/10/19 21:33 by mait-all                        //
// ****************************************************************************************** //

#pragma once

#include <iostream>


// ************************************************************************** //
//                               Bureaucrat Class                             //
// ************************************************************************** //

class Bureaucrat {

    public:
        // ocf
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        // member functions
        std::string   getName() const;
        int           getGrade() const;
        void          incrementGrade();
        void          decrementGrade();

        // Exceptions
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
        int                 _grade;

};

// insertion operator (<<) overloading
std::ostream&	operator<<(std::ostream& output, const Bureaucrat& Obj);
