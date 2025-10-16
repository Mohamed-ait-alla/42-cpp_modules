// ****************************************************************************************** //
//                               file: IMateriaSouce.hpp                                      //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/16 21:21 by mait-all                        //
//                               Updated: 2025/10/16 21:56 by mait-all                        //
// ****************************************************************************************** //

#pragma once

#include "AMateria.hpp"


// ************************************************************************** //
//                          IMateriaSource Interface                          //
// ************************************************************************** //

class IMateriaSource {

    public:
        // destructor
        virtual ~IMateriaSource() {};

        // member functions
        virtual void        learnMateria(AMateria*) = 0;
        virtual AMateria*   createMateria(std::string const & type) = 0;

};