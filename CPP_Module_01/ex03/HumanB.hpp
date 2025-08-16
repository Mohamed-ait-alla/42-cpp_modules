#include "Weapon.hpp"

#pragma once

class HumanB {
	private:
		Weapon*		humanBWeapon;
		std::string	name;
	
	public:
		HumanB(std::string name);
		void	setWeapon(Weapon& weapon);
		void	attack(void);
};