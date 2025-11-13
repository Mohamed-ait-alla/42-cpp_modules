// ****************************************************************************** //
//                        file: RobotomyRequestForm.hpp                           //
//                        by: mait-all <mait-all@student.1337.ma>                 //
//                                                                                //
//                        Created: 2025/10/23 19:12 by mait-all                   //
//                        Updated: 2025/11/13 09:12 by mait-all                   //
// ****************************************************************************** //

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <stdlib.h>
# include "AForm.hpp"


// ****************************************************************************** //
//                           RobotomyRequestForm Class                            //
// ****************************************************************************** //

class RobotomyRequestForm : public AForm {

    public:
        // ocf
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm&    operator=(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();

        // member functions
        void    execute(const Bureaucrat& executor) const;

};


#endif /* __ROBOTOMYREQUESTFORM_HPP__ */