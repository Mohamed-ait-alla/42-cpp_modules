#include "Harl.hpp"

// Private member functions definitions
void	Harl::debug( void )
{
	std::cout << BLUE "{DEBUG}" RESET << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
			  << std::endl;
}

void	Harl::info( void )
{
	std::cout << GREEN "{INFO}" RESET << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
			  << std::endl;
}

void	Harl::warning( void )
{
	std::cout << YELLOW "{WARNING}" RESET << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
			  << std::endl;
}

void	Harl::error( void )
{
	std::cout << RED "{ERROR}" RESET << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now."
			  << std::endl;
}

// Public member function definition
void	Harl::complain( std::string level)
{
	int	i;
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	void	(Harl::*funcs[])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	// Empty string
	if (level.empty())
	{
		std::cout << CYAN "[ No level provided! ]" RESET << std::endl;
		return ;
	}
	// Find the level and call its function
	for (i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*funcs[i])();
			return ;
		}
	}
	// Invalid level
	if (i == 4)
		std::cout << CYAN "[ Undefined level! ]" RESET << std::endl;
}