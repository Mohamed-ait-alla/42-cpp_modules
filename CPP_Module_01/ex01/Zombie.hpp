// ****************************************************************************************** //
//                               file: Zombie.hpp                                             //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/08/15 09:08 by mait-all                        //
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
		Zombie();
		~Zombie();
		void	setName(std::string newName);
		void	announce( void );
};

Zombie*	zombieHorde(int N, std::string name);

#endif /* __ZOMBIE_HPP__*/