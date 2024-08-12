/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:24:00 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/09 21:10:59 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
    std::string message;
    Harl harl;

	if (argc != 2)
	{
		std::cerr << "Invalid number of arguments!!" << std::endl;
		return (EXIT_FAILURE);
	}
	message = argv[1];
	harl.complain(message);
	return (EXIT_SUCCESS);
}