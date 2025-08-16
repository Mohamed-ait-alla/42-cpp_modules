#pragma once

#include <iostream>


class Weapon {
	private:
		std::string type;

	public:
		Weapon(std::string t);
		const std::string& getType(void);
		void	setType(std::string newType);
};