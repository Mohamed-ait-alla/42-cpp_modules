// ****************************************************************************************** //
//                               file: AForm.cpp                                              //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/22 13:50 by mait-all                        //
//                               Updated: 2025/10/22 18:54 by mait-all                        //
// ****************************************************************************************** //

#include "AForm.hpp"

// -------------------------------
// Orthodox Canonical Form
// -------------------------------

// Default constructor
AForm::AForm()
    : _name("Default"),
      _gradeToSign(150),
      _gradeToExecute(150)
{
    _isSigned = false;
}

// Parametrised constructor
AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute) 
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
AForm::AForm(const AForm& other)
    : _name(other._name),
      _gradeToSign(other._gradeToSign),
      _gradeToExecute(other._gradeToExecute)
{
    _isSigned = other._isSigned;
}

// Copy assignment operator
AForm&   AForm::operator=(const AForm& other) {
    if (this != &other)
        _isSigned = other._isSigned;
    return (*this);
}

// Destructor
AForm::~AForm() {}


// -------------------------------
// Member functions
// -------------------------------

// form name getter
std::string AForm::getName() const {
    return _name;
}

// isSigned getter
bool    AForm::getIsSigned() const {
    return _isSigned;
}

// grade to sign the form getter
int AForm::getGradeToSign() const {
    return _gradeToSign;
}

// grade to execute the form getter
int AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

// attempt to sign the form depending on the bureaucrat's grade
void    AForm::beSigned(Bureaucrat& b) {
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}


// -------------------------------
// Exception Implementations
// -------------------------------

const char* AForm::GradeTooHighException::what() const throw() {
    return ("Grade is too high!");
}

const char* AForm::GradeTooLowException::what() const throw() {
    return ("Grade is too low!");
}


// ------------------------------------
// Insertion Operator implementation
// ------------------------------------

std::ostream&   operator<<(std::ostream& output, const AForm& formObj) {
    output  << "Form name: " << formObj.getName() << std::endl
            << "Form status: " << (formObj.getIsSigned() ? "signed" : "unsigned") << std::endl
            << "Grade to be signed: " << formObj.getGradeToSign() << std::endl
            << "Grade to be Executed: " << formObj.getGradeToExecute() << std::endl;
    return (output);
}
