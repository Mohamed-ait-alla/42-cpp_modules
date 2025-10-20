// ****************************************************************************************** //
//                               file: Form.cpp                                               //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/20 11:31 by mait-all                        //
//                               Updated: 2025/10/20 18:27 by mait-all                        //
// ****************************************************************************************** //

#include "Form.hpp"

// -------------------------------
// Orthodox Canonical Form
// -------------------------------

// Default constructor
Form::Form()
    : _name("Default"),
      _gradeToSign(150),
      _gradeToExecute(150)
{
    _isSigned = false;
}

// Parametrised constructor
Form::Form(const std::string name, int gradeToSign, int gradeToExecute) 
    : _name(name),
      _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    _isSigned = false;
}

// Copy constructor
Form::Form(const Form& other)
    : _name(other._name),
      _gradeToSign(other._gradeToSign),
      _gradeToExecute(other._gradeToExecute)
{
    _isSigned = other._isSigned;
}

// Copy assignment operator
Form&   Form::operator=(const Form& other) {
    if (this != &other)
        _isSigned = other._isSigned;
    return (*this);
}

// Destructor
Form::~Form() {}


// -------------------------------
// Member functions
// -------------------------------



// -------------------------------
// Exception Implementations
// -------------------------------

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Grade is too low!");
}