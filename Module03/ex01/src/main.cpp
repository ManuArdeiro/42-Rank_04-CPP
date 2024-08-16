/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:03:33 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/14 21:29:40 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	std::cout << std::endl;
	std::cout << "\033[31m" << "SCAVTRAP:" << "\033[0m" << std::endl;
	std::cout << "\033[32m" << "\nDefault Constructor ScavTrap TomST -> ScavTrap TomST\n" << "\033[0m" << std::endl;
	ScavTrap TomST;
	std::cout << "\033[32m" << "\nConstructor ScavTrap with name SamST -> ScavTrap SamST(\"SamST\")\n" << "\033[0m" << std::endl;
	ScavTrap SamST("SamST");
	std::cout << "\033[32m" << "\nConstructor ScavTrap with name JonST and parameters -> ScavTrap JonST(\"JonST\", 3, 2, 1)\n" << "\033[0m" << std::endl;
	ScavTrap JonST("JonST", 3, 2, 1);
	std::cout << "\033[32m" << "\nCopy Constructor ScavTrap from JonST -> ScavTrap JinST(JonST)\n" << "\033[0m" << std::endl;
	ScavTrap JinST(JonST);
	std::cout << "\033[32m" << "\nCopy Assignment Operator ScavTrap TimCT from JinCT -> ScavTrap TimST = JinST\n" << "\033[0m" << std::endl;
	ScavTrap TimST = JinST;

	std::cout << std::endl;
	std::cout << "\033[33m" << "METHODS:" << "\033[0m" << std::endl;
	std::cout << "\033[32m" << "\nConstructor ScavTrap with name RoiST and only 5 energy points ";
	std::cout << "-> ScavTrap RoiST(\"RoiST\",100, 5, 20)\n\033[0m" << std::endl;
	ScavTrap RoiST("RoiST",100, 5, 20);
	std::cout << "\033[32m" << "\nRoiST attacks RoiST: RoiST.attack(\"JonST\")\n" << "\033[0m" << std::endl;
	RoiST.attack("JonST");
	std::cout << "\033[32m" << "\nRoiST takes 2 points of damage: RoiST.takeDamage(2)\n" << "\033[0m" << std::endl;
	RoiST.takeDamage(2);
	std::cout << "\033[32m" << "\nRoiST repaires 4 points: RoiST.beRepaired(4)\n" << "\033[0m" << std::endl;
	RoiST.beRepaired(4);
	std::cout << "\033[32m" << "\nRoiST attacks TimST 4 TimCTes: 4 x RoiST.attack(\"TimST\")\n" << "\033[0m" << std::endl;
	for (int i = 0; i < 4; i++)
		RoiST.attack("TimST");
	std::cout << "\033[32m" << "\nRoiST repaires 4 points: RoiST.beRepaired(4)\n" << "\033[0m" << std::endl;
	RoiST.beRepaired(4);
	std::cout << "\033[32m" << "\nConstructor ScavTrap with name IriaST and only 5 hit points ";
	std::cout << "-> ScavTrap IriaST(\"IriaST\",5, 50, 20)\n\033[0m" << std::endl;
	ScavTrap IriaST("IriaST",5, 5, 20);
	std::cout << "\033[32m" << "\nIriaST takes 6 points of damage: IriaST.takeDamage(6)\n" << "\033[0m" << std::endl;
	IriaST.takeDamage(6);
	std::cout << "\033[32m" << "\nIriaST attacks RoiST: IriaST.attack(\"RoiST\")\n" << "\033[0m" << std::endl;
	IriaST.attack("RoiST");
	
	std::cout << std::endl;
	std::cout << "\033[33m" << "GUARD GATE:" << "\033[0m" << std::endl;
	std::cout << "\033[32m" << "\nIriaST uses the special feature GuardGate -> IriaST.guardGate()\n" << "\033[0m" << std::endl;
	IriaST.guardGate();
	
	std::cout << "\033[32m" << "\n\n\nEnd of program:\n" << "\033[0m" << std::endl;
	return (0);
}