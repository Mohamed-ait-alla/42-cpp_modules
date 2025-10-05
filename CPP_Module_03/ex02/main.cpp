/*
 * @author:
 * 			mait-all
 * 
 * @github:
 * 			https://github.com/Mohamed-ait-alla
 * 
 * @description:
 * 			This program demonstrates inheritance in C++ using the FragTrap class,
 * 			which publicly inherits from ClapTrap.
 * 
 * 			FragTrap extends ClapTrap by:
 * 				- Redefining the attack(const std::string& target) method
 * 				  with its own behavior and message.
 * 				- Adding a new member function highFivesGuys(), which
 * 				  requests a positive high five interaction.
 * 
 * 			This exercice is actually a repetitive work of previous exercice (ex01).
 * 
 * @usage:
 * 			1. Compile:	make
 * 			2. Run:		./fragTrap
 * 			3. CleanUp:	make fclean
*/


#include "FragTrap.hpp"

int main( void )
{
	std::cout << "=== CPP03 EX02 FRAGTRAP TESTS ===" << std::endl;
	std::cout << std::endl;

	// Test 1: Basic Construction
	std::cout << "--- Test 1: Constructor Tests ---" << std::endl;
	FragTrap frag1("GuardBot");
	FragTrap frag2;
	FragTrap frag3(frag1);
	FragTrap frag4;
	frag4 = frag1; 

	std::cout << std::endl;

	// Inheritance: FragTrap can do everthing ClapTrap can
	std::cout << "--- Test 2: Inherited Functionality ---" << std::endl;
	frag1.attack("Intruder");
	frag1.takeDamage(30);
	frag1.beRepaired(15);

	std::cout << std::endl;

   std::cout << "--- Test 3: FragTrap Special Ability ---" << std::endl;
	frag1.highFivesGuys();
	frag2.highFivesGuys();

	std::cout << std::endl;

  std::cout << "--- Test 4: Hit Point Management ---" << std::endl;
	FragTrap frag5("ToughBot");
	frag5.takeDamage(99);  // Almost dead
	frag5.attack("Enemy"); // Should work
	frag5.takeDamage(5);   // Should die
	frag5.attack("Enemy"); // Should fail - dead
	frag5.beRepaired(10);  // Should fail - dead
	frag5.highFivesGuys(); // Should fail - dead

	std::cout << std::endl;
	return (0);
}