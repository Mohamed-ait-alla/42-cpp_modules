#include "Zombie.hpp"

// Constructor
Zombie::Zombie(std::string zombieName)
{
	name = zombieName;
}

// Destructor
Zombie::~Zombie()
{
	std::cout << name << ": Has Been Destroyed!\n";
}

// member functions
void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}