#pragma once

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