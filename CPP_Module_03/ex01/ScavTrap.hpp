// ****************************************************************************************** //
//                               file: ScavTrap.hpp                                           //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/09/28 17:55 by mait-all                        //
//                               Updated: 2025/09/29 11:52 by mait-all                        //
// ****************************************************************************************** //

#include "ClapTrap.hpp"


// ************************************************************************** //
//                               ScavTrap Class                               //
// ************************************************************************** //

class ScavTrap : public ClapTrap {

	public:
		// ocf
		ScavTrap();
		ScavTrap(const ScavTrap& other);
		ScavTrap&	operator=(const ScavTrap& other);
		~ScavTrap();

		// parametrised constructor
		ScavTrap(std::string newName);

		// member functions
		void	attack(const std::string& target);
		void	guardGate();
		
};

