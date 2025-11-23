// ****************************************************************************** //
//                        file: iter.hpp                                          //
//                        by: mait-all <mait-all@student.1337.ma>                 //
//                                                                                //
//                        Created: 2025/11/23 09:02 by mait-all                   //
//                        Updated: 2025/11/23 19:50 by mait-all                   //
// ****************************************************************************** //

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>


// === iter<T, Func>() ======================================================== //
// calling the function (func) on each element of the passed array
// ============================================================================ //
template <typename T, typename Func>
void	iter(T* arr, const size_t len, Func func)
{
	for (size_t i = 0; i < len; i++)
	{
		func(arr[i]);
	}
}


#endif /* __ITER_HPP__ */