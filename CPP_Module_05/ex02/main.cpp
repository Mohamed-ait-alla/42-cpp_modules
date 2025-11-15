/*
 * @author:
 * 			mait-all
 * 
 * @github:
 * 			https://github.com/Mohamed-ait-alla
 * 
 * @description:
 * 			This exercise builds on the previous interaction between Bureaucrat and Form by
 * 			making the Form class as an abstract class called AForm. The AForm class defines
 * 			a common interface for all forms and includes a pure virtual method:
 * 
 * 				- execute(Bureaucrat const & executor)
 * 
 * 			This method must be implemented by each concrete form class:
 * 				- ShrubberyCreationForm
 * 				- RobotomyRequestForm
 * 				- PresidentialPardonForm
 * 
 * 			A form can only be executed if:
 * 				1. It has already been signed.
 * 				2. The executing Bureaucrat has a grade high enough to execute it.
 * 
 * 			If either condition is not met, the appropriate exception is thrown. Each concrete
 * 			form implements its own action logic inside the execute() method, demonstrating
 * 			how abstract classes provide structure while allowing specialized behavior.
 * 
 * @usage:
 * 			1. Compile:	make
 * 			2. Run:		./advancedForm
 * 			3. CleanUp:	make fclean
*/

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    try {
        std::cout << "=== Creating Bureaucrats ===" << std::endl;
        Bureaucrat high("Alice", 1);
        Bureaucrat mid("Bob", 72);
        Bureaucrat low("Charlie", 150);

        std::cout << high << std::endl;
        std::cout << mid << std::endl;
        std::cout << low << std::endl;

        std::cout << "\n=== Creating Forms ===" << std::endl;
        ShrubberyCreationForm shrub("Home");
        RobotomyRequestForm robo("Bender");
        PresidentialPardonForm pardon("Marvin");

        std::cout << shrub << std::endl;
        std::cout << robo << std::endl;
        std::cout << pardon << std::endl;

        std::cout << "\n=== Trying to sign with low-grade Bureaucrat ===" << std::endl;
        low.signForm(shrub);

        std::cout << "\n=== Signing with mid and high Bureaucrats ===" << std::endl;
        mid.signForm(shrub);   // should succeed
        high.signForm(robo);   // should succeed
        high.signForm(pardon); // should succeed

        std::cout << "\n=== Executing forms ===" << std::endl;
        low.executeForm(shrub); // fail (too low)
        mid.executeForm(shrub); // should work (Shrubbery needs 137 to exec)
        high.executeForm(robo); // should work
        high.executeForm(pardon); // should work

        std::cout << "\n=== Trying to execute unsigned form ===" << std::endl;
        RobotomyRequestForm unsignedForm("R2D2");
        high.executeForm(unsignedForm); // should throw (not signed)

    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return (0);
}