#include "phonebook.hpp"

// utilities
void	checkForEof()
{
	if (std::cin.eof())
		exit (0);
}

std::string	checkUserInput( std::string feild )
{
	std::string	userInput;

	do
	{
		std::cout << GREEN BOLD "Enter Your " << feild << ": " RESET;
		getline(std::cin, userInput);
		checkForEof();
		if (userInput.empty())
			std::cout << RED << "Oops! The feild can not be empty" << RESET << std::endl;
	} while (userInput.empty());
	return (userInput);
}

//		#____PhoneBook class member implementations____#

// constructor
PhoneBook::PhoneBook(void)
{
	contactSize = 0;
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

	if (contactSize < MAX_CONTACTS)
	{
		// add contact normally
		contacts[contactSize] = tmp;
		std::cout << CYAN BOLD "Contact N" << contactSize + 1 << " added successfully!" RESET << std::endl;
		contactSize ++;
	}
	else
	{
		// if phoneBook is full start overwrite oldest contacts
		contacts[(contactSize + stmp) % MAX_CONTACTS] = tmp;
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
	std::string userIndex;
	int			index;

	std::cout << CYAN BOLD "\n========== SEARCH CONTACT ==========\n" RESET;
	// if phonebook is empty print error msg
	if (contactSize == 0)
	{
		std::cout << "PhoneBook is empty!!\n";
		return ;
	}
	// Display available contacts
	std::cout << YELLOW BOLD "|     Index| FirstName|  LastName|  NickName|" RESET << std::endl;
	for (int i = 0; i < contactSize; i++)
	{
		std::cout << std::right;
		std::cout << BLUE "|" << std::setw(10) << i;
		std::cout << BLUE "|" << std::setw(10) << formatFeild(contacts[i].getFName());
		std::cout << BLUE "|" << std::setw(10) << formatFeild(contacts[i].getLName());
		std::cout << BLUE "|" << std::setw(10) << formatFeild(contacts[i].getNkName()) << "|" RESET << std::endl;
	}
	// Display contact information specified by the user
	while (1)
	{
		std::cout << GREEN BOLD "For more detail informations, Enter the desired index? " RESET;
		getline(std::cin, userIndex);
		checkForEof();
		// check if the index entred contains only digits
		if (strspn(userIndex.c_str(), DIGITS) != userIndex.length())
		{
			std::cout << RED "Error: Invalid index! (use digits only)" RESET << std::endl;
			continue ;
		}
		index = atoi(userIndex.c_str());
		// check if index is not out-of-range
		if (index < 0 || index > contactSize || userIndex.length() >= 2)
		{
			std::cout << RED "Oops! Your Index is Out-Of-Range" RESET << std::endl;
			continue ;
		}
		break ;
	}
	std::cout << MAGENTA BOLD "\n--- Contact Details ---\n" RESET;
	std::cout << BOLD "First Name: " RESET << contacts[index].getFName() << std::endl;
	std::cout << BOLD "Last Name: " RESET << contacts[index].getLName() << std::endl;
	std::cout << BOLD "Nick Name: " RESET << contacts[index].getNkName() << std::endl;
	std::cout << BOLD "Phone Number: " RESET << contacts[index].getPNumber() << std::endl;
	std::cout << BOLD "Darkest Secret: " RESET << contacts[index].getDSecret() << std::endl;
}

//		#____Contact class member implementations____#

// getters
std::string	Contact::getFName()
{
	return (_firstName);
}

std::string Contact::getLName()
{
	return (_lastName);
}

std::string Contact::getNkName()
{
	return (_nickName);
}

std::string	Contact::getPNumber()
{
	return (_phoneNumber);
}

std::string	Contact::getDSecret()
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

