// ****************************************************************************************** //
//                               file: Animal.hpp                                             //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/08 08:51 by mait-all                        //
//                               Updated: 2025/10/11 13:15 by mait-all                        //
// ****************************************************************************************** //

#pragma once

#include <iostream>


// ************************************************************************** //
//                                 Animal Class                               //
// ************************************************************************** //

class Animal {

	public:
		// ocf
		Animal();
		Animal(const Animal& other);
		Animal&	operator=(const Animal& other);
		virtual ~Animal();

		// member functions
		virtual void		makeSound(void) const;
		std::string			getType(void) const;
	
	protected:
		std::string	type;
};