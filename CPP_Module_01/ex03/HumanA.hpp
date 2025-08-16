#include "Weapon.hpp"

#pragma once

class HumanA {
	private:
		Weapon&		humanAWeapon;
		std::string	name;
	
	public:
		HumanA(std::string name, Weapon& weapon);
		void	attack(void);
};