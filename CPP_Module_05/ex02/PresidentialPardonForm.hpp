// ****************************************************************************************** //
//                               file: PresidentialPardonForm.hpp                             //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/22 13:50 by mait-all                        //
//                               Updated: 2025/10/23 10:55 by mait-all                        //
// ****************************************************************************************** //

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"


// ************************************************************************** //
//                         PresidentialPardonForm Class                       //
// ************************************************************************** //

class PresidentialPardonForm : public AForm {

    public:
        // ocf
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();

        // member functions
        void    execute(const Bureaucrat& executor);

};


#endif /* __PRESIDENTIALPARDONFORM_HPP__ */