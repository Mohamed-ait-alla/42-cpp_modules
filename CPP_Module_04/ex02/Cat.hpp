// ****************************************************************************************** //
//                               file: Cat.hpp                                                //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/12 19:40 by mait-all                        //
//                               Updated: 2025/11/07 11:37 by mait-all                        //
// ****************************************************************************************** //

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"


// ************************************************************************** //
//                                  Cat Class                                 //
// ************************************************************************** //

class Cat : public AAnimal {

	public:
		// ocf
		Cat();
		Cat(const Cat& other);
		Cat&	operator=(const Cat& other);
		~Cat();

		// Member funtions
		void	makeSound(void) const;
		Brain*	getBrain() const;

	private:
		Brain*	_brain;

};