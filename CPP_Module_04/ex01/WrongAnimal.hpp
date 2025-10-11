// ****************************************************************************************** //
//                               file: WrongAnimal.hpp                                        //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/11 20:04 by mait-all                        //
//                               Updated: 2025/10/11 20:04 by mait-all                        //
// ****************************************************************************************** //

#pragma once

#include <iostream>


// ************************************************************************** //
//                              WrongAnimal Class                             //
// ************************************************************************** //

class WrongAnimal {

    public:
        // ocf
        WrongAnimal();
        WrongAnimal(const WrongAnimal& other);
        WrongAnimal&    operator=(const WrongAnimal& other);
        ~WrongAnimal();

        // member functions
        void        makeSound(void) const;
        std::string getType(void) const;

    protected:
        std::string type;

};