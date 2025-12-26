// ****************************************************************************** //
//                        file: PmergeMe.hpp                                      //
//                        by: mait-all <mait-all@student.1337.ma>                 //
//                                                                                //
//                        Created: 2025/12/15 14:25 by mait-all                   //
//                        Updated: 2025/12/26 14:53 by mait-all                   //
// ****************************************************************************** //

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <vector>
# include <deque>
# include <algorithm>
# include <limits>
# include <cstdlib>
# include <cstring>


class Int {

	public:
		static int	compCount;

		// ocf
		Int(int val = 0);
		Int(const Int& other);
		Int(const std::string& s);
		~Int();
		
		// operators
		Int&	operator=(const Int& other);
		bool	operator<(const Int& other);

		// member functions
		void	saveIndex(int idx);
		int		getIndex();
		int		getValue();

	private:
		unsigned char	_c;
		int				_value;
		int				_idxs[35];

};

// templates declarations
template <typename T>
void	mergeInsert(T& nums);

template <typename T>
void	makePairs(T& nums, T& a, T& b);

template <typename T>
void	restoreB(T& a, T& b, T& restoredB);

template <typename T>
void	isSorted(T _Seq);

// external helper functions
void	processInput(int ac, char **av);
bool	isValidArg(std::string arg);
size_t	t_sequence(size_t k);


# include "PmergeMe.tpp"

#endif /* __PMERGEME_HPP__ */