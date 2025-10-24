// ****************************************************************************************** //
//                               file: Intern.cpp                                             //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/23 19:38 by mait-all                        //
//                               Updated: 2025/10/24 22:10 by mait-all                        //
// ****************************************************************************************** //

#include "Intern.hpp"

// -------------------------------
// Orthodox Canonical Form
// -------------------------------

// Default constructor
Intern::Intern() {}

// Copy constructor
Intern::Intern(const Intern& other)
{
    *this = other;
}

// Copy assignment operator
Intern& Intern::operator=(const Intern& other) {
    if (this != &other)
        *this = other;
    return (*this);
}

// Destructor
Intern::~Intern() {}


// -------------------------------
// Member functions
// -------------------------------

AForm*  Intern::makeForm(const std::string formName, const std::string formTarget) {
    std::string validForms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    int         index = 0;

    for (index = 0; index < 3; index++)
    {
        if (formName == validForms[index])
            break;
    }

    switch(index)
    {
        case 0:
                return (new ShrubberyCreationForm(formTarget));
        case 1:
                return (new RobotomyRequestForm(formTarget));
        case 2:
                return (new PresidentialPardonForm(formTarget));
        default:
                throw std::invalid_argument("Invalid form name");
                return (NULL);
    }
}