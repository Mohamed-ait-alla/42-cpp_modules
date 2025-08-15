# include <iostream>

#pragma once

// Zombie class definition
class Zombie {
	private:
	std::string	name;

	public:
		~Zombie();
		void	setName(std::string newName);
		void	announce( void );
};

Zombie*	zombieHorde(int N, std::string name);