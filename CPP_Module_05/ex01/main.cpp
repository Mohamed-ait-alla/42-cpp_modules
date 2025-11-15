/*
 * @author:
 * 			mait-all
 * 
 * @github:
 * 			https://github.com/Mohamed-ait-alla
 * 
 * @description:
 * 			This exercise expands the exception-handling system by introducing the Form class.
 * 			Each Form has the following attributes:
 * 				- A constant name
 * 				- A boolean indicating whether the form is signed (during construction each Form should be unsigned)
 * 				- A required grade to sign the form
 * 				- A required grade to execute the form
 * 
 * 			The beSigned() member function allows a Bureaucrat to attempt to sign the form.
 * 			If the Bureaucrat's grade is higher than the required grade (numerically larger),
 * 			a GradeTooLowException is thrown. Otherwise, the form becomes signed.
 * 
 * 			The Bureaucrat class is extended with the signForm() method, which calls
 * 			form.beSigned(*this) and reports whether the signing attempt succeeded or failed.
 * 
 * @usage:
 * 			1. Compile:	make
 * 			2. Run:		./form
 * 			3. CleanUp:	make fclean
*/

#include "Form.hpp"

int main(void)
{

    try {
        std::cout << "\n=== Creating Bureaucrats ===" << std::endl;
        Bureaucrat bob("Bob", 1);
        Bureaucrat tom("Tom", 149);

        std::cout << bob << std::endl;
        std::cout << tom << std::endl;

        std::cout << "\n=== Creating Forms ===" << std::endl;
        Form taxForm("Tax Form", 1, 10);
        Form leaveForm("Leave Request", 100, 150);

        std::cout << taxForm << std::endl;
        std::cout << leaveForm << std::endl;

        std::cout << "\n=== Trying to sign with low-grade bureaucrat ===" << std::endl;
        tom.signForm(taxForm);  // should fail

        std::cout << "\n=== Signing with high-grade bureaucrat ===" << std::endl;
        bob.signForm(taxForm);  // should succeed

        std::cout << "\n=== Trying to sign already signed form ===" << std::endl;
        bob.signForm(taxForm);  // should do nothing / output already signed

        std::cout << "\n=== Form State After Signing ===" << std::endl;
        std::cout << taxForm << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "⚠️ Exception: " << e.what() << std::endl;
    }

    return 0;
}