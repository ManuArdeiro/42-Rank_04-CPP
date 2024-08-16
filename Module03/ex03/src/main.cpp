/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:03:33 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/15 01:49:43 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

static void	function_tests(void)
{
	std::cout << "\033[31m" << "\nDIAMONDTRAP TEST FUNCTION:" << "\033[0m" << std::endl;
	DiamondTrap* AllocatedDiamondTrap = new DiamondTrap("AllocatedDiamondTrap");
	std::cout << std::endl;
	delete AllocatedDiamondTrap;
	
	std::cout << "\033[32m" << "\nConstructor DiamondTrap with name RoiDT -> DiamondTrap RoiDT(\"RoiDT\")\n" << "\033[0m" << std::endl;
	DiamondTrap RoiDT("RoiDT");
	std::cout << "\033[32m" << "\nEnd of function:\n" << "\033[0m" << std::endl;
	
	return ;
}

int	main(void)
{
	function_tests();

	std::cout << std::endl;
	std::cout << "\033[31m" << "DIAMONDTRAP:" << "\033[0m" << std::endl;
	std::cout << "\033[35m" << "\nDefault Constructor DiamondTrap IriaDT -> DiamondTrap IriaDT\n" << "\033[0m" << std::endl;
	DiamondTrap IriaDT;
	std::cout << "\033[35m" << "\nConstructor DiamondTrap with name RoiDT -> DiamondTrap RoiDT(\"RoiDT\")\n" << "\033[0m" << std::endl;
	DiamondTrap RoiDT("RoiDT");
	std::cout << "\033[32m" << "\nConstructor DiamondTrap with name IreneDT and parameters -> DiamondTrap IreneDT(\"IreneDT\", 100, 100, 30)\n" << "\033[0m" << std::endl;
	DiamondTrap IreneDT("IreneDT", 100, 100, 30);
	std::cout << "\033[32m" << "\nConstructor DiamondTrap with name LuisDT and parameters -> DiamondTrap LuisDT(\"LuisDT\", 10, 8, 6)\n" << "\033[0m" << std::endl;
	DiamondTrap LuisDT("LuisDT", 10, 8, 6);
	std::cout << "\033[35m" << "\nCopy Constructor DiamondTrap from LuisDT -> DiamondTrap LuisCopyDT(LuisDT)\n" << "\033[0m" << std::endl;
	DiamondTrap LuisCopyDT(LuisDT);
	std::cout << "\033[35m" << "\nCopy Assignment Operator DiamondTrap JeanDT from RoiDT -> DiamondTrap JeanDT = RoiDT\n" << "\033[0m" << std::endl;
	DiamondTrap JeanDT = RoiDT;
	std::cout << std::endl;
	std::cout << "\033[33m" << "METHODS:" << "\033[0m" << std::endl;
	std::cout << "\033[35m" << "\nRoiDT attacks a non-existing ClapTrap: RoiDT.attack(\"some other robot\")\n" << "\033[0m" << std::endl;
	RoiDT.attack("some other robot");
	std::cout << "\033[35m" << "\nRoiDT takes 20 points of damage: RoiDT.takeDamage(20)\n" << "\033[0m" << std::endl;
	RoiDT.takeDamage(20);
	std::cout << "\033[35m" << "\nRoiDT repaires 40 points: RoiDT.beRepaired(40)\n" << "\033[0m" << std::endl;
	RoiDT.beRepaired(40);
	std::cout << "\033[35m" << "\nLuisDT attacks RoiDT 10 TimCTes: 10 x LuisDT.attack(\"RoiDT\")\n" << "\033[0m" << std::endl;
	for (int i = 0; i < 10; i++)
		LuisDT.attack("RoiDT");
	std::cout << "\033[35m" << "\nLuisCopyDT takes 10 points of damage: LuisCopyDT.takeDamage(20)\n" << "\033[0m" << std::endl;
	LuisCopyDT.takeDamage(20);
	std::cout << "\033[35m" << "\nLuisCopyDT attacks RoiDT: LuisCopyDT.attack(\"RoiDT\")\n" << "\033[0m" << std::endl;
	LuisCopyDT.attack("RoiDT");
	std::cout << "\033[35m" << "\nIriaDT uses her special function: IriaDT.whoAmI()\n" << "\033[0m" << std::endl;
	RoiDT.whoAmI();

	std::cout << "\033[32m" << "\nEnd of program:\n" << "\033[0m" << std::endl;
	return (0);
}