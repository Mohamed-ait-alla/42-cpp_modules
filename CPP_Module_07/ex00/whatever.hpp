// ****************************************************************************** //
//                        file: whatever.hpp                                      //
//                        by: mait-all <mait-all@student.1337.ma>                 //
//                                                                                //
//                        Created: 2025/11/22 17:51 by mait-all                   //
//                        Updated: 2025/11/22 18:20 by mait-all                   //
// ****************************************************************************** //

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>


template <typename T>
void	swap(T& a, T& b)
{
	T	tmp = a;
	a = b;
	b = tmp;
}

#endif /* __WHATEVER_HPP__ */