#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>


// Zombie class definition
class Zombie {
	private:
		std::string	_name;

	public:
		~Zombie();
		void	setName(std::string newName);
		void	announce( void );
};

Zombie*	zombieHorde(int N, std::string name);

#endif