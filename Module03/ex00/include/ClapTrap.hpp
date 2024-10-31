/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:15:57 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/16 02:28:45 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class ClapTrap
{
	private:
		std::string		_name;
		unsigned int	_hit;
		unsigned int	_energy;
		unsigned int	_attack;

	public:
		//	Constructors
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(std::string name, unsigned int hit, unsigned int energy,
			unsigned int attack);
		
		//	Copy constructor
		ClapTrap(const ClapTrap &other);

		//	Copy assignment operator
		ClapTrap &operator=(const ClapTrap &other);

		//	Destructor
		~ClapTrap();

		//	Methods
		void attack(ClapTrap &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};
