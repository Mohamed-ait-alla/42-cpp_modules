// ****************************************************************************** //
//                        file: easyfind.hpp                                      //
//                        by: mait-all <mait-all@student.1337.ma>                 //
//                                                                                //
//                        Created: 2025/11/27 09:29 by mait-all                   //
//                        Updated: 2025/11/27 10:44 by mait-all                   //
// ****************************************************************************** //

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <algorithm>


// === easyfind<T>() ========================================================== //
// finds an element within a container
// ============================================================================ //
template <typename T>
int	easyfind(T& container , int toFind)
{
	typename T::iterator it = std::find(container.begin(), container.end(), toFind);
	if (it != container.end())
		return (*it);
	throw std::runtime_error("Element not found in container");
}


#endif /* __EASYFIND_HPP__ */