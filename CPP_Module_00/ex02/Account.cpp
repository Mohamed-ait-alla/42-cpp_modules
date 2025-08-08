#include <iostream>
#include <ctime>
#include "Account.hpp"

// init static variables
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// constructor of the Account class
Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts ++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";created" << std::endl;
}

// destructor of the Account class
Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";closed" << std::endl;
}

std::string getCurrentTime()
{
	char	formattedDateTime[80];
	time_t	timestamp;
	struct tm	*dateTime;
	
	time(&timestamp);
	dateTime = localtime(&timestamp);
	strftime(formattedDateTime, sizeof(formattedDateTime), "[%Y%m%d_%H%M%S] ", dateTime);
	return (formattedDateTime);
}

// function that displays the current time
void	Account::_displayTimestamp( void )
{
	std::cout << getCurrentTime();
}