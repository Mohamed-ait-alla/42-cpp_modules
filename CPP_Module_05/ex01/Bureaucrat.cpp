// ****************************************************************************************** //
//                               file: Bureaucrat.cpp                                         //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/20 11:29 by mait-all                        //
//                               Updated: 2025/10/20 11:29 by mait-all                        //
// ****************************************************************************************** //

#include "Bureaucrat.hpp"


// -------------------------------
// Orthodox Canonical Form
// -------------------------------

// Default constructor
Bureaucrat::Bureaucrat() : _name("unknown") {
    _grade = 150;
}

// Parametrised constructor
Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name) {
    _grade = other._grade;
}

// Copy assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other)
        _grade = other._grade;
    return (*this);
}

// Destructor
Bureaucrat::~Bureaucrat() {}


// -------------------------------
// Member functions
// -------------------------------

// name getter
std::string Bureaucrat::getName() const {
    return (_name);
}

// grade getter
int Bureaucrat::getGrade() const {
    return (_grade);
}

// increment grade by 1
void    Bureaucrat::incrementGrade() {
    if (_grade - 1 < 1)
        throw GradeTooHighException();
    else
        _grade--;
}

// decrement grade by 1
void    Bureaucrat::decrementGrade() {
    if (_grade + 1 > 150)
        throw GradeTooLowException();
    else
        _grade++;
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

std::ostream&   operator<<(std::ostream& output, const Bureaucrat& obj) {
    output << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return (output);
}