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