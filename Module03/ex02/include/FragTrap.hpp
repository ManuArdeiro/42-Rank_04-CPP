/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:03:14 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/15 00:58:54 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	private:
	
	public:
		//	Constructors:
		FragTrap();
		FragTrap(std::string name);

		//	Copy Constructor:
		FragTrap(const FragTrap &other);

		//	Copy assignment operator:
		FragTrap &operator=(const FragTrap &other);

		//	Destructor:
		~FragTrap();
		
		//	Methods:
		void attack(FragTrap &target);
		void highFivesGuys(void);
};