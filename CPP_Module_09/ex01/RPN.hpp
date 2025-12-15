// ****************************************************************************** //
//                        file: RPN.hpp                                           //
//                        by: mait-all <mait-all@student.1337.ma>                 //
//                                                                                //
//                        Created: 2025/12/13 20:47 by mait-all                   //
//                        Updated: 2025/12/15 10:18 by mait-all                   //
// ****************************************************************************** //

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>


void	evaluateRPN(std::string expression);
void	calcRPNExpr(std::stack<int>& s, char token);
bool	hasOnlySpaces(std::string expr);


#endif /* __RPN_HPP__ */