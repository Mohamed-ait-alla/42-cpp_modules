// ****************************************************************************************** //
//                               file: Cure.hpp                                               //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/14 17:39 by mait-all                        //
//                               Updated: 2025/10/14 18:47 by mait-all                        //
// ****************************************************************************************** //

#pragma once

#include "AMateria.hpp"


// ************************************************************************** //
//                                Cure Class                                  //
// ************************************************************************** //

class Cure : public AMateria {

    public:
        // ocf
        Cure();
        Cure(const Cure& other);
        Cure&   operator=(const Cure& other);
        ~Cure();

        // member functions
        AMateria*   clone(void) const;
        void        use(ICharacter& target);

};