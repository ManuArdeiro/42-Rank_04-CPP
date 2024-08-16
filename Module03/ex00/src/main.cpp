/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:03:33 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/16 02:32:26 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	std::cout << "\033[34m" << "\nDefault Constructor ClapTrap Tom: ClapTrap Tom\n" << "\033[0m" << std::endl;
	ClapTrap Tom;
	std::cout << "\033[34m" << "\nConstructor ClapTrap Jon: ClapTrap Jon(\"Jon\")\n" << "\033[0m" << std::endl;
	ClapTrap Jon("Jon");
	std::cout << "\033[34m" << "\nConstructor ClapTrap Jon: ClapTrap Jon(\"Jan\", 5, 5, 2)\n" << "\033[0m" << std::endl;
	ClapTrap Jan("Jan", 5, 5, 2);
	std::cout << "\033[34m" << "\nCopy Constructor ClapTrap from Jon: ClapTrap Jin(Jon)\n" << "\033[0m" << std::endl;
	ClapTrap Jin(Jon);
	std::cout << "\033[34m" << "\nCopy Assignment Operator ClapTrap Jin from Tom: ClapTrap Tim = Jin\n" << "\033[0m" << std::endl;
	ClapTrap Tim = Jin;
	std::cout << "\033[34m" << "\nCopy Assignment Operator ClapTrap Sam from Tom: ClapTrap Sam = Jan\n" << "\033[0m" << std::endl;
	ClapTrap Sam = Jan;

	std::cout << std::endl;
	std::cout << "\033[33m" << "METHODS:" << "\033[0m" << std::endl;
	std::cout << "\033[34m" << "\nJin attacks a non-existing ClapTrap:\n" << "\033[0m" << std::endl;
	Jin.attack("some other robot");
	std::cout << "\033[34m" << "\nJon attacks Jon:\n" << "\033[0m" << std::endl;
	Jon.attack("Jon");
	std::cout << "\033[34m" << "\nTim takes 2 points of damage:\n" << "\033[0m" << std::endl;
	Tim.takeDamage(2);
	std::cout << "\033[34m" << "\nJon repaires 4 points:\n" << "\033[0m" << std::endl;
	Jon.beRepaired(4);
	std::cout << "\033[34m" << "\nJin attacks Tim 11 times:\n" << "\033[0m" << std::endl;
	for (int i = 0; i < 11; i++)
		Jin.attack("Tim");
	std::cout << "\033[34m" << "\nEnd of program:\n" << "\033[0m" << std::endl;
	return (0);

}