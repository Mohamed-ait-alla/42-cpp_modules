#include "contact.hpp"
#include <iostream>

void	Contact::setContact(std::string first, std::string last,
						 std::string nick, std::string phone, 
						 std::string secretMsg)
{
	firstName = first;
	lastName = last;
	nickName = nick;
	phoneNumber = phone;
	darkestSecret = secretMsg;
}

void	Contact::displayContact()
{
	std::cout << "-------------Contact Details-------------\n";
	std::cout << firstName << "\n";
	std::cout << lastName << "\n";
	std::cout << nickName << "\n";
	std::cout << phoneNumber << "\n";
	std::cout << darkestSecret << "\n";
}