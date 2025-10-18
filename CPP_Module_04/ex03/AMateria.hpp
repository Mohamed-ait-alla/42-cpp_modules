// ****************************************************************************************** //
//                               file: AMateria.hpp                                           //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/13 19:57 by mait-all                        //
//                               Updated: 2025/10/18 10:51 by mait-all                        //
// ****************************************************************************************** //

#pragma once

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

// ************************************************************************** //
//                                AMateria Class                              //
// ************************************************************************** //

class AMateria {

    public:
        // ocf
        AMateria();
        AMateria(std::string const & type);
        AMateria(const AMateria& other);
        AMateria&   operator=(const AMateria& other);
        virtual ~AMateria();

        // member functions
        virtual AMateria*   clone() const = 0;
        virtual void        use(ICharacter& target);
        std::string const & getType() const;

    protected:
        std::string type;

};