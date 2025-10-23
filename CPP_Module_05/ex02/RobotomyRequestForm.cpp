// ****************************************************************************************** //
//                               file: RobotomyRequestForm.cpp                                //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/22 13:50 by mait-all                        //
//                               Updated: 2025/10/23 18:44 by mait-all                        //
// ****************************************************************************************** //

#include "RobotomyRequestForm.hpp"

// -------------------------------
// Orthodox Canonical Form
// -------------------------------

// Default constructor
RobotomyRequestForm::RobotomyRequestForm() 
    : AForm ("RobotomyRequestForm", "unknown", 72, 45)
{}

// Parametrised constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string target)
    : AForm("RobotomyRequestForm", target, 72, 45)
{}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other)
{}

// Copy assignment operator
RobotomyRequestForm&    RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    AForm::operator=(other);
    return (*this);
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {}


// -------------------------------
// Member functions
// -------------------------------

void    RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    if (!this->getIsSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw GradeTooLowException();
    srand(time(NULL));
    std::cout << "Bzzz... drrr... BRRRRZZZZZZZ!" << std::endl;
    if (rand() % 2)
        std::cout << this->getTarget() << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "The robotomy of " << this->getTarget() << " failed!" << std::endl;
}