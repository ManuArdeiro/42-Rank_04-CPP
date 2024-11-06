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

// Static function: Applies the operation to the operands
static int applyOperation(char op, int a, int b)
{
    switch (op)
    {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0)
                throw std::runtime_error("Error: zero division.");
            return a / b;
        default:
            throw std::runtime_error("Error: not a valid operator.");
    }
}

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

// Evaluates the expression in Reverse Polish Notation
int RPN::evaluate(const std::string& expression)
{
    std::istringstream tokens(expression);
    std::string token;

    while (tokens >> token)
    {
        processToken(token);
    }

    if (stack.size() != 1)
    {
        throw std::runtime_error("Error: Expression is not valid.");
    }

    return stack.top(); // Final result
}

// Processes the token
void RPN::processToken(const std::string& token)
{
    if (isdigit(token[0]))
    {
        std::stringstream ss(token);
        int number;
        ss >> number; // Converts the token to an integer
        if (ss.fail())
        {
            throw std::runtime_error("Error: Token is not a number.");
        }
        stack.push(number); // Pushes the number to the stack
    }
    else if (token.size() == 1 && std::string("+-*/").find(token) != std::string::npos)
    {
        if (stack.size() < 2)
        {
            throw std::runtime_error("Error: not enough operands.");
        }
        int b = stack.top();
        stack.pop();
        int a = stack.top();
        stack.pop();

        stack.push(applyOperation(token[0], a, b));
    }
    else
    {
        throw std::runtime_error("Error: not a valid token.");
    }
}
