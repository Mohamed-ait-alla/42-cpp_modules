// ****************************************************************************************** //
//                               file: Form.cpp                                               //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/20 11:31 by mait-all                        //
//                               Updated: 2025/10/20 20:01 by mait-all                        //
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

// form name getter
std::string Form::getName() const {
    return _name;
}

// isSigned getter
bool    Form::getIsSigned() const {
    return _isSigned;
}

// grade to sign the from getter
int Form::getGradeToSign() const {
    return _gradeToSign;
}

// grade to execute the form getter
int Form::getGradeToExecute() const {
    return _gradeToExecute;
}

// attempt to sign the form depending on the bureaucrat's grade
void    Form::beSigned(Bureaucrat& b) {
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}


// -------------------------------
// Exception Implementations
// -------------------------------

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Grade is too low!");
}


// ------------------------------------
// Insertion Operator implementation
// ------------------------------------

std::ostream&   operator<<(std::ostream& output, const Form& formObj) {
    output  << "Form name: " << formObj.getName() << std::endl
            << "Form status: " << (formObj.getIsSigned() ? "signed" : "unsigned") << std::endl
            << "Grade to be signed: " << formObj.getGradeToSign() << std::endl
            << "Grade to be Executed: " << formObj.getGradeToExecute() << std::endl;
    return (output);
}
