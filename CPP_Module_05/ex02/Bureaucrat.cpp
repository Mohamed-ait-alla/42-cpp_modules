// ****************************************************************************************** //
//                               file: Bureaucrat.cpp                                         //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/22 13:50 by mait-all                        //
//                               Updated: 2025/10/23 11:43 by mait-all                        //
// ****************************************************************************************** //

#include "Bureaucrat.hpp"
#include "AForm.hpp"

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

// attempt to sign a form
void    Bureaucrat::signForm(AForm& form) {
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

// attempt to execute a form
void    Bureaucrat::executeForm(const AForm& form) {
    try
    {
        form.execute(*this);
        std::cout << this->_name << " executed " << form.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << this->_name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
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