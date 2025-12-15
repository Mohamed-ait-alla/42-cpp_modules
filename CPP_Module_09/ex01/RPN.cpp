// ****************************************************************************** //
//                        file: RPN.cpp                                           //
//                        by: mait-all <mait-all@student.1337.ma>                 //
//                                                                                //
//                        Created: 2025/12/13 20:47 by mait-all                   //
//                        Updated: 2025/12/15 10:05 by mait-all                   //
// ****************************************************************************** //

#include "RPN.hpp"


/**
 * Validates the expression for white spaces.
 * returns true if expression has only spaces, false if not.
 * 
 * @param expr The entred RPN expression.
*/
bool	hasOnlySpaces(std::string expr)
{
	for (size_t i = 0; i < expr.length(); i++)
	{
		if (!std::isspace(expr[i]))
			return (false);
	}
	return (true);
}

/**
 * Applies an operation on the top two elements of the stack (s).
 * The applied operation depends on the type of token.
 * Pushes the operation's result back into the stack.
 * 
 * @param s The stack container that's stored operands (elements).
 * @param token Type of operation (+,-,*,/).
*/
void	calcRPNExpr(std::stack<int>& s, char token)
{
	int	firstOperand = 0;
	int	secondOperand = 0;
	int	result = 0;

	if (s.size() <= 1)
		throw std::runtime_error("Error: invalid RPN syntax!");
	secondOperand = s.top();
	s.pop();
	firstOperand = s.top();
	s.pop();
	if (token == '+')
		result = firstOperand + secondOperand;
	else if (token == '-')
		result = firstOperand - secondOperand;
	else if (token == '*')
		result = firstOperand * secondOperand;
	else
		result = firstOperand / secondOperand;
	s.push(result);
}

/**
 * Starts the workflow of the RPN program.
 * Parses user input and checks for proper errors.
 * Calls calcRPNExpr() when an expression is valid.
 * If any none error is found, it displays the result on stdout.
 * 
 * @param expression The entred RPN expression.
*/
void	evaluateRPN(std::string expression)
{
	std::string	validTokens = "+-/*";
	std::stack<int>	s;

	if (expression.empty() || hasOnlySpaces(expression))
		throw std::runtime_error("Error: empty expression!");

	for (size_t i = 0; i < expression.length(); i++)
	{
		if (expression[i] == ' ')
			continue;
		if ((!isdigit(expression[i]) && (validTokens.find(expression[i]) == std::string::npos)))
			throw std::runtime_error("Error: not allowed character!");
		if (isdigit(expression[i]))
		{
			if (isdigit(expression[i + 1]))
				throw std::runtime_error("Error: digit should be between 0 and 9");
			s.push(expression[i] - '0');
		}
		if (validTokens.find(expression[i]) != std::string::npos)
			calcRPNExpr(s, expression[i]);
	}
	if (s.size() > 1)
		throw std::runtime_error("Error: invalid RPN syntax!");
	std::cout << s.top() << std::endl;
}
