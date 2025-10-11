// ****************************************************************************************** //
//                               file: Brain.hpp                                              //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/11 20:15 by mait-all                        //
//                               Updated: 2025/10/11 20:22 by mait-all                        //
// ****************************************************************************************** //

#pragma once

#include <iostream>


// ************************************************************************** //
//                                  Brain Class                               //
// ************************************************************************** //

class Brain {

    public:
        // ocf
        Brain();
        Brain(const Brain& other);
        Brain&  operator=(const Brain& other);
        ~Brain();

    private:
        std::string ideas[100];

};