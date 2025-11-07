// ****************************************************************************************** //
//                               file: Animal.hpp                                             //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/12 19:40 by mait-all                        //
//                               Updated: 2025/11/07 11:23 by mait-all                        //
// ****************************************************************************************** //

#pragma once

#include <iostream>


// ************************************************************************** //
//                                 Animal Class                               //
// ************************************************************************** //

class AAnimal {

	public:
		// ocf
		AAnimal();
		AAnimal(const AAnimal& other);
		AAnimal&	operator=(const AAnimal& other);
		virtual ~AAnimal();

		// member functions
		virtual void				makeSound(void) const = 0;
		virtual std::string			getType(void) const;
	
	protected:
		std::string	type;
};