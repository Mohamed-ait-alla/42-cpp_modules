#include "phonebook.hpp"

void	PhoneBook::addContact(std::string firstName, std::string lastName, 
						std::string nickName, std::string phoneNumber,
						std::string darkestSecret)
{
	contacts[0].setContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
	// std::cout << "-----------------------displaying-----------------\n";
	// std::cout << "" + contacts[0].displayContact();
}