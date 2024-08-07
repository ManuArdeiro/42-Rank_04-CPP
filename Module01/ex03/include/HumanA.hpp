/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 11:02:49 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/07 19:50:40 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Header-protection
#pragma once

//	includes
#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	public:
		void	attack(void);

		HumanA(std::string name, Weapon &_weapon);
		~HumanA(void);
		
	private:
		std::string	_name;
		Weapon		&_weapon;
};
