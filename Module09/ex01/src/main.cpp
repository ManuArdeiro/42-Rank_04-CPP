/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:35:24 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/28 20:36:21 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int argc, char** argv)
{
    RPN calculator;

    if (argc != 2)
	{
        std::cerr << "Usage: ./RPN <expression>" << std::endl;
        return 1;
    }
    try 
	{
        int result = calculator.evaluate(argv[1]);
        std::cout << result << std::endl;
    }
	catch (const std::exception &e) 
{
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
