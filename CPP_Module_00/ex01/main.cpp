/*
 * @Author:
 *          Mohamed Ait Alla
 *
 * @Description:
 *               A simple command-line phonebook application that can store up to 8 contacts.
 *               Each contact has a first name, last name, nick name, phone number, and a darkest secret.
 *               The user can add a new contact, search and view stored contacts, or exit the program.
 * 
 * @Usage:
 *          ./phonebook
*/

#include "phonebook.hpp"

int main()
{
	PhoneBook	phoneb;
	std::string userInput;

	do
	{
		std::cout << CYAN "------------ PhoneBook Menu ------------" RESET << std::endl;
		std::cout << YELLOW "- 1. Add a Contact" << std::endl;
		std::cout << YELLOW "- 2. Search for a Contact" << std::endl;
		std::cout << YELLOW "- 3. Exit" << std::endl;
		std::cout << CYAN "----------------------------------------" RESET << std::endl;
		std::cout << GREEN "Enter Your Option: (ADD, SEARCH, EXIT)" RESET << std::endl;
		getline(std::cin, userInput);
		checkForEof();
		if (userInput == "ADD")
			phoneb.addContact();
		else if (userInput == "SEARCH")
			phoneb.searchContact();

		
	} while (userInput.compare("EXIT") != 0);
	
}