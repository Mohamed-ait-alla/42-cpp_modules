// ****************************************************************************************** //
//                               file: Character.hpp                                          //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/15 10:38 by mait-all                        //
//                               Updated: 2025/10/15 21:15 by mait-all                        //
// ****************************************************************************************** //

#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"


// ************************************************************************** //
//                                Character Class                             //
// ************************************************************************** //

class Character : public ICharacter {

    public:
        // ocf
        Character();
        Character(std::string name);
        Character(const Character& other);
        Character&  operator=(const Character& other);
        ~Character();

        // member functions
        std::string const & getName() const;
        void                equipe(AMateria* m);
        void                unequipe(int idx);
        void                use(int idx, ICharacter& target);

    private:
        std::string     _name;
        AMateria*       _inventory[4];
        AMateria*       _inventoryCopy[4];
};