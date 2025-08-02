/*
 * Author: ToDo... 
 * Description:  ToDo..
 * Usage: ToDo...
*/

#include "phonebook.hpp"

int main()
{
	std::string userInput;

	do
	{
		std::cout << "------------ PhoneBook Menu ------------\n";
		std::cout << "- 1. Add a Contact\n";
		std::cout << "- 2. Search for a Contact\n";
		std::cout << "- 2. Exit\n";
		std::cout << "-----------------------------------------\n";
		std::cout << "Enter your choice (Add, search, exit)\n";
		getline(std::cin, userInput);
		std::cout << "choice entred is " + userInput << "\n";
		
	} while (userInput.compare("exit") != 0);
	
}