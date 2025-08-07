#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <cstring>

// needed constents
# define MAX_CONTACTS 2
# define DIGITS "0123456789"
// ANSI colors
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define CYAN		"\033[36m"
# define MAGENTA	"\033[35m"
# define RESET		"\033[0m"
# define BOLD		"\033[1m"

// Contact class declaration
class Contact {
	public:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
};

// Phonebook class declaration
class PhoneBook {
	private:
	Contact contacts[MAX_CONTACTS];
	int		contactSize;
	
	public:
	PhoneBook(void);
	void	addContact();
	void	searchContact();
	
	
};

// utility
void	checkForEof();
#endif