#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <cstring>


# define MAX_CONTACTS 2
# define DIGITS "0123456789"

class Contact {
	public:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
};

class PhoneBook {
	private:
	Contact contacts[MAX_CONTACTS];
	int		contactSize;
	
	public:
	PhoneBook(void);
	void	addContact();
	void	searchContact();


};


#endif