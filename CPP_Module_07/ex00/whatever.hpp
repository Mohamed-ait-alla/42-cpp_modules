// ****************************************************************************** //
//                        file: whatever.hpp                                      //
//                        by: mait-all <mait-all@student.1337.ma>                 //
//                                                                                //
//                        Created: 2025/11/22 17:51 by mait-all                   //
//                        Updated: 2025/11/22 20:41 by mait-all                   //
// ****************************************************************************** //

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>


// === swap<T>() ============================================================== //
// Swaps the values of two variables of type T.
// ============================================================================ //
template <typename T>
void	swap(T& a, T& b)
{
	T	tmp = a;
	a = b;
	b = tmp;
}

// === min<T>() =============================================================== //
// Returns the smaller of two values of type T.
// ============================================================================ //
template <typename T>
T		min(T a, T b)
{
	return (a < b ? a : b);
}

// === max<T>() =============================================================== //
// Returns the larger of two values of type T.
// ============================================================================ //
template <typename T>
T		max(T a, T b)
{
	return (a > b ? a : b);
}


#endif /* __WHATEVER_HPP__ */