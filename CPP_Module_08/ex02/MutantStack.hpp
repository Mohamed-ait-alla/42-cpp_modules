// ****************************************************************************** //
//                        file: MutantStack.hpp                                   //
//                        by: mait-all <mait-all@student.1337.ma>                 //
//                                                                                //
//                        Created: 2025/11/29 12:00 by mait-all                   //
//                        Updated: 2025/11/30 09:09 by mait-all                   //
// ****************************************************************************** //

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <iterator>

// ****************************************************************************** //
//                            MutantStack Class Template                          //
// ****************************************************************************** //

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {

	public:
		typedef typename Container::iterator	iterator;

		iterator	begin()
		{
			return (this->c.begin());
		}

		iterator	end()
		{
			return (this->c.end());
		}

};


#endif /* __MUTANTSTACK_HPP__ */