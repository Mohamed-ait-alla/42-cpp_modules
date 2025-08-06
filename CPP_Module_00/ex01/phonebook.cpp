#include "phonebook.hpp"

PhoneBook::PhoneBook(void)
{
	contactSize = 0;
}

void	PhoneBook::addContact()
{
	Contact tmp;

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
		contacts[contactSize % MAX_CONTACTS] = tmp;
		contactSize ++;
	}
}

