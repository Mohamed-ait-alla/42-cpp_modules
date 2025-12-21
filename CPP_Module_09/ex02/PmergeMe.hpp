// ****************************************************************************** //
//                        file: PmergeMe.hpp                                      //
//                        by: mait-all <mait-all@student.1337.ma>                 //
//                                                                                //
//                        Created: 2025/12/15 14:25 by mait-all                   //
//                        Updated: 2025/12/21 17:44 by mait-all                   //
// ****************************************************************************** //

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <limits>
# include <cstdlib>
# include <cstring>


class Int {

	public:
		static int Count;

		// ocf
		Int(int val = 0);
		Int(const Int& other);
		Int(const std::string& s);
		~Int();
		Int&	operator=(const Int& other);

		// overloaded operators
		bool	operator<(const Int& other);
		bool	operator>(const Int& other);
		bool	operator==(const Int& other);
		bool	operator!=(const Int& other);

		// member functions
		void	saveIndex(int idx);
		int		getIndex();
		int		getValue();
	
	private:
		unsigned char	_c;
		int				_value;
		int				_idxs[35];

};

// external helper functions
void	processInput(int ac, char **av);
bool	isValidArg(std::string arg);

#endif /* __PMERGEME_HPP__ */