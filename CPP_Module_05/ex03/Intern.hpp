// ****************************************************************************************** //
//                               file: Intern.hpp                                             //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/23 19:38 by mait-all                        //
//                               Updated: 2025/10/24 17:52 by mait-all                        //
// ****************************************************************************************** //

#ifndef INTERN_HPP
# define INTERN_HPP
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"


// ************************************************************************** //
//                                Intern Class                                //
// ************************************************************************** //

class Intern {

    public:
        // ocf
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();

        // member functions
        AForm*  makeForm(const std::string formName, const std::string formTarget);

};


#endif /* __INTERN_HPP__ */