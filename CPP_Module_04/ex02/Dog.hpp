// ****************************************************************************************** //
//                               file: Dog.hpp                                                //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/12 19:40 by mait-all                        //
//                               Updated: 2025/11/07 11:35 by mait-all                        //
// ****************************************************************************************** //

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"


// ************************************************************************** //
//                                   Dog Class                                //
// ************************************************************************** //

class Dog : public AAnimal {

	public:
		// ocf
		Dog();
		Dog(const Dog& other);
		Dog&	operator=(const Dog& other);
		~Dog();

		// member functions
		void	makeSound(void) const;
		Brain*	getBrain() const;
	
	private:
		Brain*	_brain;
};