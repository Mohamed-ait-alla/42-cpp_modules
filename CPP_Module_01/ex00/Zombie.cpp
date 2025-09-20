#include "Zombie.hpp"

// Constructor
Zombie::Zombie(std::string zombieName)
{
	_name = zombieName;
}

// Destructor
Zombie::~Zombie()
{
	std::cout << _name << ": Has Been Destroyed!\n";
}

// member functions
void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}