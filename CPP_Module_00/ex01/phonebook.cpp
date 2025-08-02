#include "phonebook.hpp"

void	PhoneBook::setCountContact(int nCountContact)
{
	countContact = nCountContact;
}

int	PhoneBook::getCountContact()
{
	return (countContact);
}

void	PhoneBook::addContact()
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;

	std::cout << "Enter Your First Name: ";
	getline(std::cin, firstName);
	std::cout << "Enter Your Last Name: ";
	getline(std::cin, lastName);
	std::cout << "Enter Your Nick Name: ";
	getline(std::cin, nickName);
	std::cout << "Enter Your Phone Number: ";
	getline(std::cin, phoneNumber);
	std::cout << "Enter Your Darkest Secret: ";
	getline(std::cin, darkestSecret);
	
	if (firstName.empty() || lastName.empty() || nickName.empty() || phoneNumber.empty() || darkestSecret.empty())
	{
		std::cout << "Oops!, Please fill out all the feilds!\n";
		return ;
	}
	if (getCountContact() < 1)
	{
		contacts[getCountContact()].setContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
		std::cout << "Contact N" << getCountContact() + 1 << " has been added successfully\n";
		setCountContact(getCountContact() + 1);
	}
	else{
		contacts[getCountContact() % 2].setContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
		setCountContact(getCountContact() + 1);
	}
	// std::cout << "-----------------------displaying-----------------\n";
	// std::cout << "" + contacts[0].displayContact();
}