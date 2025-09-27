// ****************************************************************************************** //
//                               file: HumanA.hpp                                             //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/08/15 21:24 by mait-all                        //
// ****************************************************************************************** //

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

// ************************************************************************** //
//                               HumanA Class                                 //
// ************************************************************************** //

class HumanA {
	private:
		Weapon&		humanAWeapon;
		std::string	name;
	
	public:
		HumanA(std::string manName, Weapon& weapon);
		void	attack(void);
};

#endif /* __HUMANA_HPP__*/