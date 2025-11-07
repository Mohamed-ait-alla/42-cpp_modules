// ****************************************************************************************** //
//                               file: Cat.cpp                                                //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/11 20:04 by mait-all                        //
//                               Updated: 2025/11/07 10:39 by mait-all                        //
// ****************************************************************************************** //

#include "Cat.hpp"

// Default constructor
Cat::Cat() {
	this->type = "Cat";
	this->_brain = new Brain();
	std::cout << "Cat: Default constructor called" << std::endl;
}

// Copy constructor
Cat::Cat(const Cat& other) : Animal(other) {
	this->_brain = new Brain(*other._brain);
	std::cout << "Cat: Copy constructor called" << std::endl;
}

// Copy assignment operator
Cat&	Cat::operator=(const Cat& other) {
	if (this == &other)
		return (*this);

	Animal::operator=(other);
	*this->_brain = *other._brain;
	std::cout << "Cat: Copy assignment operator called" << std::endl;
	return (*this);
}

// Destructor
Cat::~Cat() {
	delete this->_brain;
	std::cout << "Cat: Destructor called" << std::endl;
}


// --- Member functions ---
void	Cat::makeSound(void) const {
	std::cout << "!! meow meow !!" << std::endl;
}

Brain*	Cat::getBrain() const {
	return (_brain);
}