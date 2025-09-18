#include "phonebook.hpp"

//		#____utilities____#

// Handle end-of-file in getline()
void	checkForEof()
{
	if (std::cin.eof())
		exit (0);
}

// check if a feild has only spaces
bool	isOnlySpaces( std::string feild )
{
	size_t	count = 0;

	for(int i = 0; feild[i]; i++)
	{
		if (feild[i] <= (char)ASCII_SPACE)
			count++;
	}
	return ((count == feild.length()) ? 1 : 0);
}

// getting and checking user input for empty feilds
std::string	checkUserInput( std::string feild )
{
	std::string	userInput;
	bool		pNumberCheck;

	do
	{
		pNumberCheck = false;
		std::cout << GREEN BOLD "Enter Your " << feild << ": " RESET;
		getline(std::cin, userInput);
		checkForEof();
		if (userInput.empty() || isOnlySpaces(userInput))
		{
			std::cout << RED << "Oops! The feild can not be empty" << RESET << std::endl;
			continue;
		}
		if (feild == "Phone Number")
		{
			if (strspn(userInput.c_str(), DIGITS) != userInput.length())
			{
				std::cout << RED "Oops! Invalid Phone Number (use only digits)" RESET << std::endl;
				pNumberCheck = true;
			}
		}
	} while (userInput.empty() || isOnlySpaces(userInput) || pNumberCheck);
	return (userInput);
}

//		#____PhoneBook class member implementations____#

// constructor
PhoneBook::PhoneBook(void)
{
	_contactSize = 0;
}

// add a new contact
void	PhoneBook::addContact()
{
	std::string	input;
	static int	stmp;
	Contact		tmp;
	
	std::cout << YELLOW "\n------ Add New Contact ------\n" RESET;

	// get infos from user
	input = checkUserInput("First Name");
	tmp.setFName(input);

	input = checkUserInput("Last Name");
	tmp.setLName(input);

	input = checkUserInput("Nick Name");
	tmp.setNkName(input);

	input = checkUserInput("Phone Number");
	tmp.setPNumber(input);

	input = checkUserInput("Darkest Secret");
	tmp.setDSecret(input);

	if (_contactSize < _MAX_CONTACTS)
	{
		// add contact normally
		_contacts[_contactSize] = tmp;
		std::cout << CYAN BOLD "Contact N" << _contactSize + 1 << " added successfully!" RESET << std::endl;
		_contactSize ++;
	}
	else
	{
		// if phoneBook is full start overwrite oldest contacts
		_contacts[(_contactSize + stmp) % _MAX_CONTACTS] = tmp;
		std::cout << YELLOW BOLD "Phonebook full. Oldest contact overwritten!" RESET << std::endl;
		stmp++;
	}
}

// formatting output
std::string formatFeild(std::string arg)
{
	if (arg.length() > 10)
		return (arg.substr(0, 9) + ".");
	return (arg);
}

// search for a contact
void	PhoneBook::searchContact()
{
	std::string	userIndex;
	int			index;

	std::cout << CYAN BOLD "\n========== SEARCH CONTACT ==========\n" RESET;
	// if phonebook is empty print error msg
	if (_contactSize == 0)
	{
		std::cout << "PhoneBook is empty!!\n";
		return ;
	}
	// Display available contacts
	std::cout << YELLOW BOLD "|     Index| FirstName|  LastName|  NickName|" RESET << std::endl;
	for (int i = 0; i < _contactSize; i++)
	{
		std::cout << std::right;
		std::cout << BLUE "|" << std::setw(10) << i;
		std::cout << BLUE "|" << std::setw(10) << formatFeild(_contacts[i].getFName());
		std::cout << BLUE "|" << std::setw(10) << formatFeild(_contacts[i].getLName());
		std::cout << BLUE "|" << std::setw(10) << formatFeild(_contacts[i].getNkName()) << "|" RESET << std::endl;
	}
	// Display contact information specified by the user
	while (1)
	{
		std::cout << GREEN BOLD "For more detail informations, Enter the desired index? " RESET;
		getline(std::cin, userIndex);
		checkForEof();
		// if index is empty
		if (userIndex.empty())
		{
			std::cout << RED "Error: Invalid index! (can not be empty)" RESET << std::endl;
			continue;
		}
		// check if the index entred contains only digits
		if (strspn(userIndex.c_str(), DIGITS) != userIndex.length())
		{
			std::cout << RED "Error: Invalid index! (use digits only)" RESET << std::endl;
			continue ;
		}
		index = atoi(userIndex.c_str());
		// check if index is out-of-range => repeat process
		if (index < 0 || index >= _contactSize || userIndex.length() >= 2)
		{
			std::cout << RED "Oops! Your Index is Out-Of-Range" RESET << std::endl;
			continue ;
		}
		break ;
	}
	std::cout << MAGENTA BOLD "\n--- Contact Details ---\n" RESET;
	std::cout << BOLD "First Name: " RESET << _contacts[index].getFName() << std::endl;
	std::cout << BOLD "Last Name: " RESET << _contacts[index].getLName() << std::endl;
	std::cout << BOLD "Nick Name: " RESET << _contacts[index].getNkName() << std::endl;
	std::cout << BOLD "Phone Number: " RESET << _contacts[index].getPNumber() << std::endl;
	std::cout << BOLD "Darkest Secret: " RESET << _contacts[index].getDSecret() << std::endl;
}

//		#____Contact class member implementations____#

// getters
std::string	Contact::getFName() const
{
	return (_firstName);
}

std::string Contact::getLName() const
{
	return (_lastName);
}

std::string Contact::getNkName() const
{
	return (_nickName);
}

std::string	Contact::getPNumber() const
{
	return (_phoneNumber);
}

std::string	Contact::getDSecret() const
{
	return (_darkestSecret);
}

// setters
void	Contact::setFName( std::string fName )
{
	_firstName = fName;
}

void	Contact::setLName( std::string lName )
{
	_lastName = lName;
}

void	Contact::setNkName( std::string nkName )
{
	_nickName = nkName;
}

void	Contact::setPNumber( std::string pNumber )
{
	_phoneNumber = pNumber;
}

void	Contact::setDSecret( std::string dSecret )
{
	_darkestSecret = dSecret;
}

