// ****************************************************************************** //
//                        file: MutantStack.hpp                                   //
//                        by: mait-all <mait-all@student.1337.ma>                 //
//                                                                                //
//                        Created: 2025/11/29 12:00 by mait-all                   //
//                        Updated: 2025/11/30 09:51 by mait-all                   //
// ****************************************************************************** //

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <iterator>

// ****************************************************************************** //
//                            MutantStack Class Template                          //
// ****************************************************************************** //

template <typename T, typename _Seq = std::deque<T> >
class MutantStack : public std::stack<T, _Seq> {

	public:
		typedef typename _Seq::iterator	iterator;
		typedef typename _Seq::const_iterator	const_iterator;

		/**
		* return the underlying container's `begin()`
		* non-const version
		*/
		iterator	begin()
		{
			return (this->c.begin());
		}

		/**
		* return the underlying container's `end()`
		* non-const version
		*/
		iterator	end()
		{
			return (this->c.end());
		}

		/**
		* return the underlying container's `begin()`
		* const version
		*/
		const_iterator	begin() const
		{
			return (this->c.begin());
		}

		/**
		* return the underlying container's `end()`
		* const version
		*/
		const_iterator	end() const
		{
			return (this->c.end());
		}

};


#endif /* __MUTANTSTACK_HPP__ */