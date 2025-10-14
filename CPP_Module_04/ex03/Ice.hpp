// ****************************************************************************************** //
//                               file: Ice.hpp                                                //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/14 17:39 by mait-all                        //
//                               Updated: 2025/10/14 17:53 by mait-all                        //
// ****************************************************************************************** //

#pragma once

#include "AMateria.hpp"


// ************************************************************************** //
//                                Ice Class                                   //
// ************************************************************************** //

class Ice : public AMateria {

    public:
        // ocf
        Ice();
        Ice(const Ice& other);
        Ice& operator=(const Ice& other);
        ~Ice();

        // member functions
        AMateria*   clone(void) const;
        void        use(ICharacter& target);

};