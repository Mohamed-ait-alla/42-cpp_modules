/*
 * @author:
 * 			ToDo...
 * 
 * @github:
 * 			ToDo...
 * 
 * @description:
 * 			ToDo...
 * 
 * 
 * @usage:
 * 			ToDo...
 *
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
        AForm*  sC = intern.makeForm("shrubbery creation", "home");
        AForm*  rR = intern.makeForm("robotomy request", "bender");
        AForm*  pP = intern.makeForm("presidential pardon", "marvin");

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