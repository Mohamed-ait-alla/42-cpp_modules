// ****************************************************************************************** //
//                               file: WrongCat.hpp                                           //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/11 13:53 by mait-all                        //
//                               Updated: 2025/10/11 13:59 by mait-all                        //
// ****************************************************************************************** //

#pragma once

#include "WrongAnimal.hpp"



// ************************************************************************** //
//                                 WrongCat Class                             //
// ************************************************************************** //

class WrongCat : public WrongAnimal {

    public:
        // ocf
        WrongCat();
        WrongCat(const WrongCat& other);
        WrongCat&   operator=(const WrongCat& other);
        ~WrongCat();

        // member functions
        void    makeSound(void) const; 

};