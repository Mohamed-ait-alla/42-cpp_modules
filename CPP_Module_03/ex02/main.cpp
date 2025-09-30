/*
 * @author:
 * 			ToDo...
 * 
 * @github:
 * 			ToDo...
 * 
 * @description:
 * 				ToDo...
 * 
 * @usage:
 * 			ToDo...
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
	frag5.highFivesGuys();

	std::cout << std::endl;
	return (0);
}