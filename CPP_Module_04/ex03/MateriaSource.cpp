// ****************************************************************************************** //
//                               file: MateriaSource.cpp                                      //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/17 10:57 by mait-all                        //
//                               Updated: 2025/10/17 18:29 by mait-all                        //
// ****************************************************************************************** //

#include "MateriaSource.hpp"

// Default constructor
MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++) {
        _materias[i] = NULL;
    }
    std::cout << "MateriaSource: Default constructor called" << std::endl;
}

// Copy constructor
MateriaSource::MateriaSource(const MateriaSource& other) {
    for (int i  = 0; i < 4; i++) {
        if (other._materias[i])
            this->_materias[i] = other._materias[i]->clone();
        else
            this->_materias[i] = NULL;
    }
    std::cout << "MateriaSource: Copy constructor called" << std::endl;
}

// Copy assignment operator
MateriaSource&  MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other)
    {
        for (int i = 0; i < 4; i++) {
            if (other._materias[i])
            {
                if (this->_materias[i]) // if true delete previous memory addrress then assign it the new one
                    delete (this->_materias[i]);
                this->_materias[i] = other._materias[i]->clone();
            }
            else
                this->_materias[i] = NULL;
        }
    }
    std::cout << "MateriaSource: Copy assignment operator called" << std::endl;
    return (*this);
}

// Destructor
MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        if (this->_materias[i])
            delete (this->_materias[i]);
    }
    std::cout << "MateriaSource: Destructor called" << std::endl;
}


// --- Member functions ---
void    MateriaSource::learnMateria(AMateria* m) {
    if (!m)
        return ;
    for (int i = 0; i < 4; i++) {
        if (this->_materias[i] == NULL)
        {
            this->_materias[i] = m;
            return ;
        }
    }
}

AMateria*   MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (this->_materias[i] && (this->_materias[i]->getType() == type))
            return (this->_materias[i]->clone());
    }
    return (NULL);
}