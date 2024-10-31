/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:26:11 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/29 10:04:38 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>
#include <string>
#include <stdexcept>

class RPN
{
	public:
		// Constructors
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		// Methods
		int 	evaluate(const std::string &expression);

	private:
		double	result;
		
		// Methods
		int 	applyOperation(char op, int a, int b);
};
