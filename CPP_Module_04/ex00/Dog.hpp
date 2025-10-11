// ****************************************************************************************** //
//                               file: Dog.hpp                                                //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/08 09:08 by mait-all                        //
//                               Updated: 2025/10/11 13:16 by mait-all                        //
// ****************************************************************************************** //

#pragma once

#include "Animal.hpp"


// ************************************************************************** //
//                                   Dog Class                                //
// ************************************************************************** //

class Dog : public Animal {

	public:
		// ocf
		Dog();
		Dog(const Dog& other);
		Dog&	operator=(const Dog& other);
		~Dog();

		// member functions
		void	makeSound(void) const;
};