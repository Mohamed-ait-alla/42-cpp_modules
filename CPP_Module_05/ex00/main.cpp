/*
 * @author:
 * 			mait-all
 * 
 * @github:
 * 			https://github.com/Mohamed-ait-alla
 * 
 * @description:
 * 			This exercise introduces exception handling in C++ through the implementation
 * 			of a Bureaucrat class. A Bureaucrat has two attributes:
 * 				- A constant name
 * 				- A grade ranging from 1 (highest) to 150 (lowest)
 * 			
 * 			When constructing a Bureaucrat with an invalid grade, the class must throw
 * 			an appropriate exception. Two custom exception types are implemented:
 * 				- GradeTooHighException
 * 				- GradeTooLowException
 * 
 * 			The class also provides the member functions incrementGrade() and decrementGrade()
 * 			which they must check whether the resulting grade remains within
 * 			the valid range. If not, the corresponding exception is thrown.
 * 
 * 			The purpose of this exercice is to understand how c++ exceptions work,
 * 			how to define custom exception classes, and how to work with them.
 * 
 * @usage:
 * 			1. Compile:	make
 * 			2. Run:		./bureaucrat
 * 			3. CleanUp:	make fclean
*/

#include "Bureaucrat.hpp"

int main(void)
{
    // 1. Creating a valid Bureaucrat
    try {
        Bureaucrat bob("Bob", 75);
        std::cout << bob << std::endl;

        // Incrementing grade
        bob.incrementGrade();
        std::cout << "After increment: " << bob << std::endl;

        // Decrementing grade
        bob.decrementGrade();
        std::cout << "After decrement: " << bob << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "-----------------------------" << std::endl;

    // 2. Creating a Bureaucrat with grade too high
    try {
        Bureaucrat alice("Alice", 0);
    } catch (std::exception &e) {
        std::cout << "Caught Exception: " << e.what() << std::endl;
    }

    std::cout << "-----------------------------" << std::endl;

    // 3. Creating a Bureaucrat with grade too low
    try {
        Bureaucrat eve("Eve", 151);
    } catch (std::exception &e) {
        std::cout << "Caught Exception: " << e.what() << std::endl;
    }

    std::cout << "-----------------------------" << std::endl;

    // 4. Incrementing grade beyond upper limit
    try {
        Bureaucrat topGuy("TopGuy", 1);
        std::cout << topGuy << std::endl;
        topGuy.incrementGrade();  // Should throw
    } catch (std::exception &e) {
        std::cerr << "Caught Exception: " << e.what() << std::endl;
    }

    std::cout << "-----------------------------" << std::endl;

    // 5. Decrementing grade beyond lower limit
    try {
        Bureaucrat lowGuy("LowGuy", 150);
        std::cout << lowGuy << std::endl;
        lowGuy.decrementGrade();  // Should throw
    } catch (std::exception &e) {
        std::cerr << "Caught Exception: " << e.what() << std::endl;
    }

    return 0;
}