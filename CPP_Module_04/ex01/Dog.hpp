// ****************************************************************************************** //
//                               file: Dog.hpp                                                //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/11 20:04 by mait-all                        //
//                               Updated: 2025/10/11 21:53 by mait-all                        //
// ****************************************************************************************** //

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"


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
	
	private:
		Brain*	brain;
};