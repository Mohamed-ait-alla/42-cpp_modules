// ****************************************************************************************** //
//                               file: Brain.hpp                                              //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/12 19:40 by mait-all                        //
//                               Updated: 2025/10/12 19:40 by mait-all                        //
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

        // member functions
        std::string getIdea(int index) const;
        void        setIdea(int index, std::string idea);

    private:
        std::string ideas[100];

};