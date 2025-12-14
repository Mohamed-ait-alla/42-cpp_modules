// ****************************************************************************** //
//                        file: RPN.cpp                                           //
//                        by: mait-all <mait-all@student.1337.ma>                 //
//                                                                                //
//                        Created: 2025/12/13 20:47 by mait-all                   //
//                        Updated: 2025/12/14 18:14 by mait-all                   //
// ****************************************************************************** //

#include "RPN.hpp"


/**
 * todo...
 * 
 * @param expression todo...
*/
void	evaluateRPN(std::string expression)
{
	std::string	validOps = "+-/*";
	std::stack<int>	s;

	if (expression.empty())
		throw std::runtime_error("Error: empty expression!");

	for (size_t i = 0; i < expression.length(); i++)
	{
		if (expression[i] == ' ')
			continue;
		if ((!isdigit(expression[i]) && (validOps.find(expression[i]) == std::string::npos)))
			throw std::runtime_error("Error: not allowed character!");
		if (isdigit(expression[i]))
		{
			if (isdigit(expression[i + 1]))
				throw std::runtime_error("Error: digit should be between 0 and 9");
			s.push(expression[i] - '0');
		}
		if (validOps.find(expression[i]) != std::string::npos)
		{
			if (s.size() <= 1)
				throw std::runtime_error("Error: no enough operands for each operator!");
			int secondOperand = s.top();
			s.pop();
			int firstOperand = s.top();
			s.pop();
			std::cout << "f: " << firstOperand << "s: " << secondOperand << std::endl;
			int result = 0;
			if (expression[i] == '+')
				result = firstOperand + secondOperand;
			else if (expression[i] == '-')
				result = firstOperand - secondOperand;
			else if (expression[i] == '*')
				result = firstOperand * secondOperand;
			else
				result = firstOperand / secondOperand;
			s.push(result);
		}
	}
	if (s.size() > 1)
		throw std::runtime_error("Error: no operation symbol found!");
	std::cout << "result: " << s.top() << std::endl;
}
