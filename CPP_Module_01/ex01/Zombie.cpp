#include "Zombie.hpp"

// Default constructor
Zombie::Zombie() {}

// Destructor
Zombie::~Zombie()
{
	std::cout << _name << ": Has Been Destroyed!" << std::endl;
}

// member function
void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// setter
void	Zombie::setName(std::string newName)
{
	_name = newName;
}