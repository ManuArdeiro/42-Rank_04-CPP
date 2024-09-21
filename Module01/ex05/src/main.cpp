/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:24:00 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/11 20:11:21 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

static void print_menu(void)
{
	std::cout << std::endl;
    std::cout << "What message do you want to display?" << std::endl;
	std::cout << "1 -> debug" << std::endl;
	std::cout << "2 -> info" << std::endl;
	std::cout << "3 -> warning" << std::endl;
	std::cout << "4 -> error" << std::endl;
	std::cout << "If you want to exit please press ENTER." << std::endl;
}

static std::string get_option(void)
{
    std::string option;
	std::string levels[] = {"debug", "info", "warning", "error"};

	std::cout << "Harl> ";
	getline(std::cin, option);
	std::cout << std::endl;
	if (std::cin.eof() == true)
	{
		std::cin.clear();
		std::clearerr(stdin);
	}
	if (option != "1" && option != "2" && option != "3" && option != "4"
		&& option != "")
	{
		std::cerr << "No valid option. I won't play more with you :( ";
		exit(0);
	}
	if (option == "")
		return ("");
    return levels[atoi(option.c_str()) - 1];
}

int	main(void)
{
    std::string message;
    Harl harl;

	while (1)
	{
		print_menu();
		message = get_option();
		if (message == "")
		{
			std::cout << "No more complains from you...!!\n" << std::endl;
			return (EXIT_SUCCESS);
		}
		else
			harl.complain(message);
	}
	return (EXIT_SUCCESS);
}