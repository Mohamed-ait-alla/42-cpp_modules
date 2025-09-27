// ****************************************************************************************** //
//                               file: Zombie.hpp                                             //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/08/10 18:53 by mait-all                        //
// ****************************************************************************************** //

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

// ************************************************************************** //
//                               Zombie Class                                 //
// ************************************************************************** //

class Zombie {
	private:
		std::string	_name;

	public:
		Zombie( std::string name );
		~Zombie();
		void	announce( void );
		
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name);

#endif /* __ZOMBIE_HPP__ */