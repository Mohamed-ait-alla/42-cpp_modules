#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <cstring>

// needed constents
# define DIGITS "0123456789"
# define ASCII_SPACE 32

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
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkestSecret;

	public:
		std::string	getFName() const;
		std::string	getLName() const;
		std::string	getNkName() const;
		std::string	getPNumber() const;
		std::string	getDSecret() const;

		void		setFName( std::string fName );
		void		setLName( std::string lName );
		void		setNkName( std::string nkName );
		void		setPNumber( std::string pNumber );
		void		setDSecret( std::string dSecret );
		
};

// Phonebook class declaration
class PhoneBook {
	private:
		static const int	_MAX_CONTACTS = 8;
		Contact				_contacts[_MAX_CONTACTS];
		int					_contactSize;

	public:
		PhoneBook(void);
		void	addContact();
		void	searchContact();
};

// utility
void	checkForEof();

#endif