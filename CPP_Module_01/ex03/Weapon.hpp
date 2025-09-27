// ****************************************************************************************** //
//                               file: Weapon.hpp                                             //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/08/15 21:24 by mait-all                        //
// ****************************************************************************************** //

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

// ************************************************************************** //
//                               Weapon Class                                 //
// ************************************************************************** //

class Weapon {
	private:
		std::string	_type;

	public:
		Weapon( std::string t );
		const std::string&	getType( void );
		void				setType( std::string newType );
};

#endif /* __WEAPON_HPP__ */