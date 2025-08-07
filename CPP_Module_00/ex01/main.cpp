/*
 * Author: ToDo... 
 * Description:  ToDo..
 * Usage: ToDo...
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