// ****************************************************************************************** //
//                               file: HumanB.hpp                                             //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/08/15 21:24 by mait-all                        //
// ****************************************************************************************** //

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

// ************************************************************************** //
//                               HumanB Class                                 //
// ************************************************************************** //

class HumanB {
	private:
		Weapon*		humanBWeapon;
		std::string	name;
	
	public:
		HumanB(std::string manName);
		void	setWeapon(Weapon& weapon);
		void	attack(void);
};

#endif /* __HUMANB_HPP__ */