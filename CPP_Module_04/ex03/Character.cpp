// ****************************************************************************************** //
//                               file: Character.cpp                                          //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/15 10:38 by mait-all                        //
//                               Updated: 2025/11/08 16:04 by mait-all                        //
// ****************************************************************************************** //

#include "Character.hpp"

// Default constructor
Character::Character() {
    this->_name = "unknown";
    for(int i = 0; i < 4; i++) {
        this->_inventory[i] = NULL;
        this->_inventoryCopy[i] = NULL;
    }
    std::cout << "Character: Default constructor called" << std::endl;
}

// Parametrised constructor
Character::Character(std::string name) {
    this->_name = name;
    for(int i = 0; i < 4; i++) {
        this->_inventory[i] = NULL;
        this->_inventoryCopy[i] = NULL;
    }
    std::cout << "Character: Parametrised constructor called" << std::endl;
}

// Copy constructor
Character::Character(const Character& other) {
    this->_name = other._name;
    for(int i = 0; i < 4; i++) {
        if (other._inventory[i])
            this->_inventory[i] = other._inventory[i]->clone();
        else
            this->_inventory[i] = NULL;
    }
    std::cout << "Character: Copy constructor called" << std::endl;
}

// Copy assignment operator
Character&  Character::operator=(const Character& other) {
    if (this != &other) {
        this->_name = other._name;
        for (int i = 0; i < 4; i++) {
			if (this->_inventory[i])
           		delete this->_inventory[i];
            if (other._inventory[i])
                this->_inventory[i] = other._inventory[i]->clone();
            else
                this->_inventory[i] = NULL;
        }
    }
    std::cout << "Character: Copy assignment operator called" << std::endl;
    return (*this);
}

// Destructor
Character::~Character() {
    for (int i = 0; i < 4; i++) {
        if (_inventory[i])
            delete _inventory[i];
        if (_inventoryCopy[i])
            delete _inventoryCopy[i];
    }
    std::cout << "Character: Destructor called" << std::endl;
}


// --- Member functions ---
std::string const & Character::getName() const {
    return (_name);
}

void    Character::equipe(AMateria* m) {
    if (!m)
        return ;
    for (int i = 0; i < 4; i++)
    {
		if (_inventory[i] == m)
			return ;
        if (this->_inventory[i] == NULL)
        {
            this->_inventory[i] = m;
            return ;
        }
    }
}

void    Character::unequipe(int idx) {
    if (idx < 0 || idx >= 4 || !_inventory[idx])
        return ;
    _inventoryCopy[idx] = _inventory[idx];
    _inventory[idx] = NULL;
}

void    Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && _inventory[idx])
        _inventory[idx]->use(target);
}