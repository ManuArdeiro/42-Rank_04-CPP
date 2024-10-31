/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:03:33 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/17 21:06:24 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	std::cout << std::endl;
	std::cout << "\033[31m" << "SCAVTRAP:" << "\033[0m" << std::endl;
	std::cout << "\033[33m" << "\nDefault Constructor ScavTrap TomST -> ScavTrap TomST\n" << "\033[0m" << std::endl;
	ScavTrap TomST;
	std::cout << "\033[33m" << "\nConstructor ScavTrap with name SamST -> ScavTrap SamST(\"SamST\")\n" << "\033[0m" << std::endl;
	ScavTrap SamST("SamST");
	std::cout << "\033[33m" << "\nCopy Constructor ScavTrap from SamST -> ScavTrap JinST(SamST)\n" << "\033[0m" << std::endl;
	ScavTrap JinST(SamST);
	std::cout << "\033[33m" << "\nCopy Assignment Operator ScavTrap TimCT from JinCT -> ScavTrap TimST = JinST\n" << "\033[0m" << std::endl;
	ScavTrap TimST = JinST;
	std::cout << std::endl;
	
	std::cout << "\033[33m" << "METHODS:" << "\033[0m" << std::endl;
	std::cout << "\033[33m" << "\nSamST attacks JinST: SamST.attack(JinST)\n" << "\033[0m" << std::endl;
	SamST.attack(JinST);
	std::cout << "\033[33m" << "\nSamST repaires 3 points: SamST.beRepaired(3)\n" << "\033[0m" << std::endl;
	SamST.beRepaired(3);
	std::cout << "\033[33m" << "\nSamST takes 104 points of damage: SamST.takeDamage(104)\n" << "\033[0m" << std::endl;
	SamST.takeDamage(104);
	std::cout << "\033[33m" << "\nSamST attacks TomST: SamST.attack(TomST)\n" << "\033[0m" << std::endl;
	SamST.attack(TomST);
	std::cout << "\033[33m" << "\nJinST attacks TimST 52 Times: 52 x JinST.attack(TimST)\n" << "\033[0m" << std::endl;
	for (int i = 0; i < 52; i++)
		JinST.attack(TimST);
	std::cout << "\033[33m" << "\nCopy Constructor ScavTrap from SamST -> ScavTrap Iria(SamST)\n" << "\033[0m" << std::endl;
	ScavTrap IriaST(SamST);
	std::cout << std::endl;
	
	std::cout << "\033[31m" << "GUARD GATE:" << "\033[0m" << std::endl;
	std::cout << "\033[33m" << "\nIriaST uses the special feature GuardGate -> IriaST.guardGate()\n" << "\033[0m" << std::endl;
	IriaST.guardGate();
	std::cout << "\033[33m" << "\nIriaST uses the special feature GuardGate again -> IriaST.guardGate()\n" << "\033[0m" << std::endl;
	IriaST.guardGate();
	
	std::cout << "\033[33m" << "\n\n\nEnd of program:\n" << "\033[0m" << std::endl;
	return (0);
}