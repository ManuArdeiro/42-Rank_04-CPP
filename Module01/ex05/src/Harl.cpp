/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:23:21 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/09 20:49:28 by jolopez-         ###   ########.fr       */
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
	
	for (int i = 0; i < 4; i++)
	{
        if (levels[i] == level)
		{
            (this->*functions[i])();
            break;
        }
    }
	return ;
}