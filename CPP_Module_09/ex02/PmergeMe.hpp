// ****************************************************************************** //
//                        file: PmergeMe.hpp                                      //
//                        by: mait-all <mait-all@student.1337.ma>                 //
//                                                                                //
//                        Created: 2025/12/15 14:25 by mait-all                   //
//                        Updated: 2025/12/17 10:55 by mait-all                   //
// ****************************************************************************** //

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <limits>
# include <cstdlib>

typedef std::pair<int, int> Pair;

void	processInput(int ac, char **av);
bool	isValidArg(std::string arg);
void	mergeInsertionSort(std::vector<int>& input, int pairLevel);

#endif /* __PMERGEME_HPP__ */