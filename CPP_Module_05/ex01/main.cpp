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