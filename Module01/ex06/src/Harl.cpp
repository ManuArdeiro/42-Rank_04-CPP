/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:23:21 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/09 21:16:14 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "DEBUG: This is a debug message." << std::endl;
}

void Harl::info(void)
{
    std::cout << "INFO: This is an info message." << std::endl;;
}

void Harl::warning(void)
{
    std::cout << "WARNING: This is a warning message." << std::endl;
}

void Harl::error(void)
{
    std::cout << "ERROR: This is an error message." << std::endl;
}

void Harl::complain(std::string level)
{
    void (Harl::*functions[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[] = {"debug", "info", "warning", "error"};
	bool		printed_message = false;
	
	for (int i = 0; i < 4; i++)
	{
        if (levels[i] == level)
		{
			for (int j = i; j < 4; j++)
            	(this->*functions[j])();
			printed_message = true;
            break;
        }
    }
	if (printed_message == false)
		std::cout << "Argument is not a valid comment!!" << std::endl;
	return ;
}