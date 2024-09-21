/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:38:31 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/15 19:30:10 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream> // cin, cout, endl
#include <string> // string class

class Zombie
{
	public:
		void announce(void) const;
		
		Zombie(std::string name);
		~Zombie(void);
		
	private:
		std::string name;
		
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);
