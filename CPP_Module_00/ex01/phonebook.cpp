#include "phonebook.hpp"

void	checkForEof()
{
	if (std::cin.eof())
		exit (0);
}

PhoneBook::PhoneBook(void)
{
	contactSize = 0;
}

void	PhoneBook::addContact()
{
	Contact tmp;
	static int stmp;
	
	std::cout << YELLOW "\n------ Add New Contact ------\n" RESET;
	// get infos from the user
	std::cout << GREEN BOLD "Enter Your First Name: " RESET;
	getline(std::cin, tmp.firstName);
	checkForEof();
	std::cout << GREEN BOLD "Enter Your Last Name: " RESET;
	getline(std::cin, tmp.lastName);
	checkForEof();
	std::cout << GREEN BOLD "Enter Your Nick Name: " RESET;
	getline(std::cin, tmp.nickName);
	checkForEof();
	std::cout << GREEN BOLD "Enter Your Phone Number: " RESET;
	getline(std::cin, tmp.phoneNumber);
	checkForEof();
	std::cout << GREEN BOLD "Enter Your Darkest Secret: " RESET;
	getline(std::cin, tmp.darkestSecret);
	checkForEof();
	// empty feilds: print error message
	if (tmp.firstName.empty() || tmp.lastName.empty() 
		|| tmp.nickName.empty() || tmp.phoneNumber.empty() 
		|| tmp.darkestSecret.empty())
	{
		std::cout << RED "Oops!, Please fill out all the feilds!" RESET << std::endl;
		return ;
	}
	if (contactSize < MAX_CONTACTS) // if phonebook contact is empty add the contact normally
	{
		
		contacts[contactSize] = tmp;
		contactSize ++;
	}
	else // else start overwrite the oldest ones
	{
		contacts[(contactSize + stmp) % MAX_CONTACTS] = tmp;
		stmp++;
	}
}

std::string formatFeild(std::string arg)
{
	if (arg.length() > 10)
		return (arg.substr(0, 9) + ".");
	return (arg);
}

void	PhoneBook::searchContact()
{
	std::string userIndex;
	int			index;

	std::cout << CYAN BOLD "\n========== SEARCH CONTACT ==========\n" RESET;
	// if phonebook is empty print error msg
	if (contactSize == 0)
	{
		std::cout << "PhoneBook is empty!!\n";
		return ;
	}
	// Display available contacts
	std::cout << YELLOW BOLD "|     Index| FirstName|  LastName|  NickName|" RESET << std::endl;
	for (int i = 0; i < contactSize; i++)
	{
		std::cout << std::right;
		std::cout << BLUE "|" << std::setw(10) << i;
		std::cout << BLUE "|" << std::setw(10) << formatFeild(contacts[i].firstName);
		std::cout << BLUE "|" << std::setw(10) << formatFeild(contacts[i].lastName);
		std::cout << BLUE "|" << std::setw(10) << formatFeild(contacts[i].nickName) << "|" RESET << std::endl;
	}
	// Display contact information specified by the user
	while (1)
	{
		std::cout << GREEN BOLD "For more detail informations, Enter the desired index? " RESET;
		getline(std::cin, userIndex);
		checkForEof();
		// check if the index entred contains only digits
		if (strspn(userIndex.c_str(), DIGITS) != userIndex.length())
		{
			std::cout << RED "Error: Invalid index! (use digits only)" RESET << std::endl;
			continue ;
		}
		index = atoi(userIndex.c_str());
		if (index < 0 || index > contactSize)
		{
			/* Notes:
				* Overflow can occur here, so it can bypass this check
			*/ 
			std::cout << RED "Oops! Your Index is Out-Of-Range" RESET << std::endl;
			continue ;
		}
		break ;
	}
	std::cout << MAGENTA BOLD "\n--- Contact Details ---\n" RESET;
	std::cout << BOLD "First Name: " RESET << contacts[index].firstName << std::endl;
	std::cout << BOLD "Last Name: " RESET << contacts[index].lastName << std::endl;
	std::cout << BOLD "Nick Name: " RESET << contacts[index].nickName << std::endl;
	std::cout << BOLD "Phone Number: " RESET << contacts[index].phoneNumber << std::endl;
	std::cout << BOLD "Darkest Secret: " RESET << contacts[index].darkestSecret << std::endl;
}

