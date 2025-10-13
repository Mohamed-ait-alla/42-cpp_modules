// ****************************************************************************************** //
//                               file: AMateria.hpp                                           //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/13 19:57 by mait-all                        //
//                               Updated: 2025/10/13 20:09 by mait-all                        //
// ****************************************************************************************** //

#pragma once

#include <iostream>


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
        ~AMateria();

        // member functions
        virtual AMateria*   clone() const = 0;
        virtual void        use(Icharacter& target);
        std::string const & getType() const;

    protected:
        std::string type;

};