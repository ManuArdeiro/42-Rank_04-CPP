/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:15:57 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/14 20:24:07 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

/*	The attributes should now be protected instead of private, I leave one
	private and create the necessary functions to see the difference.	*/
class ClapTrap
{
	protected:
		std::string		_name;
		unsigned int	_hit;
		unsigned int	_energy;

	private:
		unsigned int	_attack;

	public:
		//	Constructors
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(std::string name, unsigned int hit, unsigned int energy,
			unsigned int damage);
		
		//	Copy constructor
		ClapTrap(const ClapTrap &other);

		//	Copy assignment operator
		ClapTrap &operator=(const ClapTrap &other);

		//	Destructor
		virtual ~ClapTrap();

		//	Methods
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		//	Access method for ScavTrap

		unsigned int	getAttack() const;
		void			setAttack(unsigned int attack);
};
