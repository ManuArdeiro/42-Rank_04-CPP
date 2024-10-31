/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:33:35 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/13 13:38:22 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
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