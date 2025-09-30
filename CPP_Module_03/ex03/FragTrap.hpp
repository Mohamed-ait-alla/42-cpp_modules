// ****************************************************************************************** //
//                               file: FragTrap.hpp                                           //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/09/30 09:22 by mait-all                        //
//                               Updated: 2025/09/30 14:56 by mait-all                        //
// ****************************************************************************************** //

#pragma once

#include "ClapTrap.hpp"


// ************************************************************************** //
//                               FragTrap Class                               //
// ************************************************************************** //

class FragTrap : virtual public ClapTrap {

	public:
		// ocf
		FragTrap();
		FragTrap(const FragTrap& other);
		FragTrap&	operator=(const FragTrap& other);
		~FragTrap();

		// parametrised constructor
		FragTrap(std::string newName);

		// member functions
		void	attack(const std::string& target);
		void	highFivesGuys(void);

};