/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 11:03:19 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/07 19:51:19 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Header-protection
#pragma once

//	includes
#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	public:
		void	attack(void);	
		void	setWeapon(Weapon &_weapon);
	
		HumanB(std::string name);
		~HumanB();
		
	private:
		std::string	_name;
		Weapon		*_weapon;
};
