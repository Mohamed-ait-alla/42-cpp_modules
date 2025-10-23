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