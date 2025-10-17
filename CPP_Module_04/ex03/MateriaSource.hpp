// ****************************************************************************************** //
//                               file: MateriaSource.hpp                                      //
//                               by: mait-all <mait-all@student.1337.ma>                      //
//                                                                                            //
//                               Created: 2025/10/17 10:57 by mait-all                        //
//                               Updated: 2025/10/17 11:06 by mait-all                        //
// ****************************************************************************************** //

#pragma once

#include "IMateriaSource.hpp"


// ************************************************************************** //
//                              MateriaSource Class                           //
// ************************************************************************** //

class MateriaSource : public IMateriaSource {
    
    public:
        // ocf
        MateriaSource();
        MateriaSource(const MateriaSource& other);
        MateriaSource&  operator=(const MateriaSource& other);
        ~MateriaSource();

        // member functions
        void        learnMateria(AMateria* m);
        AMateria*   createMateria(std::string const & type);

    private:
        AMateria*   _materias[4];

};