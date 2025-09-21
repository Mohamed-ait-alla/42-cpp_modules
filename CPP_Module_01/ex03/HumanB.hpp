#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"


class HumanB {
	private:
		Weapon*		humanBWeapon;
		std::string	name;
	
	public:
		HumanB(std::string manName);
		void	setWeapon(Weapon& weapon);
		void	attack(void);
};

#endif