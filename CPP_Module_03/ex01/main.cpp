/*
 * @author:
 * 			mait-all
 * 
 * @github:
 * 			https://github.com/Mohamed-ait-alla
 * 
 * @description:
 * 			This program demonstrates inheritance in C++ using the ScavTrap class,
 * 			which publicly inherits from ClapTrap.
 * 
 * 			ScavTrap extends the behavior of ClapTrap by:
 * 				- Redefining the attack(const std::string& target) method
 * 				  with a custom attack message.
 * 				- Adding a new member function guardGate(), which enables
 * 				  Gate Keeper mode.
 *
 * 			The program showcases how derived classes can reuse and customize
 * 			base class functionality.
 * 
 * @usage:
 * 			1. Compile:	make
 * 			2. Run:		./scavTrap
 * 			3. CleanUp:	make fclean
*/


#include "ScavTrap.hpp"

int main( void )
{
	std::cout << "=== CPP03 EX01 SCAVTRAP TESTS ===" << std::endl;
	std::cout << std::endl;

	// Test 1: Basic Construction
	std::cout << "--- Test 1: Constructor Tests ---" << std::endl;
	ScavTrap scav1("GuardBot");
	ScavTrap scav2;
	ScavTrap scav3(scav1);
	ScavTrap scav4;
	scav4 = scav1; 

	std::cout << std::endl;

	// Inheritance: ScavTrap can do everthing ClapTrap can
	std::cout << "--- Test 2: Inherited Functionality ---" << std::endl;
	scav1.attack("Intruder");
	scav1.takeDamage(30);
	scav1.beRepaired(15);

	std::cout << std::endl;

   std::cout << "--- Test 3: ScavTrap Special Ability ---" << std::endl;
	scav1.guardGate();
	scav2.guardGate();

	std::cout << std::endl;

  std::cout << "--- Test 4: Hit Point Management ---" << std::endl;
	ScavTrap scav5("ToughBot");
	scav5.takeDamage(99);  // Almost dead
	scav5.attack("Enemy"); // Should work
	scav5.takeDamage(5);   // Should die
	scav5.attack("Enemy"); // Should fail - dead
	scav5.beRepaired(10);  // Should fail - dead
	scav5.guardGate();
		
	std::cout << std::endl;
	return (0);
}