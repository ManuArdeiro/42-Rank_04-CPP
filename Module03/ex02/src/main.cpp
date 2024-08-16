/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:03:33 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/15 01:19:19 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

static void	function_tests(void)
{
	std::cout << "\033[31m" << "\nFRAGTRAP FUNCTION TEST:" << "\033[0m" << std::endl;
	FragTrap* AllocatedFragTrap = new FragTrap("AllocatedFragTrap");
	delete AllocatedFragTrap;
	std::cout << "\033[32m" << "\nConstructor FragTrap with name RoiFT -> FragTrap RoiFT(\"RoiFT\")\n" << "\033[0m" << std::endl;
	FragTrap RoiFT("RoiFT");
	std::cout << "\033[32m" << "\nEnd of function:\n" << "\033[0m" << std::endl;
	return ;
}

int	main(void)
{
	function_tests();

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "\033[31m" << "FRAGTRAP:" << "\033[0m" << std::endl;
	std::cout << "\033[32m" << "\nDefault Constructor FragTrap IriaFT -> FragTrap IriaFT\n" << "\033[0m" << std::endl;
	FragTrap IriaFT;
	std::cout << "\033[32m" << "\nConstructor FragTrap with name RoiFT -> FragTrap RoiFT(\"RoiFT\")\n" << "\033[0m" << std::endl;
	FragTrap RoiFT("RoiFT");
	std::cout << "\033[32m" << "\nConstructor FragTrap with name IreneFT and parameters -> FragTrap IreneFT(\"IreneFT\", 5, 5, 2)\n" << "\033[0m" << std::endl;
	FragTrap IreneFT("IreneFT", 5, 5, 2);
	std::cout << "\033[32m" << "\nCopy Constructor FragTrap from BeaFT -> FragTrap BeaFT(IreneFT)\n" << "\033[0m" << std::endl;
	FragTrap BeaFT(IreneFT);
	std::cout << "\033[32m" << "\nCopy Assignment Operator FragTrap ConsuFT from BeaFT -> FragTrap ConsuFT = BeaFT\n" << "\033[0m" << std::endl;
	FragTrap ConsuFT = BeaFT;
	std::cout << std::endl;
	std::cout << "\033[33m" << "METHODS:" << "\033[0m" << std::endl;
	std::cout << "\033[32m" << "\nRoiFT attacks a non-existing ClapTrap: RoiFT.attack(\"some other robot\")\n" << "\033[0m" << std::endl;
	RoiFT.attack("some other robot");
	std::cout << "\033[32m" << "\nRoiFT attacks JonST: RoiFT.attack(\"JonST\")\n" << "\033[0m" << std::endl;
	RoiFT.attack("JonST");
	std::cout << "\033[32m" << "\nRoiFT takes 20 points of damage: RoiFT.takeDamage(20)\n" << "\033[0m" << std::endl;
	RoiFT.takeDamage(20);
	std::cout << "\033[32m" << "\nRoiFT repaires 40 points: RoiFT.beRepaired(40)\n" << "\033[0m" << std::endl;
	RoiFT.beRepaired(40);
	std::cout << "\033[32m" << "\nRoiFT high fives: RoiFT.highFivesGuys()\n" << "\033[0m" << std::endl;
	RoiFT.highFivesGuys();
	std::cout << "\033[32m" << "\nBeaFT attacks RoiFT 7 TimCTes: 7 x BeaFT.attack(\"RoiFT\")\n" << "\033[0m" << std::endl;
	for (int i = 0; i < 7; i++)
		BeaFT.attack("RoiFT");
	std::cout << "\033[32m" << "\nConsuFT takes 5 points of damage: ConsuFT.takeDamage(5)\n" << "\033[0m" << std::endl;
	ConsuFT.takeDamage(5);
	std::cout << "\033[32m" << "\nConsuFT attacks RoiFT 7 TimCTes: 7 x ConsuFT.attack(\"RoiFT\")\n" << "\033[0m" << std::endl;
	for (int i = 0; i < 7; i++)
		ConsuFT.attack("RoiFT");

	std::cout << "\033[32m" << "\nEnd of program:\n" << "\033[0m" << std::endl;
	return (0);
}