#include "Zombie.hpp"

// Destructor
Zombie::~Zombie()
{
	std::cout << name << ": Has Been Destroyed!" << std::endl;
}

// member function
void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// setter
void	Zombie::setName(std::string newName)
{
	name = newName;
}