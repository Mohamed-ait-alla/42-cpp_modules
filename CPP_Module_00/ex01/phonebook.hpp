#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include "contact.hpp"

class PhoneBook {
	private:
	Contact contacts[8];
	int		countContact;
	
	public:
	void	addContact();
	void	setCountContact(int countContact);
	int	getCountContact();
};


#endif