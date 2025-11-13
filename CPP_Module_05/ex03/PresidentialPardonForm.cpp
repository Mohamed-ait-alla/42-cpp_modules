// ****************************************************************************** //
//                        file: PresidentialPardonForm.cpp                        //
//                        by: mait-all <mait-all@student.1337.ma>                 //
//                                                                                //
//                        Created: 2025/10/23 19:12 by mait-all                   //
//                        Updated: 2025/11/13 09:07 by mait-all                   //
// ****************************************************************************** //

#include "PresidentialPardonForm.hpp"

// -------------------------------
// Orthodox Canonical Form
// -------------------------------

// Default constructor
PresidentialPardonForm::PresidentialPardonForm()
    : AForm ("PresidentialPardonForm", "unknown", 25, 5)
{}

// Parametrised constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string target)
    : AForm ("PresidentialPardonForm", target, 25, 5)
{}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm (other)
{}

// Copy assignment operator
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    AForm::operator=(other);
    return (*this);
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {}


// -------------------------------
// Member functions
// -------------------------------

void    PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    if (!this->getIsSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw GradeTooLowException();
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
