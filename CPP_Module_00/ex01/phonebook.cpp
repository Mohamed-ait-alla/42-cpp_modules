#include "phonebook.hpp"

PhoneBook::PhoneBook(void)
{
	contactSize = 0;
}

void	PhoneBook::addContact()
{
	Contact tmp;
	static int stmp;

	// get infos from the user
	std::cout << "Enter Your First Name: ";
	getline(std::cin, tmp.firstName);
	std::cout << "Enter Your Last Name: ";
	getline(std::cin, tmp.lastName);
	std::cout << "Enter Your Nick Name: ";
	getline(std::cin, tmp.nickName);
	std::cout << "Enter Your Phone Number: ";
	getline(std::cin, tmp.phoneNumber);
	std::cout << "Enter Your Darkest Secret: ";
	getline(std::cin, tmp.darkestSecret);
	// empty feilds: print error message
	if (tmp.firstName.empty() || tmp.lastName.empty() 
		|| tmp.nickName.empty() || tmp.phoneNumber.empty() 
		|| tmp.darkestSecret.empty())
	{
		std::cout << "Oops!, Please fill out all the feilds!\n";
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

	std::cout << "____________________Search For a Contact____________________\n";
	// if phonebook is empty print error msg
	if (contactSize == 0)
	{
		std::cout << "PhoneBook is empty!!\n";
		return ;
	}
	// Display available contacts
	std::cout << "|     Index| FirstName|  LastName|  NickName|\n";
	for (int i = 0; i < contactSize; i++)
	{
		std::cout << std::right;
		std::cout << "|" << std::setw(10) << i;
		std::cout << "|" << std::setw(10) << formatFeild(contacts[i].firstName);
		std::cout << "|" << std::setw(10) << formatFeild(contacts[i].lastName);
		std::cout << "|" << std::setw(10) << formatFeild(contacts[i].nickName) << "|" << std::endl;
	}
	// Display contact information specified by the user
	while (1)
	{
		std::cout << "For more detail informations, Enter the desired index? ";
		getline(std::cin, userIndex);
		// check if the index entred contains only digits
		if (strspn(userIndex.c_str(), DIGITS) != userIndex.length())
		{
			std::cout << "Error: Invalid index! (use digits only)\n";
			continue ;
		}
		index = atoi(userIndex.c_str());
		if (index < 0 || index > contactSize)
		{
			/* Notes:
				* Check if it is contactSize or MAX_CONTACTS 
				* Overflow can occur here, so it can bypass this check
			*/ 
			std::cout << "Oops! Your Index is Out-Of-Range\n";
			continue ;
		}
		break ;
	}
	std::cout << "_______________Contact Details________________\n";
	std::cout << "First Name: " << contacts[index].firstName << std::endl;
	std::cout << "Last Name: " << contacts[index].lastName << std::endl;
	std::cout << "Nick Name: " << contacts[index].nickName << std::endl;
	std::cout << "Phone Number: " << contacts[index].phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << contacts[index].darkestSecret << std::endl;
}

