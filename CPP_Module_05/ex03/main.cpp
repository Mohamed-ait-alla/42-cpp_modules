/*
 * @author:
 * 			mait-all
 * 
 * @github:
 * 			https://github.com/Mohamed-ait-alla
 * 
 * @description:
 * 			This exercise introduces the Intern class, which is responsible for creating
 * 			concrete AForm objects based on a form name requested at runtime.
 * 
 * 			The Intern provides a member function:
 * 				- makeForm(const std::string &formName, const std::string &target)
 * 
 * 			This function acts as a simple factory: it returns a new form object based
 * 			on the formName passed as parameter.
 * 
 * 			Valid forms are:
 * 				→ ShrubberyCreationForm
 * 				→ RobotomyRequestForm
 * 				→ PresidentialPardonForm
 * 
 * 			If the requested form name does not match any known type, the Intern throws
 * 			an appropriate exception, indicating that the form cannot be created.
 * 
 * @usage:
 * 			1. Compile:	make
 * 			2. Run:		./intern
 * 			3. CleanUp:	make fclean
*/

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void)
{
    try
    {
        Bureaucrat  bob("bob", 15);
        Intern      intern;

        // testing valid forms
        AForm*  sC = intern.makeForm("ShrubberyCreationForm", "home");
        AForm*  rR = intern.makeForm("RobotomyRequestForm", "bender");
        AForm*  pP = intern.makeForm("PresidentialPardonForm", "marvin");

        std::cout << *sC << std::endl;
        std::cout << *rR << std::endl;
        std::cout << *pP << std::endl;

        std::cout << std::endl;
        std::cout << std::endl;

        bob.signForm(*sC);
        bob.executeForm(*sC);

        std::cout << std::endl;

        bob.signForm(*rR);
        bob.executeForm(*rR);

        std::cout << std::endl;

        bob.signForm(*pP);
        bob.executeForm(*pP);

        delete sC;
        delete rR;
        delete pP;

        std::cout << std::endl;

        // testing a wrong form name
        AForm*  wrongForm = intern.makeForm("wrong form", "monster");

        bob.signForm(*wrongForm);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return (0);
}