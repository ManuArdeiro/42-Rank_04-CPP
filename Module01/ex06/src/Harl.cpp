/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:23:21 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/16 02:18:33 by jolopez-         ###   ########.fr       */
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

/*	void (Harl::*functions[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	This line declares an array of pointers to member functions of the Harl
	class. The array is named functions, and each element in the array is a
	pointer to a member function of Harl that takes no arguments and returns
	void. The array is initialized with pointers to the debug, info, warning,
	and error member functions of the Harl class.	*/
void Harl::complain(std::string level)
{
    void (Harl::*functions[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[] = {"debug", "info", "warning", "error"};
	bool		printed_messages = false;
	
	for (int i = 0; i < 4; i++)
	{
        if (levels[i] == level)
		{
			for (int j = i; j < 4; j++)
			{
				switch (j)
				{
					case    0: 
						this->debug();
						continue;
					case    1: 
						(this->*functions[j])();
						continue;
					case    2: 
						(this->*functions[j])();
						continue;
					case    3: 
						(this->*functions[j])();
						break ;
					default:
						continue;
				}
			}
			printed_messages = true;
        }
		
    }
	if (printed_messages == false)
	{
		std::cout << "Argument is not a valid comment!! ";
		std::cout << "Type one of these options:" << std::endl;
		std::cout << "./harlFilter debug" << std::endl;
		std::cout << "./harlFilter info" << std::endl;
		std::cout << "./harlFilter warning" << std::endl;
		std::cout << "./harlFilter error" << std::endl;
	}
	return ;
}

Harl::Harl()
{
}

Harl::~Harl()
{
}