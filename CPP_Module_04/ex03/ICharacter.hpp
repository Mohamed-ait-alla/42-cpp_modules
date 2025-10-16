// ****************************************************************************************** //
//                               file: ICharacter.hpp                                         //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/14 19:42 by mait-all                        //
//                               Updated: 2025/10/16 21:40 by mait-all                        //
// ****************************************************************************************** //

#pragma once

#include "AMateria.hpp"


// ************************************************************************** //
//                              ICharacter Interface                          //
// ************************************************************************** //

class ICharacter {
    
    public:
        // destructor
        virtual ~ICharacter() {};

        // member functions
        virtual std::string const & getName() const = 0;
        virtual void                equipe(AMateria* m) = 0;
        virtual void                unequipe(int idx) = 0;
        virtual void                use(int idx, ICharacter& other) = 0;

};