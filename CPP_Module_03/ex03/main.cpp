/*
 * @author:
 * 			mait-all
 * 
 * @github:
 * 			https://github.com/Mohamed-ait-alla
 * 
 * @description:
 * 			This program demonstrates multiple inheritance and the diamond problem
 * 			in C++ through the DiamondTrap class.
 *
 * 			DiamondTrap inherits publicly from both ScavTrap and FragTrap, which
 * 			themselves derive from ClapTrap. This creates a diamond-shaped inheritance
 * 			structure that requires careful management using virtual inheritance.
 * 
 * 			DiamondTrap extends the behavior of its parents by:
 * 				- Combining functionality from ScavTrap and FragTrap.
 * 				- Redefining attack() to clarify which parent’s version is used.
 * 				- Introducing whoAmI(), which displays both its own name and
 * 				  its ClapTrap base name.
 *
 * 			The exercise illustrates how to handle ambiguity and resource sharing
 * 			in multiple inheritance scenarios.			
 * 
 * @usage:
 * 			1. Compile:	make
 * 			2. Run:		./diamondTrap
 * 			3. CleanUp:	make fclean
*/

#include "DiamondTrap.hpp"

int main( void )
{

    std::cout << "=== CPP03 EX03 DIAMONDTRAP TESTS ===" << std::endl;
    std::cout << std::endl;

    // Test 1: Object construction
    std::cout << "--- Test 1: DiamondTrap Construction ---" << std::endl;
    DiamondTrap diamond1("Sparkles");
    DiamondTrap diamond2("Shiny");
    DiamondTrap diamond3(diamond1);
    DiamondTrap diamond4;
    diamond4 = diamond2;
    
    std::cout << std::endl;

	// Test 3: Mixed Inheritance - Which functions come from where?
	std::cout << "--- Test 2: Mixed Inheritance Abilities ---" << std::endl;
    diamond1.attack("Target1");
    diamond1.guardGate();
    diamond1.highFivesGuys();
    diamond1.takeDamage(30);
    diamond1.beRepaired(15);

	std::cout << std::endl;

	// Test 2: whoAmI() - The Key Diamond Problem Test
	std::cout << "--- Test 3: whoAmI() - Diamond Problem Resolution ---" << std::endl;
    diamond1.whoAmI();
    diamond2.whoAmI();

	std::cout << std::endl;

    // Test 5: Resource Exhaustion Behavior
    std::cout << "--- Test 4: Resource Management ---" << std::endl;
	diamond2.takeDamage(95);
	diamond2.attack("target2");
	diamond2.takeDamage(5);
	diamond2.attack("target2");
	diamond2.beRepaired(50);

    std::cout << std::endl;

    std::cout << "=== ALL DIAMONDTRAP TESTS COMPLETED ===" << std::endl;
	std::cout << std::endl;
	return (0);
}