/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:33:35 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/15 01:17:20 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

/*	The DiamondTrap class will inherit from FragTrap and ScavTrap. Since both
	classes derive from ClapTrap, we need to ensure that the ClapTrap subobject
	is created only once. The way to achieve this is by ensuring that both
	FragTrap and ScavTrap inherit from ClapTrap virtually. This is necessary to
	avoid ambiguity and duplication of members in the derived class.	*/
	
class ScavTrap: virtual public ClapTrap
{
	private:
		bool _guardGate;
		
	public:
		//	Constructors:
		ScavTrap();
		ScavTrap(std::string name);

		//	Copy Constructor:
		ScavTrap(const ScavTrap &other);

		//	Copy assignment operator:
		ScavTrap &operator=(const ScavTrap &other);

		//	Destructor:
		~ScavTrap();
		
		//	Methods:
		void attack(ScavTrap &target);
		void guardGate(void);
};