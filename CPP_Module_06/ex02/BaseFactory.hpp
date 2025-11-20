// ****************************************************************************** //
//                        file: BaseFactory.hpp                                   //
//                        by: mait-all <mait-all@student.1337.ma>                 //
//                                                                                //
//                        Created: 2025/11/20 19:59 by mait-all                   //
//                        Updated: 2025/11/20 19:59 by mait-all                   //
// ****************************************************************************** //

#ifndef BASEFACTORY_HPP
# define BASEFACTORY_HPP

# include "A.hpp"
# include "B.hpp"
# include "C.hpp"


Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif /* __BASEFACTORY_HPP__ */