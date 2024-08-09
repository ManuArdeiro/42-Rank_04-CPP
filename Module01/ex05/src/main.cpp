/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:24:00 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/09 19:14:09 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

static void print_menu(void)
{
    std::cout << "What message do you want to display?" << std::endl;
	std::cout << "1 -> debug" << std::endl;
	std::cout << "2 -> info" << std::endl;
	std::cout << "3 -> warning" << std::endl;
	std::cout << "4 -> erro" << std::endl;
	std::cout << "If you want to exit please press ENTER." << std::endl;
}

static std::string get_option(void)
{
    std::string option;
	std::string levels[] = {"debug", "info", "warning", "error"};

    while (1)
    {
        std::cout << "Harl> ";
        getline(std::cin, option);
        if (std::cin.eof() == true)
        {
            std::cin.clear();
            clearerr(stdin);
        }
		if (option != "1" && option != "2" && option != "3" && option != "4"
			&& option != "")
		{
			std::cerr << "No valid option. Please press 1, 2, 3, 4";
			std::cerr << " or ENTER!!" << std::endl;
		}
		if (option == "")
			return NULL;
    }
    return levels[std::stoi(option)];
}

int	main(void)
{
    std::string message;

	while (1)
	{
		print_menu();
		message = get_option();
		if (message == "debug")
			Harl::debug();
		else if (message == "info")
			Harl::info();
		else if (message == "warning")
			Harl::warning();
		else if (message == "error")
			Harl::error();
		else if (message == NULL)
		{
			std::cout << "No more complains...!!" << std::endl;
			return (EXIT_SUCCESS);
		}
	}
}