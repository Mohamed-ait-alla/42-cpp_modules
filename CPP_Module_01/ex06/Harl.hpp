#pragma once

// headers
#include <iostream>


// Ansi colors
#define RED			"\033[31m"
#define GREEN		"\033[32m"
#define YELLOW		"\033[33m"
#define BLUE		"\033[34m"
#define CYAN		"\033[36m"
#define RESET		"\033[0m"
#define BOLD		"\033[1m"

// enum for levels
enum Level {
	DEBUG,
	INFO,
	WARNING,
	ERROR
};


// Harl class declaration
class Harl {
	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
	
	public:
		void	complain( std::string level );
};