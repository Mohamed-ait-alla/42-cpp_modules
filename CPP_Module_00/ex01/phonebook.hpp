#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include "contact.hpp"

class PhoneBook {
	private:
	Contact contacts[8];
	
	public:
	void	addContact(std::string firstName, std::string lastName, 
						std::string nickName, std::string phoneNumber,
						std::string darkestSecret);
};


#endif