/*
 * @author:
 *			mait-all
 * 
 * @github:
 * 			https://github.com/Mohamed-ait-alla
 * 
 * @description:
 * 			This exercice consists of recreating the missing implementation file (Account.cpp)
 * 			from a given header (Account.hpp) and a test file (tests.cpp). So you need to implement
 * 			all the class member and static funcions to make it work.
 * 
 *  @usage:
 * 			./bank_system
*/

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

// ----------- static methods ------------

// getters
int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

// print summary of all accounts
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
			  << ";total:" << _totalAmount
			  << ";deposits:" << _totalNbDeposits
			  << ";withdrawals:" << _totalNbWithdrawals
			  << std::endl;
}


// -------- Instance methods ---------

int	Account::checkAmount( void ) const 
{
	return (_amount);
}
// print account status
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals
			  << std::endl;
}

// function that makes a deposit operation on each account
void	Account::makeDeposit( int deposit )
{
	int	prevAmount;

	prevAmount = _amount;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << prevAmount	
			  << ";deposit:" << deposit
			  << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits
			  << std::endl;
}

// function that makes a withdrawal operation on each account
bool	Account::makeWithdrawal( int withdrawal )
{
	int	prevAmount;

	if (withdrawal  <= _amount)
	{
		prevAmount = _amount;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;

		_displayTimestamp();
		std::cout << "index:" << _accountIndex
				  << ";p_amount:" << prevAmount
				  << ";withdrawal:" << withdrawal
				  << ";amount:" << _amount
				  << ";nb_withdrawals:" << _nbWithdrawals
				  << std::endl;
				  return (true);
	}

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << _amount
			  << ";withdrawal:refused" 
			  << std::endl;
	return (false);
}

std::string getCurrentTime()
{
	char		formattedDateTime[80];
	time_t		timestamp;
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