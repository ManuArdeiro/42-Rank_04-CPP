/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:28:10 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/29 10:06:24 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <iostream>
#include <cctype>

// Constructors
RPN::RPN()
{
    std::cout << "RPN default constructor called." << std::endl;
}

RPN::RPN(const RPN &other)
{
    std::cout << "RPN copy constructor called." << std::endl;
	(void)other;
}

RPN &RPN::operator=(const RPN &other)
{
    std::cout << "RPN assignment operator called." << std::endl;
    // Nothing to copy
	(void)other;
    return *this;
}

RPN::~RPN()
{
    std::cout << "RPN destructor called." << std::endl;
}

// Applies the operation depending on the operator
int RPN::applyOperation(char op, int a, int b)
{
    switch (op)
	{
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) throw std::runtime_error("Error: Division by zero");
            return a / b;
        default:
            throw std::runtime_error("Error: Unknown operator");
    }
}

// Evaluates the expression in Reverse Polish Notation
int RPN::evaluate(const std::string &expression)
{
    std::stack<int>		stack;
    std::istringstream	iss(expression);	// Creates an input string stream (istringstream)
											// from the expression, allowing it to be read token 
											// by token as if it were a stream of input.
    std::string 		token;

    while (iss >> token)
	{
        if (isdigit(token[0]))
		{
            stack.push(token[0] - '0');  // Convierte char a int
        }
		else if (token.size() == 1 && std::string("+-*/").find(token[0]) != std::string::npos)
		{
            if (stack.size() < 2) throw std::runtime_error("Error: Invalid expression");
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            int result = applyOperation(token[0], a, b);
            stack.push(result);
        }
		else
		{
            throw std::runtime_error("Error: Invalid token in expression");
        }
    }
    if (stack.size() != 1)
	{
		throw std::runtime_error("Error: Invalid expression");
	}

    return stack.top();
}
