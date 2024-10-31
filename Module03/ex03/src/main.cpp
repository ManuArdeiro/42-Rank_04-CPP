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
	std::cout << "\033[35m" << "\nCopy Constructor DiamondTrap from LuisCopyDT -> DiamondTrap LuisCopyDT(RoiDT)\n" << "\033[0m" << std::endl;
	DiamondTrap LuisCopyDT(RoiDT);
	std::cout << "\033[35m" << "\nCopy Assignment Operator DiamondTrap Jean_eq_DT from RoiDT -> DiamondTrap Jean=DT = RoiDT\n" << "\033[0m" << std::endl;
	DiamondTrap Jean_eq_DT = RoiDT;
	std::cout << std::endl;
	std::cout << "\033[33m" << "METHODS:" << "\033[0m" << std::endl;
	std::cout << "\033[35m" << "\nRoiDT takes 20 points of damage: RoiDT.takeDamage(20)\n" << "\033[0m" << std::endl;
	RoiDT.takeDamage(20);
	std::cout << "\033[35m" << "\nRoiDT repaires 40 points: RoiDT.beRepaired(40)\n" << "\033[0m" << std::endl;
	RoiDT.beRepaired(40);
	std::cout << "\033[35m" << "\nLuisCopyDT takes 101 points of damage: LuisCopyDT.takeDamage(101)\n" << "\033[0m" << std::endl;
	LuisCopyDT.takeDamage(101);
	std::cout << "\033[35m" << "\nLuisCopyDT attacks RoiDT: LuisCopyDT.attack(RoiDT)\n" << "\033[0m" << std::endl;
	LuisCopyDT.attack(RoiDT);
	std::cout << "\033[35m" << "\nIriaDT uses her special function: IriaDT.whoAmI()\n" << "\033[0m" << std::endl;
	RoiDT.whoAmI();

	std::cout << "\033[32m" << "\nEnd of program:\n" << "\033[0m" << std::endl;
	return (0);
}