/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 10:14:09 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/14 12:53:50 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

/*	This class will have a private attribute _name (which is different from
	ClapTrap::_name).	*/

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string _name;

	public:
		//	Constructors:
		DiamondTrap();
		DiamondTrap(std::string name);
		
		//	Copy Constructor:
		DiamondTrap(const DiamondTrap &other);
		
		//	Copy assignment operator:
		DiamondTrap &operator=(const DiamondTrap &other);
		
		//	Destructor:
		~DiamondTrap();

		void whoAmI();
		void attack(DiamondTrap &target);
};