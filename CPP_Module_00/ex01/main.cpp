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
		std::cout << "------------ PhoneBook Menu ------------\n";
		std::cout << "- 1. Add a Contact\n";
		std::cout << "- 2. Search for a Contact\n";
		std::cout << "- 2. Exit\n";
		std::cout << "-----------------------------------------\n";
		std::cout << "Enter your choice (ADD, SEARCH, EXIT)\n";
		getline(std::cin, userInput);
		if (userInput == "ADD")
			phoneb.addContact();

		
	} while (userInput.compare("EXIT") != 0);
	
}