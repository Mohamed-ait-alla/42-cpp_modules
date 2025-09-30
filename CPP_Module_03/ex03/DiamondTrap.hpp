// ****************************************************************************************** //
//                               file: DiamondTrap.hpp                                           //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/09/30 10:44 by mait-all                        //
//                               Updated: 2025/09/30 10:58 by mait-all                        //
// ****************************************************************************************** //

#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"


// ************************************************************************** //
//                               ClapTrap Class                               //
// ************************************************************************** //

class DiamondTrap : public ScavTrap, public FragTrap {

	public:
		// ocf
		DiamondTrap();
		DiamondTrap(const DiamondTrap& other);
		DiamondTrap&	operator=(const DiamondTrap& other);
		~DiamondTrap();

		// parametrised constructor
		DiamondTrap(std::string newName);

		// member functions
		void	whoAmI();
	
	private:
		std::string	_name;

};